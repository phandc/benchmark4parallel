#include <stdlib.h>  
#include <stdio.h>
#include <time.h>  

#define MAX_ITEMS 100000000
int arr1[ MAX_ITEMS];
int arr2[ MAX_ITEMS];
void init1(){
 int i = 0;
  for (i=0; i< MAX_ITEMS ; i++)
  {
   int  x = rand();
    if (i%2==0)
      arr1[i]=x;
    else
     arr1[i]= -x;
  }

}

void init2(){
int i = 0;
  for (i=0; i< MAX_ITEMS ; i++)
  {
   int x = rand();
    if (i%2==0)
      arr2[i]=x;
    else
     arr2[i]= -x;
  }

}
int count_positive(int array[MAX_ITEMS]){
	int count = 0;
	int i =  0;
	for(i = 0; i < MAX_ITEMS; i++){
		if(array[i] > 0){
			count += 1;
		}
	}
	return count;
}

int count_negative(int array[MAX_ITEMS]){
	int count = 0;
	int i =  0;
	for(i = 0; i < MAX_ITEMS; i++){
		if(array[i] < 0){
			count += 1;
		}
	}
	return count;
}

int main(int argc, char* argv[])  
{
 struct timespec start, finish;
  double elapsed;
  clock_gettime(CLOCK_MONOTONIC, &start);
  init1();
  init2();
  int positive1 = count_positive(arr1);
  int positive2 = count_positive(arr2);
int negative1 = count_negative(arr1);
int negative2 = count_negative(arr2);	

printf("arr1 positives =  %d, negatives = %d\n", positive1, negative1);
printf("arr2 positives =  %d, negatives = %d\n", positive2, negative2);
 clock_gettime(CLOCK_MONOTONIC, &finish);
  elapsed = (finish.tv_sec - start.tv_sec);
  printf("Execution time is %f \n", elapsed);
  return 0;
} 
