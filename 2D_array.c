#include <stdio.h>

#define SIZE 8

void print_array(int [], int);
void eight_colony(int [], int);


//printing array in a specific pattern:
void print_array(int arr[], int size){
	int i;
	printf("\n[");
	for(i = 0; i < size; i++){
		if(i != size -1){
			printf("%4d |",arr[i] );
		}
		else printf("%4d]\n", arr[i]);

	}
	printf("\n");
}

//the function to change the modes of each room for each passing days:
void eight_colony(int arr[], int days){
	int d = 1;
	int left, right, i;
	int temp[SIZE];

	while(d <= days){
		for(i = 0; i < SIZE; i++){
			//using ternary operations
			left = (i == 0) ? 0 : arr[i-1];
			right = (i == SIZE -1) ? 0 : arr[i+1];
			temp[i] = (left == right) ? 0 : 1;

			// if(i == 0){
			// 	left = 0;
			// }
			// else left = arr[i];

			// if(i == SIZE-1)
			// 	right = 0;
			// else right = arr[i+1];

			// if(left == right){
			// 	temp[i]=0;

			// }
			// else temp[i]=1;
			
		}
		for(i = 0; i <SIZE; i++){
				arr[i]=temp[i];
			}
			printf("Situation after day : %d", d);
			print_array(arr,SIZE);
			d++;
	}
}

int main(){
	int arr[] = {1,0,0,1,1,1,0,1};
	eight_colony(arr,6);
	return 0;
}