#include <stdio.h>
#include <time.h> 
#include <stdlib.h>

#define MAX_ITEMS 10000

double a1[MAX_ITEMS][MAX_ITEMS],v1[MAX_ITEMS],v_out1[MAX_ITEMS];
double a2[MAX_ITEMS][MAX_ITEMS],v2[MAX_ITEMS],v_out2[MAX_ITEMS];

void init_matrix1() {
  int i, j;
  for (i = 0; i < MAX_ITEMS; i++){
    for (j = 0; j < MAX_ITEMS; j++) {
      a1[i][j] = rand() % 10;
    }   
  }
}


void init_matrix2() {
  int i, j;
  for (i = 0; i < MAX_ITEMS; i++){
    for (j = 0; j < MAX_ITEMS; j++) {
      a2[i][j] = rand() % 10;
    }   
  }
}

void init_array1() {
  int i, j;
  for (i = 0; i < MAX_ITEMS; i++){
   
      v1[i] = rand() % 2;
    
  }
}

void init_array2() {
  int i, j;
  for (i = 0; i < MAX_ITEMS; i++){
    
      v2[i] = rand() % 2;
    
  }
}

int mv1()
{           
  int i,j;
  for (i = 0; i < MAX_ITEMS; i++)
  {         
    float sum = 0.0;
    for (j = 0; j < MAX_ITEMS; j++)
    { 
      sum += a1[i][j]*v1[j];
    }  
    v_out1[i] = sum;
  }         
  return 0; 
}

int mv2()
{           
  int i,j;
  for (i = 0; i < MAX_ITEMS; i++)
  {         
    float sum = 0.0;
    for (j = 0; j < MAX_ITEMS; j++)
    { 
      sum += a1[i][j]*v1[j];
    }  
    v_out2[i] = sum;
  }         
  return 0; 
}


int main()
{
  struct timespec start, finish;
  double elapsed;
  clock_gettime(CLOCK_MONOTONIC, &start);
  init_array1();
  init_matrix1();
  init_array2();
  init_matrix2();

  mv1();
  mv2();


  clock_gettime(CLOCK_MONOTONIC, &finish);
  elapsed = (finish.tv_sec - start.tv_sec);
  printf("Execution time is %f \n", elapsed);
  return 0;
}