//
//  LinkedList.cpp
//  PracticeDSA
//
//  Created by Nguyen Duc Phat on 8/4/26.
//

#include "LinkedList.hpp"
#include <iostream>
using namespace std;
// linked list

/*Bài tập 1: Xây dựng nền móng (Create & Read)
 * Yêu cầu: * Định nghĩa struct node { int data; node* next; }; và một struct quản lý struct LinkedList { node* head; };.
     * Viết hàm pushFront (thêm vào đầu), pushBack (thêm vào cuối) và printList (in danh sách).*/

node* createnode(int data){
    node* theNewnode = new node();
    if (!theNewnode){
        cout<<"Cannot create a new node !"<<endl;
        return nullptr;
    }
    theNewnode->data = data;
    theNewnode->next = nullptr;
    return theNewnode;
}

void pushFront(node* &head, int data){
    node* theNewnode = createnode(data);
    theNewnode->next = head;
    head = theNewnode;
}

void pushBack (node* &head, int data){
    node* theNewnode = createnode(data);
    if (!head) {
        head = theNewnode;
        return;
    }
    node* head_temp = head;
    while (head_temp->next) {
        head_temp = head_temp->next;
    }
    head_temp->next = theNewnode;
}

void printList(node* head){
    if (!head){
        cout<<"The list is NULL !"<<endl;
        return;
    }
    cout<<"List: ";
    while(head->next){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<head->data<<endl;
}

/*Bài tập 2: "Máy chém" Con trỏ (Update & Delete)
 * Yêu cầu: * Viết hàm deleteFront (xóa phần tử đầu) và deleteBack (xóa phần tử cuối).
     * Viết hàm deleteValue(int x) để tìm và xóa Node đầu tiên có giá trị bằng x.
 * Lưu ý sinh tử: Trong C++, xóa xong phải gọi lệnh delete (giải phóng bộ nhớ) để tránh Memory Leak (rò rỉ RAM). Cậu làm AI sau này dữ liệu cực lớn, Leak một phát là đứng máy ngay!*/

void deleteFront(node* &head){
    if (!head){
        return;
    }
    node* select = head;
    head = head->next;
    delete select;
}

void deleteBack(node* &head){
    if (!head) {
        cout<<"The list is NULL!"<<endl;
        return;
    }
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    node* head_temp = head;
    while (head_temp->next->next) {
        head_temp = head_temp->next;
    }
    node* select = head_temp->next;
    head_temp->next = head_temp->next->next;
    delete select;
    select = nullptr;
}

void deleteValue(node* &head, int x){
    if (!head) {
        cout<<"The list is NULL!"<<endl;
        return;
    }
    node* select = nullptr;
    if(head->data == x){
        select = head;
        head = head->next;
        delete select;
        select = nullptr;
    }
    node* head_temp = head;
    while (head_temp->next && head_temp->next->data != x) {
        head_temp = head_temp->next;
    }
    if (head_temp->next){
        select = head_temp->next;
        head_temp->next = head_temp->next->next;
        delete select;
        select = nullptr;
    }
    else{
        cout<<"The value is not in the Linked List !"<<endl;
    }
}
/* Yêu cầu: * Đổi data thành struct Song { string title; string artist; int duration; };.
 * Viết hàm insertSorted: Thêm một bài hát mới vào danh sách sao cho danh sách luôn được sắp xếp theo thời lượng (duration) tăng dần.
* Mục tiêu: Rèn kỹ năng duyệt bằng 2 con trỏ (current và previous) để tìm đúng vị trí cần nhét Node mới vào giữa danh sách.*/

listSong* createListSong(song data){
    listSong * theNewList = new listSong();
    if(!theNewList){
        cout<<"Cannot create a new Node!"<<endl;
        return NULL;
    }
    theNewList->data = data;
    theNewList->next = nullptr;
    return theNewList;
}
void insertSorted(listSong* &head, song data){
    listSong* theNewNode = createListSong(data);
    if (!head) {
        head = theNewNode;
        return;
    }
    if (head->data.duration > data.duration){
        theNewNode->next = head;
        head = theNewNode;
        return;
    }
    listSong* curr = head;
    listSong* previous = head;
    while (curr && curr->data.duration < data.duration) {
        previous = curr;
        curr = curr->next;
    }
    if (curr) {
        theNewNode->next = curr;
        previous->next = theNewNode;
    }
    else{
        previous->next = theNewNode;
    }
}
void printSong(listSong *head){
    if (!head) {
        cout<<"The list is NULL!"<<endl;
        return;
    }
    while (head) {
        cout<<"Name: "<<head->data.title<<" Artist: "<<head->data.artist<<" Duration: "<<head->data.duration<<endl;
        head = head->next;
    }
}

/*Bài tập 4: Đảo ngược dòng thời gian (Reverse Linked List)
 * Yêu cầu: Viết hàm đảo ngược toàn bộ chiều của danh sách liên kết (Ví dụ: 1 -> 2 -> 3 biến thành 3 -> 2 -> 1).
 * Cảnh báo: Đây là câu hỏi kinh điển 100% xuất hiện trong các buổi phỏng vấn thực tập. Cậu chỉ được dùng 3 con trỏ (prev, curr, next) để lật ngược mũi tên tại chỗ, tuyệt đối không tạo danh sách mới!*/

void reverseLinkedList(node* &head){
    if (!head || !head->next) {
        return;
    }
    node* tail = head;
    node* bucket = nullptr;
    while (tail->next) {
        tail = tail->next;
    }
    while (head != tail) {
        bucket = head;
        head = head->next;
        bucket->next = tail->next;
        tail->next = bucket;
    }
    head = tail;
}

/*Bài tập 5: Tuyệt kỹ "Rùa và Thỏ" (Tìm điểm chính giữa)
 * Yêu cầu: Tìm Node nằm ở chính giữa danh sách liên kết chỉ trong đúng 1 lần duyệt.
 * Gợi ý cực mạnh: Dùng 2 con trỏ cùng xuất phát ở Head. Con Rùa đi 1 bước (slow = slow->next), con Thỏ đi 2 bước (fast = fast->next->next). Khi Thỏ chạy đến cuối đường thì Rùa đang đứng ở đâu? 😎
*/


node* findTheMidOfList(node* head){
    if (!head || !head->next)  {
        return head;
    }
    node* fast = head;
    node* slow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

/*Bài tập 6: Phát hiện Vòng lặp vô tận (Cycle Detection)
 * Yêu cầu: Đôi khi code lỗi, con trỏ next của thằng cuối cùng không trỏ vào NULL mà trỏ ngược về một Node ở giữa, tạo thành vòng lặp vô tận. Hãy viết hàm kiểm tra xem danh sách có bị "dính ngải" vòng lặp hay không.
 * Tư duy: Lại mang "Rùa và Thỏ" ra dùng. Chạy trên một cái vòng tròn, liệu Thỏ chạy nhanh có bao giờ bắt kịp (đụng trúng) Rùa từ phía sau lưng không?*/

bool isCycledList(node* head){
    if (!head || head->next) {
        return false;
    }
    node* slow = head;
    node* fast = head->next;
    while (fast && fast->next) {
        if(slow == fast){
            return true;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return false;
}

/*Bài tập 7: Trộn 2 Danh sách đã sắp xếp (Merge Two Sorted Lists)
 * Yêu cầu: Cho 2 Linked List đã sắp xếp tăng dần. Hãy trộn chúng lại thành 1 Linked List mới cũng tăng dần (giống hệt bước Merge của Merge Sort).
 * Thử thách: Không được tạo thêm Node mới, chỉ được cắt/nối các con trỏ của 2 danh sách cũ!*/

node* mergeTwoSortedList(node* q1 , node* q2){
    if (!q1 || !q2) {
        return nullptr;
    }
    node* smaller = nullptr;
    node* larger = nullptr;
    node* head = nullptr;
    node* bucket = nullptr;
    if (q1->data < q2->data) {
        smaller = q1;
        head = q1;
        larger = q1;
    }
    else{
        smaller = q2;
        head = q2;
        larger = q1;
    }
    while (smaller->next && larger ) {
        if (smaller->next->data > larger->data) {
            bucket = larger;
            larger = larger->next;
            bucket->next = smaller->next;
            smaller->next = bucket;
        }
        smaller = smaller->next;
    }
    if (larger) {
        smaller->next = larger;
    }
    return head;
}

/*Bài tập 8: "Du hành đa chiều" (Doubly Linked List)
 * Yêu cầu: Tưởng tượng cậu đang code tính năng "Back / Forward" của trình duyệt Web.
     * Sửa Node thành có 2 con trỏ: Node* prev và Node* next.
     * Viết hàm Thêm/Xóa cho cấu trúc này. Lợi thế là cậu có thể đi lùi từ Tail về Head!*/

Doubly* createDoublyNode(int data){
    Doubly* theNewNode = new Doubly();
    if (!theNewNode) {
        cout<<"Cannot create a new Node!"<<endl;
        return nullptr;
    }
    theNewNode->data = data;
    theNewNode->next = nullptr;
    theNewNode->prev = nullptr;
    return theNewNode;
}

void pushBackDoubly(Doubly* &head, int data){
    Doubly* theNewNode = createDoublyNode(data);
    if (!head) {
        head = theNewNode;
        return;
    }
    Doubly* head_temp = head;
    while (head_temp->next) {
        head_temp = head_temp->next;
    }
    head_temp->next = theNewNode;
    theNewNode->prev = head_temp;
}

void insertSortedDoubly(Doubly* &head, int x){
    Doubly* theNewNode = createDoublyNode(x);
    if (!head) {
        head = theNewNode;
        return;
    }
    if (head->data > x) {
        theNewNode->next = head;
        head->prev = theNewNode;
        head = theNewNode;
        return;
    }
    Doubly*head_temp = head;
    while (head_temp->next && head_temp->next->data < x) {
        head_temp = head_temp->next;
    }
    theNewNode->next = head_temp->next;
    head->next->prev = theNewNode;
    theNewNode->prev = head_temp;
    head_temp->next = theNewNode;
}
