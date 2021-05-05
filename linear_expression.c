#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
#define MAX_ITEMS 100000000

int array1[MAX_ITEMS];
int array2[MAX_ITEMS];

void init1(){
	int i = 0;
	for (i=0; i<MAX_ITEMS; i++)
    	array1[i]= rand(); 
}
void init2(){
	int i = 0;
	for (i=0; i<MAX_ITEMS; i++)
    	array2[i]= rand(); 
}
void modify1(){
	int i = 0;
	 for (i=0;i<MAX_ITEMS/2 - 1;i++)
    	array1[2*i+1]= (array1[i] + 1) / 2;
}

void modify2(){
	int i = 0;
	 for (i=0;i<MAX_ITEMS/3 - 1;i++)
    	array2[3*i+1]= (array2[i] + 2) / 3;
}

int main(int argc, char* argv[])
{
struct timespec start, finish;
  double elapsed;
  clock_gettime(CLOCK_MONOTONIC, &start);
  init1();
  init2();
 	
  modify1();
  modify2();

  clock_gettime(CLOCK_MONOTONIC, &finish);
  elapsed = (finish.tv_sec - start.tv_sec);
  printf("Execution time is %f \n", elapsed);
  return 0;
}