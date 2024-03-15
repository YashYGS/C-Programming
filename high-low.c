#include <stdio.h>

// Write your implementation here...


int main(int argc, char **argv) {
char a;
printf("Welcome to the High Low game...\n");
 
       char r;\
       char cont;
       int contNum = 1;
        

      while (contNum == 1) {
      
      int low = 1;
      int high = 100;
      int mid = 50;

      printf("Think of a number between 1 and 100 and press <enter>\n");

      //scanf(" %c",&a);
      getchar();
      //scanf("^\n");
      while (high>=low){
        printf("Is it higher than %d? (y/n)\n", mid);
        scanf(" %c",&r);
	//scanf("^\n");
          if (r=='y') {
                  low = mid+1;
	          }
          else if(r=='n') {
                  high = mid-1;
          } else {
	  printf("Type y or n\n");

	}

	 mid = (high+low)/2;

      }

	printf("\n>>>>>> The number is %d\n", mid+1);
 
	printf("\nDo you want to continue playing (y/n)?");
	scanf(" %c",&cont);
	//getchar();
	scanf("^\n");
	if (cont=='y') {
	continue;
	} else if (cont=='n') {
	break;
	} else {
	printf("Type y or n\n");
	}
     }
}
