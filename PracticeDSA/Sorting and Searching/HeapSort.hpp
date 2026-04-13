//
//  HeapSort.hpp
//  PracticeDSA
//
//  Created by Nguyen Duc Phat on 13/4/26.
//

#ifndef HeapSort_hpp
#define HeapSort_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
struct Patient {
    string name;
    int age;
    bool isEmergency;
};
struct Element {
    int value;
    int col;
    int row;
};
void heapSort(int *A, int n);
void heapifyBulidHeap(int* A, int n, int index);
void buildHead(int *A, int n);
void heapSortDecrease(int *A, int n);
void heapSortCountSwap(int *A, int n, int &countSwap);
void heapSortPatient(Patient *P, int n);
void heapSortCString(const char* arr[], int n);
void topKTrending(int *A, int n, int k);
void createRandomData(int *&A);
void streamingDataKLargest(int *A, int n, int k);
void ternaryHeap(int *A, int n);
void introSort(int *A, int left, int right, int countRecursion);
#endif /* HeapSort_hpp */
