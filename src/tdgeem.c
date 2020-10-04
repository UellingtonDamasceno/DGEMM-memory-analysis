#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

double **createMatrix(int size);
double **readMatrix(char *, int);
void freeMatrix(double **, int); 
void dgemm(size_t, double *, double *, double *);
void saveResult(char *, int, double);

int main(int argc, char* argv[]){
	clock_t timer_i, timer_f;
    double result;    
    
//    printf("Nome do arquivo: %s\n", argv[1]);
//    printf("Nome arquivo saida: %s\n", argv[3]);
//    printf("Tamanho matriz: %s\n", argv[2]);
//        
    int matrixSize = atoi(argv[2]);
    
	double **matrixA = readMatrix(argv[1], matrixSize);
    double **matrixB = readMatrix(argv[1], matrixSize);
    double **matrixC = createMatrix(matrixSize);
    
    timer_i = clock();
    dgemm(matrixSize, *matrixA, *matrixB, *matrixC);    
    timer_f = clock() - timer_i;
    result = ((double)timer_f)/((CLOCKS_PER_SEC/1000));

    saveResult(argv[3], matrixSize, result);
//    freeMatrix(matrixA, matrixSize);
//    freeMatrix(matrixB, matrixSize);
//    freeMatrix(matrixC, matrixSize);

    return 0;
}

void saveResult(char* fileName, int matrixSize, double result){
    FILE *file = fopen(fileName, "a");
    
    if(file == NULL){
		printf("Erro na leitura do arquivo.\n");
        printf("Arquivo: %s\n", fileName);
		exit(1);
	}else{
        fprintf(file, "%d,%.2lf,0\n", matrixSize, result);
        fclose(file); 
    }
}

double **readMatrix(char* fileName, int size){
	FILE *file = fopen(fileName, "r");

	if(file == NULL){
		printf("Erro na leitura do arquivo.\n");
        printf("Arquivo: %s\n", fileName);
		exit(1);
	}
    int i, j;
	double **matrix = createMatrix(size);
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			fscanf(file, "%lf ", &matrix[i][j]);
		}
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
			for (size_t k = 0; k < n; k++) {
				cij += A[i+k*n] * B[k+j*n]; /*cij += A[i][k]*B[k][j]*/
			}
			C[i+j*n] = cij; /* C[i][j] = cij*/
		}
	}
}
