#include<stdlib.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

enum {MAX_LEN = 100};

typedef int minuten_t;

typedef struct {
    size_t id;
    char name[30];
} stadt_t;

typedef struct {
    size_t anzahlStaedte;
    stadt_t* staedte;
    minuten_t** verbindungen;
} routen_t;

//required for backtracking algorithm
typedef struct {
    size_t count;
    stadt_t** cities;
} city_list_t;

typedef struct {
    size_t count;
    size_t* ids;
    minuten_t time;
} path_t;
