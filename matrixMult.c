#include <stdlib.h>
#include <stdio.h>

//CS2600 Project 1
//Ryan Mangilin

struct matrix {
  float **m;
  int rows,cols;
};
int main(){
  struct matrix matA;//instance of matrix struct input A
  struct matrix matB;//instance of matrix struct input B
  struct matrix matC;//instance of matrix struct output
  printf("Please Enter the Size of Matrix A: ");
  scanf("%d",&matA.rows); //scans for int input(%d) for the rows of Matrix A
  scanf("%d",&matA.cols); //scans for int input for the cols of Matrix A

  printf("Please Enter the Size of Matrix B: ");
  scanf("%d",&matB.rows); //scans for int input for the rows of Matrix B
  scanf("%d",&matB.cols); //scans for int input for the cols of Matrix B

 
  if(matA.cols==matB.rows){ //checks if the given matrix sizes can be multiplied befor we enter the elements and multiply the columns in matrix A must be the same as the rows of matrix B 
    printf("The Matrix Sizes are Compatible for Multiplication.\n");
    printf("Please Enter the Elements of Matrix A: ");
    matA.m = (float **)malloc(matA.rows*sizeof(float*));//memory allocation
    for (int i=0;i<matA.rows;i++){//for loops in order to be able to enter the values of each cell in Matrix A
      matA.m[i] = (float*)malloc(matA.cols * sizeof(float));//memory allocation
      for (int j=0;j<matA.cols;j++){
	scanf("%f",&matA.m[i][j]);//scan function
      }
    }
    printf("Please Enter the Elements of Matrix B: ");
    matB.m = (float **)malloc(matB.rows*sizeof(float*));//memory allocation
    for (int i=0;i<matB.rows;i++){//same for loops in order to scan the propper values for Matrix B
      matB.m[i] = (float*)malloc(matB.cols * sizeof(float));//memory allocation
      for (int j=0;j<matB.cols;j++){
	scanf("%f",&matB.m[i][j]);//scan function
      }
    }
    printf("Matrix A: \n");//for loop displaying the entered Matrix A 
    for (int i=0;i<matA.rows;i++){
      for (int j=0;j<matA.cols;j++) {
	printf("%f ",matA.m[i][j]);
      }
      printf("\n");
    }
    printf("\nmultiplied by\n");
    printf("Matrix B: \n");//for loop displaying the entered Matrix B
    for (int i=0;i<matB.rows;i++){
      for (int j=0;j<matB.cols;j++) {
        printf("%f ",matB.m[i][j]);
      }
      printf("\n");
    }
    
    matC.rows=matA.rows;
    matC.cols=matB.cols;
    matC.m=(float **)malloc(matC.rows*sizeof(float*));//for loop allocating propper amount of memory for Matrix C
    for (int i=0; i < matC.rows;i++){
       matC.m[i]=(float *)malloc(matC.cols * sizeof(float*));
       for (int j=0;j < matC.cols;j++) {
	 matC.m[i][j] = 0;
       }
    }   
    for (int i=0; i<matA.rows;i++) {//multiplying Matrix A and Matrix B, then stores the result into Matrix C
      for (int j=0;j<matB.cols;j++) {
	for (int k=0; k<matA.cols;k++){
	  matC.m[i][j] += matA.m[i][k]*matB.m[k][j];
	}
      }
    }
    printf("\n=\n");//for loop displaying the outcome of the multiplication
    for (int i=0;i<matC.rows;i++){
      for (int j=0;j<matC.cols;j++){
	printf("%f ",matC.m[i][j]);
      }
      printf("\n");// in order to group the rows 
    }
  }

  else//not compatible matrices to multiply
    printf("Error Cannot Multiply Matrices");//prompts error if the two matrix sizes are incompatible for multiplication
  return 0;
}
