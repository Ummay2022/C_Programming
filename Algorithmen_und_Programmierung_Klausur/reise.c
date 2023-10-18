#include <stdio.h>
#include<stdlib.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "reise.h"
#define START_CITY_ID 0



routen_t erzeugeRouten(size_t anzahlParameter, const char** parameter);
void freigeben(routen_t routen);
size_t findeWeg(routen_t routen, stadt_t** weg, minuten_t maxDauer);
void sortiereStaedte(routen_t routen);


void addCity(city_list_t* list, stadt_t* city);
void removeLastCity(city_list_t* list);
path_t* createPath(size_t max_count);
void destroyPath(path_t* path);
void addCityToPath(path_t* path, size_t city_id, minuten_t time);
void removeLastCityFromPath(path_t* path, minuten_t time);
bool isCityInPath(path_t* path, size_t city_id);
void printPath(path_t* path);
bool tryExtendPath(routen_t* routen, city_list_t* remaining_cities, path_t* path, size_t max_count, minuten_t max_time);



routen_t erzeugeRouten(size_t anzahlParameter, const char** parameter) {
    //allocation
    routen_t routen;
    routen.anzahlStaedte = (size_t) atoi(parameter[1]);
    routen.staedte = (stadt_t*) malloc(routen.anzahlStaedte * sizeof(stadt_t));
    routen.verbindungen = (minuten_t**) malloc(routen.anzahlStaedte * sizeof(minuten_t*));
    for (size_t i = 0; i < routen.anzahlStaedte; i++) {
        routen.verbindungen[i] = (minuten_t*) calloc(routen.anzahlStaedte, sizeof(minuten_t));
    }
    
    // initialize cities
    for (size_t i = 0; i < routen.anzahlStaedte; i++) {
        routen.staedte[i].id = i;
        strncpy(routen.staedte[i].name, parameter[i+1], 30);
    }
    
    // initialize connections
    size_t offset = 1 + routen.anzahlStaedte;
    for (size_t i = 0; i < routen.anzahlStaedte; i++) {
        for (size_t j = i+1; j < routen.anzahlStaedte; j++) {
            minuten_t verbindung = (minuten_t) atoi(parameter[offset++]);
            routen.verbindungen[i][j] = verbindung;
            routen.verbindungen[j][i] = verbindung;
        }
    }
    
    return routen;
}


void freigeben(routen_t routen){
    
    
    for (size_t i = 0; i < routen.anzahlStaedte; i++) {
        free(routen.verbindungen[i]);
    }
    free(routen.verbindungen);

   
    for (size_t i = 0; i < routen.anzahlStaedte; i++) {
        free(routen.staedte[i].name);
    }
    free(routen.staedte);
}

void addCity(city_list_t* list, stadt_t* city) {
    list->count++;
    list->cities = realloc(list->cities, list->count * sizeof(stadt_t*));
    list->cities[list->count - 1] = city;
}

void removeLastCity(city_list_t* list) {
    list->count--;
    list->cities = realloc(list->cities, list->count * sizeof(stadt_t*));
}

path_t* createPath(size_t max_count) {
    path_t* path = malloc(sizeof(path_t));
    path->count = 0;
    path->ids = malloc(max_count * sizeof(size_t));
    path->time = 0;
    return path;
}

void destroyPath(path_t* path) {
    free(path->ids);
    free(path);
}

void addCityToPath(path_t* path, size_t city_id, minuten_t time) {
    path->ids[path->count++] = city_id;
    path->time += time;
}

void removeLastCityFromPath(path_t* path, minuten_t time) {
    path->count--;
    path->time -= time;
}

bool isCityInPath(path_t* path, size_t city_id) {
    for (size_t i = 0; i < path->count; i++) {
        if (path->ids[i] == city_id) {
            return true;
        }
    }
    return false;
}

void printPath(path_t* path) {
    printf("Path (%lu cities, %d min):\n", path->count, path->time);
    for (size_t i = 0; i < path->count; i++) {
        printf("%s\n", path->ids[i] == START_CITY_ID ? "Start" : path->ids[i] == 0 ? "End" : path->ids[i] < 0 ? "ERROR" : path->ids[i]);
    }

}

bool tryExtendPath(routen_t* routen, city_list_t* remaining_cities, path_t* path, size_t max_count, minuten_t max_time) {
    if (path->count == max_count && path->ids[path->count - 1] == START_CITY_ID) {
        // Found a valid circular path
        return true;
    }
    stadt_t* current_city = remaining_cities->cities[0];
    for (size_t i = 0; i < remaining_cities->count; i++) {
        stadt_t* next_city = remaining_cities->cities[i];
        if (current_city == next_city || isCityInPath(path, next_city->id)) {
            // Cannot go to current city or next city is already in the path
            continue;
        }
        minuten_t travel_time = routen->verbindungen[current_city->id][next_city->id];
        if (travel_time == max_time || path->time + travel_time > max_time) {
            // Cannot travel to next city or not enough time left
            continue;
        }
        addCityToPath(path, next_city->id, travel_time);
        removeLastCity(remaining_cities);
        if (tryExtendPath(routen, remaining_cities, path, max_count,max_time)){
            //found path
            return true;
        }
        //path extension unsucessful,backtrack
        removeLastCityFromPath(path,travel_time);
        addCity(remaining_cities,next_city);
    }
    return false;
}
size_t findeWeg(routen_t routen, stadt_t **weg, minuten_t maxDauer){
    size_t num_cities = routen.anzahlStaedte;
    city_list_t remaining_cities = { num_cities - 1, routen.staedte + 1 }; // All cities except start city
    path_t* path = createPath(num_cities);
    addCityToPath(path, START_CITY_ID, 0); // Start at the start city
    if (tryExtendPath(&routen, &remaining_cities, path, num_cities, maxDauer)) {
        // Found a valid circular path, store in weg and return path length
        path->count++; // Include start city at the end of the path
        path->ids[path->count - 1] = START_CITY_ID;
        *weg = path->ids;
        return path->count;
    } else {
        // No valid circular path found
        destroyPath(path);
        *weg = NULL;
        return 0;
    }
}



void sortiereStaedte(routen_t routen){
    
    for (size_t i = 0; i < routen.anzahlStaedte - 1; i++) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < routen.anzahlStaedte; j++) {
            if (strcasecmp(routen.staedte[j].name, routen.staedte[minIndex].name) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            // Swapping the cities in the list
            stadt_t temp = routen.staedte[i];
            routen.staedte[i] = routen.staedte[minIndex];
            routen.staedte[minIndex] = temp;
           
            
        }
    }
}

int main(int argc, char const *argv[])
{
    routen_t routen = erzeugeRouten(argc-1, argv+1);
    stadt_t* weg = NULL;
    size_t wegLaenge = findeWeg(routen, &weg, 270);
    free(weg);
    //sortiereStaedte(routen);
    freigeben(routen);
    return 0;
}
