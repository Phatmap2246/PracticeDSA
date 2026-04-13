//
//  main.cpp
//  PracticeDSA
//
//  Created by Nguyen Duc Phat on 7/4/26.
//

#include <iostream>
#include <chrono>
#include "HeapSort.hpp"
#include <ctime>
#include <vector>
using namespace std;

int main(){
    srand(static_cast<int>(time(0)));
    auto start = chrono::high_resolution_clock::now();
    int A[] = {10,28,39,11,2,4,5,3,1};
    int B[] ={10, 9, 8, 7, 6};
    Patient P1[] = {
        {"Peso1",40,false},
        {"Peso2",70,true},
        {"Peso3",18,false},
        {"Peso4",100,true}
    };
    heapSortPatient(P1, 4);
    for(Patient x:P1){
        cout<<"Name: "<<x.name<<" age: "<<x.age<<" Emergency: "<<x.isEmergency<<endl;
    }
    heapSortDecrease(A, 9);
    for(int x :A){
        cout<<x<<" ";
    }
    cout<<endl;
    int countSwap = 0;
    heapSortCountSwap(B, 5, countSwap);
    for(int x :B){
        cout<<x<<" ";
    }
    cout<<endl;
    const char* arr[] = {"Zebra", "Apple", "Mango", "Banana"};
    heapSortCString(arr, 4);
    for (int i = 0; i<4; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"So lan swap: "<<countSwap<<endl;
    int countRecursion = 0;
    introSort(A, 0, 8, countRecursion);
    for(int x :A){
        cout<<x<<" ";
    }
    cout<<endl;
    Element El [] ={
        {1,0,1},
        {3,0,2},
        
        };
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double,milli>time = end - start;
    cout<<"Running Time: "<<time.count()<<" ms"<<endl;
    return 0;
}

