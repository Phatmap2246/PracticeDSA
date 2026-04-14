//
//  BinaryTree.hpp
//  PracticeDSA
//
//  Created by Nguyen Duc Phat on 8/4/26.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>
struct tree{
    int data;
    tree* left;
    tree* right;
};
void insertTree(tree* &root, int data);
void printNLRTree(tree*root);
void printLNRTree(tree* root);
void printLRNTree(tree* root);
bool searchTree(tree* root, int x);
int countNodes(tree* root);
int findMin(tree* root);
int findMax(tree* root);
int countLeaves(tree* root);
int treeHeight (tree* root);
bool isBST(tree* root);
bool isBST(tree* root);
void deleteTreeNode(tree* &root, int x);
#endif /* BinaryTree_hpp */
