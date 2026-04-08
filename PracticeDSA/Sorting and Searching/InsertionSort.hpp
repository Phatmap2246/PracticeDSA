//
//  Practice.hpp
//  PracticeDSA
//
//  Created by Nguyen Duc Phat on 8/4/26.
//

#ifndef Practice_hpp
#define Practice_hpp

#include <stdio.h>
#include <string>
struct Node
{
    int data;
    Node* next;
};
struct Student{
    std::string name;
    float gpa;
};
int insertionSortCountingShift(int*arr, int n);
void createRandom2dArray(int ** &B, int m,int n);
void print2DArray(int** B, int m , int n);
void insertionSortDecrease(int**B, int m, int n);
void delete2DArray(int** &B, int m);
void insertSortedNode(Node* &head, int value);
void printList(Node* head);
void insertionSortCString(const char *A[], int n);
void insertionSortStudent(Student *&A, int n, Student newStudent);
#endif /* Practice_hpp */
