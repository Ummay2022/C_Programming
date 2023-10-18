#include <stdio.h>
#include <stdlib.h>

// Write your code below. You will need to write only one function, convert, please read the problem statement above to write the function.  The prototype of the function must match with the tester. 
// You are free to write additional functions for your purpose but, may not be necessary.
int convert(char str[], int flag){
    int i = 0;
    
    int count =0;
    
    char temp[100];
    while(str[i] != '\0'){
        for (i=0; str[i] != '\0'; i++){
            if(flag == 0){
                
                if(str[i] >= 'a' && str[i] <= 'z'){
                    temp[i] = str[i] - 32;
                    count += 1;
                    
                }
                else temp[i] = str[i];
            }
            else if(flag ==1){
                if(str[i] >= 'A' && str[i] <= 'Z'){
                    temp[i] = str[i] + 32;
                    count += 1;
                }
                else temp[i] = str[i];
            }
            else {
                temp[i] = str[i];
                count =0;
            }
            
        }
        printf("Converted %s to %s \n",str,temp);


    }
        // printf("the string is : %c", str[i]);
        // printf("the string is : %c", temp[i]);
    

    return count;
}

int main(){
    char str[] = "hellO WOrld 123";
    printf("number of characters converted  : %d \n",convert(str,1));
}
