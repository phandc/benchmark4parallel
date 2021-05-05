#include <stdio.h>
#include <time.h> 
#define MAX_ITEMS 10000

float u1[MAX_ITEMS][MAX_ITEMS];
float u2[MAX_ITEMS][MAX_ITEMS];
void init1(){
  int i,j;
  for (i = 0; i < MAX_ITEMS; i++)
    for (j = 0; j < MAX_ITEMS; j++)
        u1[i][j] = 0.5; 

}
void init2(){
  int i,j;
  for (i = 0; i < MAX_ITEMS; i++)
    for (j = 0; j < MAX_ITEMS; j++)
        u2[i][j] = 0.7; 

}
float reduction(float u[MAX_ITEMS][MAX_ITEMS]){
  float temp, sum=0.0;
  int i, j;
  
  for (i = 0; i < MAX_ITEMS; i++)
    for (j = 0; j < MAX_ITEMS; j++)
    {
      temp = u[i][j];
      sum = sum + temp * temp;
    }

  return sum;
}


int main(int argc, char* argv[])
{
  struct timespec start, finish;
  double elapsed;
  clock_gettime(CLOCK_MONOTONIC, &start);

  init1();
  init2();
  
  float sum1 = reduction(u1);
  float sum2 = reduction(u2);

  printf ("sum1 = %f\n", sum1);  
  printf ("sum2 = %f\n", sum2);  
  clock_gettime(CLOCK_MONOTONIC, &finish);
  elapsed = (finish.tv_sec - start.tv_sec);
  printf("Execution time is %f \n", elapsed);
  return 0;
}