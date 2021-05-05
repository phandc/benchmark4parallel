#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#define MAX_ITEMS 100000000

static int* arr1;
static int* arr2;
static void init1() {
    int i = 0;
  int* arr1 = (int *) malloc(MAX_ITEMS*sizeof(int)); 
  for (i = 0; i < MAX_ITEMS; i++) {
    arr1[i] = rand();
  }
}

static void init2() {
    int i = 0;
  int* arr2 = (int *) malloc(MAX_ITEMS*sizeof(int)); 
  for (i = 0; i < MAX_ITEMS; i++) {
    arr2[i] = rand();
  }

}

void increase(int* a){
  int i = 0;
   for (i=0;i< MAX_ITEMS -1 ;i++)
    a[i + 1]=a[i]+1;
}

void print_array(int* arr){
  int i = 0;
  for(int i = 0; i < MAX_ITEMS - 1; i++){
    printf("%d \n", arr[i]);
  }
}
void destroy_array(int* a){
  free(a);
}
int main(int argc, char* argv[])
{   
  struct timespec start, finish;
  double elapsed;
  clock_gettime(CLOCK_MONOTONIC, &start);

  int i;
 

  init1();
  init2();

  increase(arr1);
  increase(arr2);

  destroy_array(arr1);
  destroy_array(arr2);


  //printf ("arr1[500]=%d\n", arr1[500] );

  clock_gettime(CLOCK_MONOTONIC, &finish);
  elapsed = (finish.tv_sec - start.tv_sec);
  printf("Execution time is %f \n", elapsed);
  return 0;
} 