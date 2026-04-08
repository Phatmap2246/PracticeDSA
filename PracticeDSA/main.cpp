//
//  main.cpp
//  PracticeDSA
//
//  Created by Nguyen Duc Phat on 7/4/26.
//

#include <iostream>
#include <chrono>
#include "InsertionSort.hpp"
#include <ctime>
using namespace std;

int main(){
    srand(static_cast<int>(time(0)));
    auto start = chrono::high_resolution_clock::now();
    Student *st = new Student[4] {
        {"Phat1",10.0},
        {"Phat2",9.0},
        {"Phat3",8.0},
        {"Phat4",7.0}
        };
    Student newStudent = {"phat5",6.0};
    insertionSortStudent(st, 4, newStudent);
    for(int i = 0;i<5;i++){
        cout<<st[i].name<<" "<<st[i].gpa<<endl;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double,milli>time = end - start;
    cout<<"Running Time: "<<time.count()<<" ms"<<endl;
    return 0;
}

