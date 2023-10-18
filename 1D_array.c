#include <stdio.h>
#include <math.h>


int main(){
	float x[20];
	float y[20];
	int i=0 ;
	float temp;

	printf("Enter maximum 20 valuew, terminate with 0.0\n");
	printf("Enter 1st number: ");
	scanf("%f",&temp);

	while(i <20 && temp !=0){
		x[i++]= temp;
			printf("next: ");
			scanf("%f", &temp);
	}
	
	
	printf("there are total %d number of elements\n", i);
	int index;
	for (index =0; index<i; index++){
		if (index % 2 == 0){
			y[index] = 2 * x[index];
		}
		else y[index] = cbrt(x[index]);
		
	}

	printf("%12s %12s\n", "Input Array", "2nd Array");
	float firstSum = 0.0, SecondSum = 0.0;

	for (index = 0; index < i; index++){
		printf("%12.5f %12.5f\n", x[index], y[index] );
		firstSum += x[index];
		SecondSum += y[index];
	}

	printf("\n\n");
	printf("Summ of 1st array: %12.5f\n", firstSum);
	printf("Summ of 2nd array: %12.5f\n", SecondSum);
	return 0;

}