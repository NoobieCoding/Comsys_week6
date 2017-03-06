#include <stdio.h>
#include <stdlib.h>
int size = 0, count = 0;

void readMatrix(char* filename) {

  FILE* file = fopen(filename, "r");
  fscanf(file, "%d \n",&size);
  int  matrix[size][size], matC[size][size];
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      fscanf(file, "%d", &matrix[i][j]);
    }
  }

  for (int i = 0;i < size; i++){
    for(int j = 0;j < size; j++){
        matC[i][j] = 0;
        for(int k = 0;k < size;k++){
            matC[i][j]+=matrix[i][k]*matrix[k][j];
        }
    }
}
  fclose(file);
  free(matrix);
  free(matC);
}

int main() {
  readMatrix("/mat1000.dat");
  return 0;
}
