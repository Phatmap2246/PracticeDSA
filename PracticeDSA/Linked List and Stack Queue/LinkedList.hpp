//
//  LinkedList.hpp
//  PracticeDSA
//
//  Created by Nguyen Duc Phat on 8/4/26.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <iostream>
#include <string>
using namespace ::std;
struct node{
    int data;
    node* next;
};
struct song{
    string title;
    string artist;
    float duration;
};
struct  listSong{
    song data;
    listSong* next;
};
struct Doubly {
    int data;
    Doubly* next;
    Doubly* prev;
};
void pushFront(node* &head, int data);
void pushBack (node* &head, int data);
void printList(node* head);
void deleteFront(node* &head);
void deleteBack(node* &head);
void deleteValue(node* &head, int x);
void insertSorted(listSong* &head, song data);
void printSong(listSong *head);
void reverseLinkedList(node* &head);
node* findTheMidOfList(node* head);
node* mergeTwoSortedList(node* q1 , node* q2);
#endif /* LinkedList_hpp */
