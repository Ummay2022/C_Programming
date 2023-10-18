#include <stdio.h>

int main(){
	int r,c;

	printf("Enter number of rows: ");
	scanf("%d", &r);
	printf("Enter number of coloumns: ");
	scanf("%d", &c);

	int a[r][c];
	if(r < 3 ||  r > 10) printf("Row number has to be >= 3 and <=10!\n");
	if(c < 3 ||  c > 10) printf("Coloumn number has to be >= 3 and <=10!\n");

	int i,j;
	
	for (i = 0; i< r; i++){  //taking input values for each index of the matrix
		for(j = 0; j <c; j++){
			printf("Matrix[%d][%d]: ", i,j); 
			scanf("%d", &a[i][j]);
			
		}
	}
	for(i = 0; i < r; i++){  //returning the matrix
	   	for(j = 0; j < c; j++){
	   		printf("%6d",a[i][j]);
	   	}
	   	printf("\n");
	}
	printf("\n\n");

	//transpose i = c, j = r
	printf("Transpose  of  the matrix: \n");
	for(j=0; j< c; j++){
		for(i=0; i<r ; i++){
			printf("%6d", a[i][j]);
		}
		printf("\n");

	}
	return 0;




}
