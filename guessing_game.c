#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	int a, b, cs_sum, players_guess;
	int quit =0;
	int correct_count =0;
	int incorrect_count = 0;
	int  score =0;
	
	srand(time(NULL));
	while(!quit){
		printf("COMPUTER ROLLED TWO DICES..GUESS THE SUM\n");

		printf("Enter your guess: \n");
		scanf("%d", &players_guess);
		a = (rand()% 6)+1;
		b = (rand()% 6)+1;
		cs_sum = a+ b;

		if(players_guess <= 0){
			quit = 1 ;
		}

		else if (players_guess == cs_sum){
			correct_count += 1;
			score += 10;
			printf("Bravo! you were correct!\n");


		}
		else {
			incorrect_count++;
			score -= 5;
			printf("Darn! BAd attempt\n");

		}
		printf("Total correct : %d\n",correct_count );
		printf("Total incorrect : %d\n", incorrect_count );
		printf("Total score : %d\n",score );


	}
	printf("Thank You for playing");
	
}