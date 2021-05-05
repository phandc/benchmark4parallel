#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>

int g1 = 1;
int g2 = 2;
int f1(){
   	printf("f1\n");
    int a = g1;
    int i = 0, j = 0; 
    for(i = 0; i < 10000; i++){
   	  for(j = 0; j < 10000; j++){}
    }
    return a;
}

void f2(){
  
   printf("f2\n");
   g1 = f1();
   int i = 0, j = 0; 
   for(i = 0; i < 10000; i++){
      for(j = 0; j < 10000; j++){}
   }
   return;
}

void f3(){
	printf("f3\n");
	f2();
    int k = g1 - 1;
    g1 = k;
    int i = 0, j = 0; 
    for(i = 0; i < 10000; i++){
   	   for(j = 0; j < 10000; j++){}
    }
}

void f5(){
	printf("f5\n");
    g2 = 10;
    int i = 0, j = 0; 
    for(i = 0; i < 10000; i++){
   	   for(j = 0; j < 10000; j++){}
    }
    return;
}

void f4(){
   	printf("f4\n");
    g2 = 3;
    int k = g2;
    f5();
    int i = 0, j = 0; 
    for(i = 0; i < 10000; i++){
   	   for(j = 0; j < 10000; j++){}
    }
}

void f6(){
    printf("f6\n");
    g1 = 0;
    g2 = 0;
    int i = 0, j = 0; 
    for(i = 0; i < 10000; i++){
   	  for(j = 0; j < 10000; j++){}
    }
}

int f7(){
    printf("f7\n");
    int a = g1;
    int b = g2;
    int i = 0, j = 0; 
    for(i = 0; i < 10000; i++){
   	  for(j = 0; j < 10000; j++){}
   }
    return a + b;
}


int main(){
	struct timespec start, finish;
  double elapsed;
  clock_gettime(CLOCK_MONOTONIC, &start);

    
  g1 = 10; 
  g2 = 100;
  f1();
  if(g1 <= 10){
    	
    	f6();
    	f5();
    	f4();
    	f5();
    	f1();
    	f2();
    	f3();
    	f4();
	}else{
		f4();
		f7();
		f3();
	
	}
	
	
	clock_gettime(CLOCK_MONOTONIC, &finish);

  elapsed = (finish.tv_sec - start.tv_sec);
  printf("Execution time is %f \n", elapsed);
   
  return 0;
}
