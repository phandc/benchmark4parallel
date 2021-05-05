#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//f1 and f2 donot exist any dependencies

void f1(){
	printf("f1\n");
	int i, j;
	for(i = 0; i < 100000; i++){
   	  	for(j = 0; j < 100000; j++){}
    }
}

void f2(){
	printf("f2\n");
	int i, j;
	for(i = 0; i < 100000; i++){
   		for(j = 0; j < 100000; j++){}
    }
}

int main(){
	struct timespec start, finish;
    double elapsed;
    clock_gettime(CLOCK_MONOTONIC, &start);
	f1();
	f2();
	 
	clock_gettime(CLOCK_MONOTONIC, &finish);

  	elapsed = (finish.tv_sec - start.tv_sec);
  	printf("Execution time is %f \n", elapsed);
	return 0;
}
