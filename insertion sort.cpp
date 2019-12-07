// InsertionSort.cpp : Defines the entry point for the console application.
// Ali Abu Saleh - 11611711 : 9:30-11

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;
vector<string> split(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

int main()
{
    int size;
    double temp = 0;
    cin >> size;
    
    double *arr = new double[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            for (int k = i; (k >= 1)&&(arr[k] < arr[k - 1]); k--) {

                temp = arr[k - 1];
                arr[k - 1] = arr[k];
                arr[k] = temp;


            }
        }
    }
    cout << "[";
    for (int j = 0; j < size; j++) {
        cout << arr[j];
        if (j < size - 1) {
            cout << ",";
        }
    }
    cout << "]";
    return 0;
}

