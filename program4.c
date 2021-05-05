#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int g1 = 0;
int g2 = 0;
int g3 = 0;
void f1(){
	printf("f1\n");
	int a = g1 + 100;
	g2 = a;
	int i = 0, j = 0; 
    for(i = 0; i < 10000; i++){
   	    for(j = 0; j < 10000; j++){}
    }
}

void f2(){
	printf("f2\n");
	int b = g2 - 10;
	g3 = b;
	int i = 0, j = 0; 
    for(i = 0; i < 10000; i++){
   	    for(j = 0; j < 10000; j++){}
    }
}

void f3(){
	printf("f3\n");
	int c = g3 * 2;
	int i = 0, j = 0; 
    for(i = 0; i < 10000; i++){
   	  for(j = 0; j < 10000; j++){}
    }
}

int main(){
  struct timespec start, finish;
  double elapsed;
  clock_gettime(CLOCK_MONOTONIC, &start);
    
  f1();
  f3();
  f2();
	
  clock_gettime(CLOCK_MONOTONIC, &finish);

  elapsed = (finish.tv_sec - start.tv_sec);
  printf("Execution time is %f \n", elapsed);
  return 0;
}
