#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#define SIZE 1000
static double a[SIZE][SIZE];
static double b[SIZE][SIZE];
static double c[SIZE][SIZE];
static double d[SIZE][SIZE];
static double e[SIZE][SIZE];
static double f[SIZE][SIZE];
void init_matrix(void) {
	int i, j;
	for (i = 0; i < SIZE; i++){
		for (j = 0; j < SIZE; j++) {
			a[i][j] = rand() % 10;
			b[i][j] = rand() % 10;
		} 	
	}
}
void matmul_seq_a_b() { 
	int i, j, k;
	for (i = 0; i < SIZE; i++){
		for (j = 0;  j < SIZE; j++) { 
			c[i][j] = 0.0;
			for(k = 0; k < SIZE; k++){
				c[i][j] = c[i][j] + a[i][k] * b[k][j];
			}
		}
	}
}
void matmul_seq_d_e() { 
	int i, j, k;
	for (i = 0; i < SIZE; i++){
		for (j = 0;  j < SIZE; j++) { 
			f[i][j] = 0.0;
			for(k = 0; k < SIZE; k++){
				f[i][j] = f[i][j] + d[i][k] * e[k][j];
			}
		}
	}
}

int main(int argc, char **argv) {
	struct timespec start, finish;
    double elapsed;
    clock_gettime(CLOCK_MONOTONIC, &start);
	
	matmul_seq_a_b();
	matmul_seq_d_e();
	clock_gettime(CLOCK_MONOTONIC, &finish);

  	elapsed = (finish.tv_sec - start.tv_sec);
  	printf("Execution time is %f \n", elapsed);
	return 0;
}
