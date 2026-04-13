//
//  QuickSort.hpp
//  PracticeDSA
//
//  Created by Nguyen Duc Phat on 12/4/26.
//

#ifndef QuickSort_hpp
#define QuickSort_hpp

#include <stdio.h>
#include <string>
#include <iostream>
using namespace::std;
struct Student{
    string name;
    float gpa;
};
void quickSort(int*A, int left, int right);
void createPrimeArray(int* A, int n);
void quickSortPrimeArray(int*A, int left, int right, int &countRecursion);
void quickSortFirstPivot(int*A, int left, int right);
void quickSortMidPivot(int *A, int left, int right);
void quickSortHoare(int *A, int left, int right);
void quickSortGPA(Student* st1, int left, int right);
void quickSortCString(const char* arr[], int left, int right);
int findKthSmallest(int arr[], int n, int k);
void DutchNationalFlag(int* A, int n);
void quickSortIS(int *A, int left, int right);
void quickSortComparator(int *A, int left, int right, int x);
#endif /* QuickSort_hpp */
