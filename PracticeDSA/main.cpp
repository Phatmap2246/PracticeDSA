//
//  main.cpp
//  PracticeDSA
//
//  Created by Nguyen Duc Phat on 7/4/26.
//

#include <iostream>
#include <chrono>
#include "MergeSort.hpp"
#include <ctime>
#include <vector>
using namespace std;

int main(){
    srand(static_cast<int>(time(0)));
    auto start = chrono::high_resolution_clock::now();
    int A[] = {2,6,7};
    int B[] = {1,2,4,9};
    int C[] ={3,1,2,9,10,2,1,22,99,100,38,78};
    Node* head = NULL;
    Node* head2 = NULL;
    for (int x:A){
        appendListMS(head, x);
    }
    for (int x:B){
        appendListMS(head2, x);
    }
    printListMS(head);
    printListMS(head2);
    Node* head3 = mergeSortedLists(head, head2);
    printListMS(head3);
    mergeSortHybrid(C, 0,11);
    for (int i = 0; i<12; i++) {
        cout<<C[i]<<endl;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double,milli>time = end - start;
    cout<<"Running Time: "<<time.count()<<" ms"<<endl;
    return 0;
}

