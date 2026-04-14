//
//  main.cpp
//  PracticeDSA
//
//  Created by Nguyen Duc Phat on 7/4/26.
//

#include <iostream>
#include <chrono>
#include "BinaryTree.hpp"
#include <ctime>
#include <vector>
using namespace std;

int main(){
    srand(static_cast<int>(time(0)));
    auto start = chrono::high_resolution_clock::now();
    int A[] = {1,4,2,3,5,9,8,7,0};
    tree* root = nullptr;
    for(int x:A){
        insertTree(root, x);
    }
    printNLRTree(root);
    cout<<endl;
    printLNRTree(root);
    cout<<endl;
    printLRNTree(root);
    cout<<endl;
    if(searchTree(root, 1)){
        cout<<true<<endl;
    }
    cout<<countNodes(root)<<endl;
    cout<<findMin(root)<<endl;
    cout<<findMax(root)<<endl;
    cout<<countLeaves(root)<<endl;
    cout<<treeHeight(root)<<endl;
    if (isBST(root))cout<<true<<endl;
    deleteTreeNode(root, 10);
    printNLRTree(root);
    cout<<endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double,milli>time = end - start;
    cout<<"Running Time: "<<time.count()<<" ms"<<endl;
    return 0;
}

