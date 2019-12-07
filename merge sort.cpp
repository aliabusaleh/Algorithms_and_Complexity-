// Merge sort.cpp : Defines the entry point for the console application.
//Metge sort alogo
// Ali Abu Saleh - 11611711 - 9:30-11


#include <stdio.h>
#include <string.h>
#include <deque>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;
void printArray(double *ptrAr, int size);
void merge(double *arr, int st, int en) {
    int md = (st + en) / 2;
    //printArray(arr,(en-st+1));
    //new temprory array
    double *ar = new double[en - st + 1];
    int s1 = st;
    int e1 = md + 1;
    int s2 = st;
    while (s1 <= md && e1 <= en) {
        if (arr[s1] < arr[e1]) {
            ar[s2] = arr[s1];

            s1++;

        }
        else {
            ar[s2] = arr[e1];

            e1++;

        }
        s2++;
    }

    while (s1 <= md) {
        ar[s2] = arr[s1];
        s2++;
        s1++;

    }
    while (e1 <= en) {
        ar[s2] = arr[e1];
        s2++;
        e1++;

    }
    for (int i = st; i <en + 1; i++) {
        arr[i] = ar[i];

    }

}

void merge_sort(double *arr, int start, int end) {

    // base when the lengh it 1 
    if (start >= end) {
        return;
    }

    // if the lenght is not 1
    int mid = ((end + start) / 2);
    // call merge_sort for the two half's array
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    //merge the two half arrays
    merge(arr, start, end);


}
void printArray(double *ptrAr, int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << ptrAr[i];
        if (i < size - 1) {
            cout << ",";
        }

    }
    cout << "]";
}


int main() {
    int size = 0;
    double *ptrArr;

    cin >> size;
    ptrArr = new double[size];
    for (int i = 0; i < size; i++) {
        cin >> ptrArr[i];

    }

    merge_sort(ptrArr, 0, size - 1);
    printArray(ptrArr, size);

    return 0;
}

