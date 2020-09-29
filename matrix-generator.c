#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REF_ARG_NUMBER 4

double **createMatrix(int);
void saveMatrix(char*, double **, int);
void freeMatrix(double **, int);

int main(int argc, char *argv[]){
    int i, j, matrixSize, minValue, maxValue;
    char fileName[10];
    double **matrix;
   
    if(argc == REF_ARG_NUMBER) {
        matrixSize = atoi(argv[1]);            
        minValue = atoi(argv[2]);
        maxValue = (atoi(argv[3]) - minValue);

        matrix = createMatrix(matrixSize);
        
        strcpy(fileName, argv[1]);        
        strcat(fileName, ".txt");     
        
        for(i = 0; i < matrixSize; i++){
            for(j = 0; j < matrixSize; j++){
              matrix[i][j] = ((rand() % maxValue)+minValue);    
            }
        }
        saveMatrix(fileName, matrix, matrixSize);
    }else{
        printf("Verifique o número de argumentos");        
    }
    freeMatrix(matrix, matrixSize);
    return 0;
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

void saveMatrix(char* fileName, double **matrix, int matrixSize){
    int i, j;    
    FILE *file;    
    file = fopen(fileName, "w");
        
    if(file == NULL){
        printf("Não foi possivel salvar a matriz\n");
        exit(1);    
    }
    
    for(i = 0; i < matrixSize; i++){
        for(j = 0; j < matrixSize; j++){
            fprintf(file, "%f ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

void freeMatrix(double **matrix, int matrixSize){
    int i;
    for(i = 0; i < matrixSize; i++){
        free(matrix[i]);
    }
    free(matrix);
}
