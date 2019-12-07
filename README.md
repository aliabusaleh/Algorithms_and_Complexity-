## Algorithms_and_Complexity-
## Copy right for @Alighabusaleh
This Repository contains the Algorithm homeworks for ANNU 
## Merge Sort algorithm

Implement Merge algorithm to sort an integer array in ascending order, and try to make it as fast as possible.

    Comment Your Name And Registration Number As The First Line In The Code
    You are prohibited form using the built in functions of any language
    Your Code will be Reviewed to prevent any cheating

Input Format

    First line:the size of the array
    Second line:the array to be sorted(numbers seperated by spaces)

Constraints

-

Output Format

output between two brackets and each number seperated by a coma.

Sample Input

    6
    1 9 3 5 4 7

Sample Output

[1,3,4,5,7,9]

Explanation

sort array in an ascending order.

## Quick Sort algorithm

Implement Quick Sort algorithm to sort an integer array in ascending order, and try to make it as fast as possible .
Comment Your Name And Registration Number As The First Line In The Code

    You are required to build the functionality of Quick Sort algorithm and use to sort the arrays.

    You are prohibited form using the built in functions of any language

    Your Code will be Reviewed to prevent any cheating :)

Input Format

    First line:the size of the array
    Second line:the array to be sorted(numbers seperated by spaces)

Constraints

No Constraints

Output Format
output between two brackets,and each two numbers seperated by comma .

Sample Input

    6
    1 9 3 5 4 7

Sample Output

[1,3,4,5,7,9]

Explanation

Sort the array in ascending order.

## Insertion Sort algorithm

Implement Insertion algorithm to sort an integer array in ascending order, and try to make it as fast as possible.

    Comment Your Name And Registration Number As The First Line In The Code
    You are prohibited form using the built in functions of any language
    Your Code will be Reviewed to prevent any cheating

Input Format

    First line:the size of the array
    Second line:the array to be sorted(numbers seperated by spaces)

Constraints

-

Output Format
output between two brackets,and each two numbers seperated by comma .

Sample Input

    6
    1 9 3 5 4 7

Sample Output

[1,3,4,5,7,9]

Explanation

sort the array in ascending order.

##  Recursive Matrix Multiplication 
Given matrix A and matrix B, compute Matrix C, where C = A*B using resursive matrix multiplication.

You can use the following helper functions.

void PrintMatrix(int *A, int MSIZE)
{
    for (int i = 0; i < MSIZE; i++)
    {
        for (int j = 0; j < MSIZE; j++)
        {
            printf("[%4d]", A[i*MSIZE + j]);
        }
        printf("\n");
    }
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
            quarter[m++] =A[i*n+(j+MSIZE)];
}

void ProduceQuarter_10(int *A, int MSIZE, int *quarter)
{
    int n = MSIZE * 2;
    int m = 0;
    for (int i = 0; i < MSIZE; i++)
        for (int j = 0; j < MSIZE; j++)
            quarter[m++] = A[(i+MSIZE)*n + j];
}
void ProduceQuarter_11(int *A, int MSIZE, int *quarter)
{
    int n = MSIZE * 2;
    int m = 0;
    for (int i = 0; i < MSIZE; i++)
        for (int j = 0; j < MSIZE; j++)
            quarter[m++] = A[(i + MSIZE)*n + (j+MSIZE)];
}


void CombineQuaters(int *quarter_00, int *quarter_01, int *quarter_10, int *quarter_11,int *C,int MSIZE)
{
    int n = MSIZE * 2;
    int m = 0;
    for (int i = 0; i < MSIZE; i++)
        for (int j = 0; j < MSIZE; j++)
            C[i*n + j] = quarter_00[m++] ;

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
            C[i*MSIZE+j] = A[i*MSIZE+j] + B[i*MSIZE+j];

}

Input Format

Matrix_size Matrix_A_values Matrix_B_values

Constraints

Don't cheat

Output Format

Matrix_C_values

Sample Input 0

2
1 2 3 4
5 6 7 8

Sample Output 0

[ 19 22 43 50 ]

