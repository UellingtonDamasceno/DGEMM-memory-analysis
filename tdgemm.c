#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

double **createMatrix(int size);
double **readMatrix(char*, int);
void freeMatrix(double **, int);
void dgemm(size_t, double*, double*, double*);

int main(int argc, char* argv[]){
	clock_t timer;
	double **matrix = readMatrix(argv[1], atoi(argv[2]));
	return 0;
}

double **readMatrix(char* fileName, int size){
	int i, j;
	FILE *file = fopen(fileName, "r");
	
	if(file == NULL){
		printf("Erro na leitura do arquivo.\n");
		exit(1);
	}

	double** matrix = createMatrix(size);
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			fscanf(file, "%lf ", &matrix[i][j]);
			printf("%lf ", matrix[i][j]);
		}
		printf("\n");
	}
	fclose(file);
	return matrix;
}

double **createMatrix(int size){
    double **matrix;

    matrix = (double **) malloc(sizeof(double*) * size);
   
    if(matrix == NULL){
        printf("Não há memória\n");
        exit(1);
    }else{
        int i;
        for(i = 0; i < size; i++){
            matrix[i] = (double *) malloc(sizeof(double) * size);
            if(matrix[i] == NULL){
                printf("Memoria insuficiente.\n");
                exit(1);            
            }
        }
    }
    return matrix;
}

void freeMatrix(double **matrix, int matrixSize){
    int i;
    for(i = 0; i < matrixSize; i++){
        free(matrix[i]);
    }
    free(matrix);
}

void dgemm (size_t n, double* A, double* B, double* C) {
	for (size_t i = 0; i < n; ++i) {
		for(size_t j = 0; j < n; ++j) {
			double cij = 0;
			for (size_t k=0; k < n; k++) {
				cij += A[i+k*n] * B[k+j*n]; /*cij += A[i][k]*B[k][j]*/
			}
			C[i+j*n] = cij; /* C[i][j] = cij*/
		}
	}
}
