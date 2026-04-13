//
//  main.cpp
//  PracticeDSA
//
//  Created by Nguyen Duc Phat on 7/4/26.
//

#include <iostream>
#include <chrono>
#include "QuickSort.hpp"
#include <ctime>
#include <vector>
using namespace std;

int main(){
    srand(static_cast<int>(time(0)));
    auto start = chrono::high_resolution_clock::now();
    int A[] ={10, 2, 14, 4, 7};
    const char* arr[] = {"Zebra", "Apple", "Mango", "Banana"};
    Student B[] ={
        {"Phat", 9},
        {"Phat2", 7},
        {"Phat3",9},
        {"Phat4",10}
    };
    quickSortGPA(B, 0, 3);
    for (Student x:B){
        cout<<"Name: "<<x.name<<" GPA: "<<x.gpa<<endl;
    }
    quickSortCString(arr, 0, 3);
    for(int i = 0;i<4;i++){
        cout<<arr[i]<<'\t';
    }
    cout<<endl;
    quickSortComparator(A, 0, 4, 8);
    for(int x:A){
        cout<<x<<" ";
    }
    cout<<endl;
    int D[] = {2,0,1,2,1,0,1};
    DutchNationalFlag(D, 7);
    for(int x:D){
        cout<<x<<" ";
    }
    cout<<endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double,milli>time = end - start;
    cout<<"Running Time: "<<time.count()<<" ms"<<endl;
    return 0;
}

