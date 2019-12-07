// Quicksort.cpp : Defines the entry point for the console application.
// Ali Abu Saleh - 11611711 - 9:30-11

#include <iostream>
using namespace std;
//to print the array 
void printArray(double * Array,int  size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << Array[i];
        if (i < size - 1) {
            cout << ",";
        }
    }
    cout << "]";
}
void quickSort(double *A,int start, int end) {
    //the base, if we have 1 or 0 element in the array
    if (start >= end) {
        return;
    }
    // the pivot is the last element in the array
    double pivot = A[end];
    double temp = 0;
    int i, k=start;
    // for loop to switch the elements for the pivot
    for (i = start; i < end; i++) {
        if (A[i]<=pivot) {
            temp = A[k];
            A[k] = A[i];
            A[i] = temp;
            k++;
        }
        
    }
    // change the pivot in the pivot index in k 
    temp = A[end];
    A[end] =A[k];
    A[k] = temp;
    // call the fucnction for the two half's array withot the last povot // size = size -1 // 
    quickSort(A, start, k-1);
    quickSort(A, k+1, end);

}

int main()
{
    // size of the array 
    int size; 
    cin >> size;
    // the dynamic array for the elements
    double *Arr = new double[size];
    // read the array's elements 
    for (int i = 0; i < size; i++) {
        cin >> Arr[i];
    }
    // call the quickSort function 
    quickSort(Arr,0, size-1);
    // print the array 
    printArray(Arr, size);
    return 0;

}
