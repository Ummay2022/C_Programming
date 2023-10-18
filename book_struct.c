#include <stdio.h>
#include <string.h>

typedef struct {
    char title[20];    // title of book.
    char author[20];   // author of book
    double price;      // price of book.
}Book;


double getCourierCharge(Book *b_ptr, unsigned distance){

	double courier_charge = 5.00;
    
    if (distance > 0 && distance <= 100){
       return courier_charge;
        
    }
    else if(distance > 100 && distance <= 250){
        courier_charge = courier_charge + 0.10 * (b_ptr -> price);
        
    }
    else if (distance > 250 && distance <= 500){
        courier_charge = courier_charge + 0.15 * (b_ptr -> price);
        
    }
    else {
        courier_charge = courier_charge + 0.20 * (b_ptr -> price);
        
    }
    
    
    if (strcmp(b_ptr -> author,"Tagore") == 0 ){
        courier_charge = courier_charge - 0.05 * courier_charge;
        
    }
    return courier_charge;
    
    

}
// int main(){

//     Book book;

//      char title[] = "My book";

//      char author[] = "Tagore";

//      double price = 199.80;

//     double cCharge;

//     int distance = 160;



//     strcpy(book.title, title);

//     strcpy(book.author, author);

//     book.price = price;



//     cCharge = getCourierCharge(&book, distance);

//     printf("Charge: %0.2lf", cCharge);



//     return 0;

// }

int main(){
	Book book;

	unsigned distance = 165;

	strcpy(book.author, "Tagore");

	book.price = 20.5;
	double charge = getCourierCharge(&book,distance);
	printf("Charge: %0.2lf", charge);
	return 0;
}

