#include <stdio.h>
#include <math.h>

int main(){
	int n;
	printf("Enter dimension of the matrix only odd numbers(1-15): ");
	scanf("%d", &n);

	if (n < 1 || n >15 || n % 2 ==0){
	
		printf("Please give an odd number in the range from 1 to 15");
		return 0;
	}

	int a[n][n];
	int i, j;

	for (i = 0; i < n ; i++){
		for(j = 0; j < n; j++){
			a[i][j] = 0;
		}

	}
	i = n - 1;
	j = n/2;

	int k;
	for(k = 1; k <= n * n; ++k){
		a[i][j] = k;
		int oldRow = i;
		int oldCol = j;

		i = (i + 1) % n;
		j = (j + 1) % n;

		if(a[i][j] != 0){
			i = oldRow;
			j = oldCol;
			i--;

		}
	}
	int magicConstant = n * (n * n +1) / 2 ;

	printf("Magic Square: \n\n");
	int correct = 1;
	for(i = 0; i < n; i++){
		int rowSum = 0;
		for(j = 0 ; j< n; j++){
			printf("%4d",a[i][j]);
			rowSum = rowSum + a[i][j];


		}
		printf("\n");
		if(rowSum != magicConstant){
			correct = 0;

		}
	}

	for (j = 0; j <n; j++){
		int colSum = 0;
		for(i = 0; i <n ; i++){
			colSum = colSum + a[i][j];
		}
		if(colSum != magicConstant){
			correct = 0;
		}
	}

	int firstDiagonalSum = 0;
	for(i = 0, j = 0; i<n ; i++, j++ ){
		firstDiagonalSum = firstDiagonalSum + a[i][j];

	}
	if (firstDiagonalSum != magicConstant){
		correct=0;

	}
	int secodDiagonalSum = 0;
	for( i = 0,j= n-1; i <n; i++,j-- ){
		secodDiagonalSum = secodDiagonalSum + a[i][j];

	}
	if (secodDiagonalSum != magicConstant){
		correct = 0;

	}
	if(correct){
		printf("Magic square generated with %d dimension and  magic constant: %d\n", n,magicConstant);

	}
	else printf("Error forming magic square!\n");

	return 0;
}


