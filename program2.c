#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int g1 = 0;
int g2 = 0;
int f1(int x){
	printf("f1\n");
	int a = g1;
	int i, j;
	for(i = 0; i < 100000; i++){
   	  	for(j = 0; j < 100000; j++){}
    }
	return a - x;	
}

void f2(){
	printf("f2\n");
	g2 = 4;
	int x = f1(g2);
	int i, j;
	for(i = 0; i < 100000; i++){
   	  	for(j = 0; j < 100000; j++){}
    }
	if(x > 0){
		printf("1\n");
	}else{
		printf("0\n");
	}
	return;
}

void f3(){
	printf("f3\n");
	int a = g1;
	int b = 10;
	int i, j;
	for(i = 0; i < 100000; i++){
   	  	for(j = 0; j < 100000; j++){}
    }
	printf("%d\n", a + b);
	return;
}

int main(){
	struct timespec start, finish;
    double elapsed;
    clock_gettime(CLOCK_MONOTONIC, &start);
    
	f2();
	f3();
	
	clock_gettime(CLOCK_MONOTONIC, &finish);

  	elapsed = (finish.tv_sec - start.tv_sec);
  	printf("Execution time is %f \n", elapsed);
	return 0;
}
