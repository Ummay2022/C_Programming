#include <stdio.h>
#include <math.h>
 
int main(){
	int a[10]={0};
	int i;
	int n;

	
	printf("You can enter maximum 10 digits\n");
	printf("Enter total number of digits:");
	scanf("%d",&n);
	if(n>10 || n <=0){
		printf("Enter valid number!\n");
		return 0;

	}
	for (i = 10-n; i < 10;i++){
		printf("Input next digit: ");
		scanf ("%d", &a[i]);

	}
	printf("The number that you gave is: \n");
    for(i = 10-n; i < 10; ++i){
        printf("%d\n", a[i]);
    }
	int d; 
	printf("Enter a digit from 1-9 to add: ");
	scanf("%d", &d);
	if(d <= 0 || d>=10){
		printf("invalid try again");
		return  0;
	}
	int carry =0, unitPlace, sum;
	int newCount =0;
	for(i = 10-1 ; i >= 0 ; --i){
		if (i == 10 -1){
			sum = a[i] + d;
		}
		else sum = a[i] + carry;
		unitPlace = sum % 10;
		carry = sum /10;
		a[i] = unitPlace;

		if (carry == 0)
			break;


	}
	if (i < 0)
		newCount = 10;
	else if (i < 10 -n &&   a[i] != 0){
		newCount = n+1;
	}
	else newCount = n;

	printf("Result: \n");
	for (i = 10 -newCount;i<10; ++i){
		printf("%d", a[i]);

	}
	return 0;


}