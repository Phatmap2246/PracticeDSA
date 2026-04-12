//
//  MergeSort.hpp
//  PracticeDSA
//
//  Created by Nguyen Duc Phat on 12/4/26.
//

#ifndef MergeSort_hpp
#define MergeSort_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace::std;
struct Product{
    std::string id;
    double price;
};
struct Node {
    int data;
    Node* next;
};
void mergeSort(int* A, int left, int right);
void mergeSortProduct(Product* Pd, int left, int right);
void mergeSortStringLength(vector<string> &arr,int left,int right);
void printListMS(Node* head);
void appendListMS(Node* &head, int data);
Node* mergeSortedLists(Node* q1, Node* q2);
void mergeSortCountInversion(int *A, int left, int right, int &count);
void mergeSortHybrid(int* arr, int left, int right);
#endif /* MergeSort_hpp */
