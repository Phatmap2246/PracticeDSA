//
//  BinaryTree.cpp
//  PracticeDSA
//
//  Created by Nguyen Duc Phat on 8/4/26.
//

#include "BinaryTree.hpp"
#include <iostream>
using namespace std;
// binary tree
tree* creatTreNode(int data){
    tree* theNewNode = new tree();
    theNewNode->data = data;
    theNewNode->left = nullptr;
    theNewNode->right = nullptr;
    return theNewNode;
}
void insertTree(tree* &root, int data){
    if (!root) {
        root = creatTreNode(data);
        return;
    }
    if (data < root->data) {
        insertTree(root->left, data);
    }
    else if (data > root->data){
        insertTree(root->right, data);
    }
}
//NLR
void printNLRTree(tree*root){
    if (root) {
        cout<<root->data<<" ";
        printNLRTree(root->left);
        printNLRTree(root->right);
    }
}
//LNR
void printLNRTree(tree* root){
    if (root) {
        printLNRTree(root->left);
        cout<<root->data<<" ";
        printLNRTree(root->right);
    }
}

//LRN
void printLRNTree(tree* root){
    if (root) {
        printLRNTree(root->left);
        printLRNTree(root->right);
        cout<<root->data<<" ";
    }
}


/*Bài 1: Truy tìm tung tích (searchTree)
 * Yêu cầu: Viết hàm bool searchTree(tree* root, int x). Trả về true nếu số x có mặt trong cây, false nếu tìm đỏ mắt không thấy.
 * Gợi ý tư duy: Cậu đang đứng ở gốc. Nếu x bằng gốc $\rightarrow$ Bắt được rồi! Nếu x nhỏ hơn gốc $\rightarrow$ Đi tìm ở cành bên trái. Nếu x lớn hơn gốc $\rightarrow$ Đi tìm ở cành bên phải. Nếu gốc là NULL $\rightarrow$ Khỏi tìm, trả về false.*/

bool searchTree(tree* root, int x){
    if (root) {
        if (root->data > x) {
             return searchTree(root->left, x);
        }
        else if (root->data < x){
            return searchTree(root->right, x);
        }
        return true;
    }
    return false;
}

/*Bài 2: Kiểm kê dân số (countNodes)
 * Yêu cầu: Viết hàm int countNodes(tree* root) trả về tổng số lượng Node đang có trên cây.
 * Gợi ý đệ quy: Nếu cây rỗng, số Node = 0. Nếu không rỗng, Tổng số Node = 1 (chính nó) + Số Node bên cành trái + Số Node bên cành phải.*/

int countNodes(tree* root){
    if (!root) {
        return 0;
    }
    return 1+countNodes(root->left)+countNodes(root->right);
}

/*Bài 3: Tìm kẻ mạnh nhất / yếu nhất (findMax, findMin)
 * Yêu cầu: Viết hàm int findMin(tree* root) và int findMax(tree* root) để tìm ra giá trị nhỏ nhất và lớn nhất trong cây. (Nếu cây rỗng thì trả về INT_MIN hoặc INT_MAX).
 * Gợi ý siêu cấp: Nhớ lại luật BST xem! Thằng nhỏ nhất chắc chắn trốn ở tận cùng bên nào? Và thằng lớn nhất thì trốn ở đâu? Bài này thậm chí không cần đệ quy, dùng vòng lặp while chạy tuốt xuống dưới là xong!*/

int findMin(tree* root){
    while (root->left) {
        root = root->left;
    }
    return root->data;
}

int findMax(tree* root){
    while (root->right) {
        root = root->right;
    }
    return root->data;
}

/*Bài 4: Đếm lá rụng (countLeaves)
 * Yêu cầu: Viết hàm đếm xem cây có bao nhiêu Node Lá (Leaf Node).
 * Định nghĩa Node Lá: Là cái Node "cô đơn" không có con tráo, không có con phải (left == nullptr VÀ right == nullptr).*/

int countLeaves(tree* root){
    if (!root) return 0;
    if (!root->left && !root->right) {
        return 1;
    }
    return countLeaves(root->left) + countLeaves(root->right);
}

/*Bài 5: Đo chiều cao của Cây (treeHeight)
 * Yêu cầu: Trả về chiều cao (độ sâu lớn nhất) của cây. Cây rỗng có chiều cao = 0. Cây chỉ có 1 Node gốc có chiều cao = 1.
 * Gợi ý đệ quy: Chiều cao của cây = 1 (tính tầng của mình) + Chiều cao của cành nào DÀI HƠN giữa cành trái và cành phải. Cậu sẽ cần dùng hàm max() của C++ đấy.*/

int treeHeight (tree* root){
    if (!root) {
        return 0;
    }
    return 1+ max(treeHeight(root->left),treeHeight(root->right));
}

/*Bài 6: Phán Quan (isBST)
 * Yêu cầu: Giả sử ai đó đưa cho cậu một cái Cây Nhị Phân ngẫu nhiên. Hãy viết hàm bool isBST(tree* root) kiểm tra xem cái cây đó có tuân thủ đúng luật của Cây Nhị Phân Tìm Kiếm hay không.
 * Cạm bẫy: Không chỉ con trái nhỏ hơn cha, mà TẤT CẢ các Node nằm trong nhánh bên trái đều phải nhỏ hơn cha. Bài này siêu "hack não" đấy!*/

bool isBSTHelper(tree* root, int Max, int min){
    if (!root) {
        return true;
    }
    if (root->data < min || root->data > Max) {
        return false;
    }
    return isBSTHelper(root->left, root->data, min) && isBSTHelper(root->right, Max, root->data);
}

bool isBST(tree* root){
    return isBSTHelper(root, INT_MAX, INT_MIN);
}

/*Bài 7: "Trảm" Cây - Xóa một Node (deleteNode)
 * Yêu cầu: Viết hàm xóa một Node có giá trị X khỏi cây BST mà vẫn giữ nguyên được cấu trúc chuẩn của BST.
 * Độ khó KHỦNG KHIẾP: Cậu phải xử lý 3 trường hợp:
     1. Node cần xóa là Lá (Xóa cái rụp, gán bằng NULL).
     2. Node cần xóa chỉ có 1 đứa con (Nối dây từ Cha của nó thẳng xuống đứa con đó).
     3. Node cần xóa có tận 2 đứa con (Trường hợp "Đau đầu" nhất: Phải đi tìm người thừa kế!).*/
tree* findMinTreeNode(tree* root){
    while (root->left) {
        root = root->left;
    }
    return root;
}

void deleteTreeNode(tree* &root, int x){
    if (!root) {
        return;
    }
    else if (root->data > x){
        deleteTreeNode(root->left, x);
    }
    else if (root->data < x){
        deleteTreeNode(root->right, x);
    }
    else{
        tree* parent = root;
        if (!root->left) {
            root = root->right;
            delete parent;
            parent = nullptr;
            return;
        }
        else if (!root->right){
            root = root->left;
            delete parent;
            parent = nullptr;
            return;
        }
        else{
            parent = findMinTreeNode(root->right);
            root->data = parent->data;
            deleteTreeNode(root->right, parent->data);
        }
    }
}
