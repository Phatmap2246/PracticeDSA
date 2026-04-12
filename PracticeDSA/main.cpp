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
    int A[] ={9,2,3,4,5,1,10,5};
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
    int k = 5, smallestK = 0;
    smallestK = findKthSmallest(A, 7, k);
    cout<<smallestK<<endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double,milli>time = end - start;
    cout<<"Running Time: "<<time.count()<<" ms"<<endl;
    return 0;
}

