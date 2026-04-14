//
//  StackAndQueue.hpp
//  PracticeDSA
//
//  Created by Nguyen Duc Phat on 14/4/26.
//

#ifndef StackAndQueue_hpp
#define StackAndQueue_hpp

#include <stdio.h>
#include <iostream>
using namespace::std;
struct Node1{
    int data;
    Node1* next;
};
struct Stack {
    Node1* top;
};
struct Queue {
    Node1* front;
    Node1* rear;
};
struct nodeChar {
    char data;
    nodeChar* next;
};
struct charStack {
    nodeChar* top;
};
struct Line {
    string name;
    Line* next;
};
struct lineQueue {
    Line* front;
    Line* rear;
};
#endif /* StackAndQueue_hpp */
