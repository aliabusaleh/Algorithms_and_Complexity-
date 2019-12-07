
#include <iostream>
using namespace std;
void PrintMatrix(int *A, int MSIZE)
{
    printf("[ ");
    for (int i = 0; i < MSIZE; i++)
    {
        
        for (int j = 0; j < MSIZE; j++)
        {
            printf("%d ", A[i*MSIZE + j]);
        }
        
    }
    printf("]\n");
}

void ProduceQuarter_00(int *A, int MSIZE, int *quarter)
{
    int n = MSIZE * 2;
    int m = 0;
    for (int i = 0; i < MSIZE; i++)
        for (int j = 0; j < MSIZE; j++)
            quarter[m++] = A[i*n + j];
}
void ProduceQuarter_01(int *A, int MSIZE, int *quarter)
{
    int n = MSIZE * 2;
    int m = 0;
    for (int i = 0; i < MSIZE; i++)
        for (int j = 0; j < MSIZE; j++)
            quarter[m++] = A[i*n + (j + MSIZE)];
}

void ProduceQuarter_10(int *A, int MSIZE, int *quarter)
{
    int n = MSIZE * 2;
    int m = 0;
    for (int i = 0; i < MSIZE; i++)
        for (int j = 0; j < MSIZE; j++)
            quarter[m++] = A[(i + MSIZE)*n + j];
}
void ProduceQuarter_11(int *A, int MSIZE, int *quarter)
{
    int n = MSIZE * 2;
    int m = 0;
    for (int i = 0; i < MSIZE; i++)
        for (int j = 0; j < MSIZE; j++)
            quarter[m++] = A[(i + MSIZE)*n + (j + MSIZE)];
}
void CombineQuaters(int *quarter_00, int *quarter_01, int *quarter_10, int *quarter_11, int *C, int MSIZE)
{
    int n = MSIZE * 2;
    int m = 0;
    for (int i = 0; i < MSIZE; i++)
        for (int j = 0; j < MSIZE; j++)
            C[i*n + j] = quarter_00[m++];

    m = 0;
    for (int i = 0; i < MSIZE; i++)
        for (int j = 0; j < MSIZE; j++)
            C[i*n + (j + MSIZE)] = quarter_01[m++];

    m = 0;
    for (int i = 0; i < MSIZE; i++)
        for (int j = 0; j < MSIZE; j++)
            C[(i + MSIZE)*n + j] = quarter_10[m++];

    m = 0;
    for (int i = 0; i < MSIZE; i++)
        for (int j = 0; j < MSIZE; j++)
            C[(i + MSIZE)*n + (j + MSIZE)] = quarter_11[m++];

}

void AddMatrix(int *A, int *B, int *C, int MSIZE)
{
    for (int i = 0; i < MSIZE; i++)
        for (int j = 0; j < MSIZE; j++)
            C[i*MSIZE + j] = A[i*MSIZE + j] + B[i*MSIZE + j];

}
int *MatrixMulti(int *A, int *B, int size) {
  
    int *mat;
    mat = new int[size*size];
    int *Quad00_A, *Quad01_A, *Quad10_A, *Quad11_A;
    int *Quad00_B, *Quad01_B, *Quad10_B, *Quad11_B;
    int *mat1, *mat2, *mat3, *mat4;
   
    int msize=(size / 2);
    
    Quad00_A=new int[msize*msize]; 
    Quad01_A=new int[msize*msize]; 
    Quad10_A=new int[msize*msize]; 
    Quad11_A=new int[msize*msize]; 

    Quad00_B=new int[msize*msize]; 
    Quad01_B=new int[msize*msize]; 
    Quad10_B=new int[msize*msize]; 
    Quad11_B=new int[msize*msize]; 
    
    mat1=new int[msize*msize]; 
    mat2=new int[msize*msize]; 
    mat3=new int[msize*msize]; 
    mat4=new int[msize*msize]; 
    
    
    
    if (size == 1) {

        mat[0] = A[0] * B[0];

    
    }
    else{
    /*make quarter*/
    ProduceQuarter_00(A, size/2, Quad00_A);
    ProduceQuarter_00(B, size/2, Quad00_B);

    ProduceQuarter_01(A, size/2, Quad01_A);
    ProduceQuarter_01(B, size/2, Quad01_B);

    ProduceQuarter_10(A, size/2, Quad10_A);
    ProduceQuarter_10(B, size/2, Quad10_B);

    ProduceQuarter_11(A, size/2, Quad11_A);
    ProduceQuarter_11(B, size/2, Quad11_B);
    
    
    ProduceQuarter_10(A, size/2, mat1);
    ProduceQuarter_10(B, size/2, mat2);

    ProduceQuarter_11(A, size/2, mat3);
    ProduceQuarter_11(B, size/2, mat4);

    /*Recursive calling*/
    AddMatrix(MatrixMulti(Quad00_A, Quad00_B, size / 2), MatrixMulti(Quad01_A, Quad10_B, size / 2), mat1, size/2);
    AddMatrix(MatrixMulti(Quad00_A, Quad01_B, size / 2), MatrixMulti(Quad01_A, Quad11_B, size / 2), mat2, size/2);
    AddMatrix(MatrixMulti(Quad10_A, Quad00_B, size / 2), MatrixMulti(Quad11_A, Quad10_B, size / 2), mat3, size/2);
    AddMatrix(MatrixMulti(Quad10_A, Quad01_B, size / 2), MatrixMulti(Quad11_A, Quad11_B, size / 2), mat4, size/2);

    CombineQuaters(mat1, mat2, mat3, mat4, mat, size/2);
    
    }
    return mat;


}

int main()
{
    // for the size assume that the matrix is n*n 
    int size;
    cin >> size;
    // the array's pointer 
    //Array number 1 
    int *Arr1 = new int[(size*size)];
    //Array number 2 
    int *Arr2 = new int[(size*size)];
    // reading the matrix's 1  elements
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> Arr1[i*size + j];
        }
    }
    // reading the matrix's 2  elements
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> Arr2[i*size + j];
        }
    }
    int *x;
    
     x =MatrixMulti(Arr1, Arr2, size);
     PrintMatrix(x, size);

    return 0;
}