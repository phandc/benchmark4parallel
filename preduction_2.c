#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define num_steps1 2000000000 
#define num_steps2 1000000
#define num_steps3 100

double calculate_pi1(){
   double pi = 0.0;
  long int i;
  double x, interval_width;
  interval_width = 1.0/(double)num_steps1;

  for (i = 0; i < num_steps1; i++) {
    x = (i+ 0.5) * interval_width;
    pi += 1.0 / (x*x + 1.0);
  }

  pi = pi * 4.0 * interval_width;
  return pi;
} 

double calculate_pi2(){
   double pi = 0.0;
  long int i;
  double x, interval_width;
  interval_width = 1.0/(double)num_steps2;

  for (i = 0; i < num_steps2; i++) {
    x = (i+ 0.5) * interval_width;
    pi += 1.0 / (x*x + 1.0);
  }

  pi = pi * 4.0 * interval_width;
  return pi;
} 

double calculate_pi3(){
   double pi = 0.0;
  long int i;
  double x, interval_width;
  interval_width = 1.0/(double)num_steps3;

  for (i = 0; i < num_steps3; i++) {
    x = (i+ 0.5) * interval_width;
    pi += 1.0 / (x*x + 1.0);
  }

  pi = pi * 4.0 * interval_width;
  return pi;
} 

int main(int argc, char** argv)
{
  struct timespec start, finish;
  double elapsed;
  clock_gettime(CLOCK_MONOTONIC, &start);
 
  double pi1 = calculate_pi1();
  double pi2 = calculate_pi2();
  double pi3 = calculate_pi3();

  printf("pi1 = %f\n", pi1);
  printf("pi2 = %f\n", pi2);
  printf("pi3 = %f\n", pi3);
  clock_gettime(CLOCK_MONOTONIC, &finish);
  elapsed = (finish.tv_sec - start.tv_sec);
  printf("Execution time is %f \n", elapsed);
  return 0;
}