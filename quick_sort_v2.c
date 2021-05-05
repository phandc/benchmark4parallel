#include <stdio.h> 
#include <stdlib.h>
#include <time.h> 
#define MAX_ITEMS 100000000
#define swap(v, a, b) {unsigned tmp; tmp=v[a]; v[a]=v[b]; v[b]=tmp;} 
static int counter = 0;
static int *array;
static int *array2;
static void print(int* A) {
    int i;
	for (i = 0; i < MAX_ITEMS; i++) { 
		printf("%d\n", A[i]);
	}
	printf("\n"); 
}
static void init() {
    int i;
	array = (int *) malloc(MAX_ITEMS*sizeof(int)); 
	array2 = (int *) malloc(MAX_ITEMS*sizeof(int)); 
	for (i = 0; i < MAX_ITEMS; i++) {
		array[i] = rand(); 
		array2[i] = rand();
	}
}
static unsigned partition(int *array, unsigned low, unsigned high, unsigned pivot_index) {
	if (pivot_index != low) 
		swap(array, low, pivot_index);

	pivot_index = low; 
	low++;

	while (low <= high) {
		if (array[low] <= array[pivot_index])
			low++;
		else if (array[high] > array[pivot_index])
			high--; 
		else
            swap(array, low, high);
	}
	if (high != pivot_index)
		swap(array, pivot_index, high);
    return high;
}

static void quick_sort(int *array, unsigned low, unsigned high) {
	unsigned pivot;
	if (low >= high) 
		return;
	pivot = (low+high)/2;
	pivot = partition(array, low, high, pivot);

    if (low < pivot) { 
    	quick_sort(array, low, pivot-1);
	}
    if (pivot < high) { 
    	quick_sort(array, pivot+1, high);
	}
}
int main(int argc, char **argv) { 
	struct timespec start, finish;
    double elapsed;
    clock_gettime(CLOCK_MONOTONIC, &start);
  
	init();

	quick_sort(array, 0, MAX_ITEMS-1);
    free(array);
    quick_sort(array2, 0, MAX_ITEMS-1);
    free(array2);
    clock_gettime(CLOCK_MONOTONIC, &finish);

  	elapsed = (finish.tv_sec - start.tv_sec);
  	printf("Execution time is %f \n", elapsed);
  	return 0;
    
}