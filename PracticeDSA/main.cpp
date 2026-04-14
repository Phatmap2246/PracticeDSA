//
//  main.cpp
//  PracticeDSA
//
//  Created by Nguyen Duc Phat on 7/4/26.
//

#include <iostream>
#include <chrono>
#include "LinkedList.hpp"
#include <ctime>
#include <vector>
using namespace std;

int main(){
    srand(static_cast<int>(time(0)));
    auto start = chrono::high_resolution_clock::now();
    song A[] ={
        {"abc","bb",3},
        {"bacd","cc",4},
        {"acds","ss",2.30},
        {"siuuu","rr",0.50},
        {"happy","ts",3.14}
    };
    listSong* head = nullptr;
    for(song x:A){
        insertSorted(head, x);
    }
    printSong(head);
    int B[] = {1,2,3,4,5,6,7,8,9};
    int C[] = {1,3,5,7,9,100};
    node* head2 = nullptr;
    node* head3 = nullptr;
    for (int x:B){
        pushBack(head2, x);
    }
    for (int x:C){
        pushBack(head3, x);
    }
    node* head4 = mergeTwoSortedList(head2, head3);
    printList(head4);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double,milli>time = end - start;
    cout<<"Running Time: "<<time.count()<<" ms"<<endl;
    return 0;
}

