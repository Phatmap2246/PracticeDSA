//
//  Self_Practice\.cpp
//  DSA_Practice
//
//  Created by Nguyen Duc Phat on 18/3/26.
//

#include "BubbleSort.hpp"
#include <iostream>
#include <string>
using namespace::std;
Node* create_node_self(int x){
    Node* New_node = new Node();
    if (!New_node) {
        cerr<<"Fail to creat new node"<<endl;
        exit(1);
    }
    New_node->data = x;
    New_node->next = nullptr;
    return New_node;
}
void append_list_self(Node* &head, int x){
    Node* new_node = create_node_self(x);
    if (!head) {
        head = new_node;
        return;
    }
    Node* head_tmp = head;
    while (head_tmp->next) {
        head_tmp = head_tmp->next;
    }
    new_node->next = head_tmp->next;
    head_tmp->next = new_node;
}
void print_list_self(Node* head){
    if (!head) {
        cerr<<"Error list"<<endl;
        exit(1);
    }
    cout<<"List: ";
    while (head->next) {
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<head->data<<endl;
}

// 18/3/2026
// bubble sort
void bubble_sort1(int *A, int n){
    bool swapped = true;
    for (int i =0; i<n-1; i++) {
        swapped = false;
        for (int j =0; j<n-1-i; j++) {
            if (A[j] > A[j+1]) {
                swapped = true;
                swap(A[j], A[j+1]);
            }
        }
        if (!swapped) {
            return;
        }
    }
}
void bubble_sort2(int *A, int n){
    bool swapped = true;
    int left = 0, right = n;
    while (left <= right && swapped) {
        swapped = false;
        for (int i = left; i<right-1; i++) {
            if (A[i]>A[i+1]) {
                swapped = true;
                swap(A[i], A[i+1]);
            }
        }
        right--;
        for (int i = right; i>left+1; i--) {
            if (A[i]<A[i-1]) {
                swapped = true;
                swap(A[i],A[i-1]);
            }
        }
        left++;
        if (!swapped) {
            return;
        }
    }
    
}

void bubble_sort_list_sefl(Node* &head){
    if (!head || !head->next) {
        return;
    }
    // duyet lan dau
    Node* head_tmp = head;
    int n = 0;
    bool swapped = false;
    while (head_tmp->next) {
        n++;
        if (head_tmp->data>head_tmp->next->data) {
            swapped = true;
            swap(head_tmp->data, head_tmp->next->data);
        }
        head_tmp = head_tmp->next;
    }
    if (!swapped) {
        return;
    }
    for (int i=0; i<n-1; i++) {
        head_tmp = head;
        swapped = false;
        for (int j =0; j<n-i-1; j++) {
            if (head_tmp->data>head_tmp->next->data) {
                swapped = true;
                swap(head_tmp->data, head_tmp->next->data);
            }
            head_tmp = head_tmp->next;
        }
        if (!swapped) {
            return;
        }
    }
}
//
/*Bài tập 1: Sắp xếp mảng struct Sinh viên theo tên
 Yêu cầu:
 * Tạo struct Student gồm: string name, int id, float gpa.
 * Viết hàm bubble sort sắp xếp mảng Student theo thứ tự alphabet của tên (tăng dần).
 * In mảng trước và sau khi sắp xếp.
 Gợi ý: So sánh name có thể dùng toán tử > hoặc < (C++ string hỗ trợ so sánh từ điển).*/
void bubble_sort_name_array(student* list1, int n){
    bool swapped = false;
    for (int i=0; i<n-1; i++) {
        swapped = false;
        for (int j = 0; j < n-1-i; j++) {
            if(list1[j].name> list1[j+1].name){
                swapped = true;
                swap(list1[j], list1[j+1]);
            }
        }
        if (!swapped) {
            return;
        }
    }
}

/*Bài tập 2: Sắp xếp danh sách liên kết đơn các struct Sinh viên theo GPA giảm dần
 Yêu cầu:
 * Dùng lại struct Student.
 * Tạo danh sách liên kết đơn (mỗi node chứa Student và next).
 * Viết hàm bubble sort (dựa trên dữ liệu, không thay đổi liên kết) để sắp xếp theo GPA giảm dần.
 * In danh sách sau mỗi lần duyệt (nếu muốn theo dõi quá trình).*/

student_list* creat_new_st(student st1){
    student_list* st_new = new student_list();
    if (!st_new) {
        cerr<<"Error create new node"<<endl;
        exit(1);
    }
    st_new->data = st1;
    st_new->next = NULL;
    return st_new;
}
void append_st(student_list* &head, student st1){
    student_list* new_node = creat_new_st(st1);
    if (!head) {
        head = new_node;
        return;
    }
    student_list* head_tmp = head;
    while (head_tmp->next) {
        head_tmp = head_tmp->next;
    }
    new_node->next = head_tmp->next;
    head_tmp->next = new_node;
}
// print
void print_st(student_list* head){
    if (!head) {
        cerr<<"Error empty list"<<endl;
        exit(1);
    }
    cout<<"List:"<<endl;
    while (head) {
        cout<<"Name: "<<head->data.name<<'\t'<<"id: "<<head->data.id<<'\t'<<"Gpa: "<<head->data.gpa<<endl;
        head = head->next;
    }
}
void bubble_sort_GPA_List(student_list* &head){
    if (!head) {
        cerr<<"Empty list!"<<endl;
        exit(1);
    }
    if (!head->next) {
        return;
    }
    // duyet lan dau
    int n =0;
    bool swapped = false;
    student_list* head_tmp = head;
    while (head_tmp->next) {
        n++;
        if (head_tmp->data.gpa < head_tmp->next->data.gpa) {
            swapped = true;
            swap(head_tmp->data, head_tmp->next->data);
        }
        head_tmp = head_tmp->next;
    }
    if (!swapped) {
        return;
    }
    for (int i = 0; i<n-1; i++) {
        swapped = false;
        head_tmp = head;
        for (int j =0; j<n-i-1; j++) {
            if (head_tmp->data.gpa < head_tmp->next->data.gpa) {
                swapped = true;
                swap(head_tmp->data, head_tmp->next->data);
            }
            head_tmp = head_tmp->next;
        }
        if (!swapped) {
            return;
        }
    }
}

/*Bài tập 3: Sắp xếp mảng các chuỗi (string) theo độ dài tăng dần
 Yêu cầu:
 * Cho mảng vector<string> hoặc string arr[] với các chuỗi bất kỳ.
 * Dùng bubble sort để sắp xếp theo độ dài của chuỗi (số ký tự). Nếu hai chuỗi cùng độ dài, giữ nguyên thứ tự ban đầu (bubble sort ổn định).
 * In kết quả.*/

int bubble_sort_string_arr(string* A, int n){
    bool swapped = false;
    int swap_count = 0;
    for (int i =0; i<n-1; i++) {
        swapped = false;
        for (int j = 0; j<n-i-1; j++) {
            if (A[j].length()>A[j+1].length()) {
                swapped = true;
                swap_count++;
                swap(A[j],A[j+1]);
            }
        }
        if (!swapped) {
            return swap_count;
        }
    }
    return swap_count;
}

/*Bài tập 4: Sắp xếp mảng struct Hàng hóa theo giá và tên
 Yêu cầu:
 * Tạo struct Product gồm: string name, double price, int quantity.
 * Sắp xếp mảng Product sao cho:
     * Ưu tiên theo price tăng dần.
     * Nếu price bằng nhau, sắp theo name alphabet.
 * Sử dụng bubble sort.*/

void bubble_sort_product(Product* list2, int n){
    bool swapped = false;
    for (int i = 0; i<n-1; i++) {
        swapped = false;
        for (int j = 0; j<n-1-i; j++) {
            if (list2[j].price>list2[j+1].price) {
                swapped = true;
                swap(list2[j], list2[j+1]);
            }
            else if (list2[j].price == list2[j+1].price && list2[j].name>list2[j+1].name){
                swapped = true;
                swap(list2[j], list2[j+1]);
            }
        }
        if (!swapped) {
            return;
        }
    }
}
/*Bài tập 5: Sắp xếp mảng C‑string (mảng ký tự)
 Yêu cầu:
 * Khai báo mảng char* hoặc char arr[][100] chứa các chuỗi.
 * Dùng bubble sort và strcmp() để sắp xếp theo thứ tự từ điển tăng dần.
 * In kết quả.*/
void bubble_sort_char(char* A, int n){
    bool swapped = true;
    for (int i = 0; i<n-1; i++) {
        swapped = false;
        for (int j =0; j<n-i-1; j++) {
            if (strcasecmp((A+j), (A+j+1))>0) {
                swapped = true;
                swap(A[j], A[j+1]);
            }
        }
        if (!swapped) {
            return;
        }
    }
}

/*Bài tập 6: Sắp xếp struct Ngày tháng
 Yêu cầu:
 * Tạo struct Date gồm: int day, month, year.
 * Viết hàm bubble sort sắp xếp mảng các ngày tháng theo thứ tự thời gian tăng dần (năm → tháng → ngày).
 * In danh sách trước và sau khi sắp.*/
void bubble_sort_date(Date* list3, int n){
    bool swapped = true;
    for (int i = 0; i<n-1; i++) {
        swapped = false;
        for (int j = 0; j<n-1-i; j++) {
            if (list3[j].year>list3[j+1].year || (list3[j].year == list3[j+1].year && list3[j].month>list3[j+1].month) ||(list3[j].year == list3[j+1].year && list3[j].month == list3[j+1].month && list3[j].day>list3[j+1].day)) {
                swapped = true;
                swap(list3[j],list3[j+1]);
            }
        }
        if (!swapped) {
            return;
        }
    }
}

/*Bài tập 7: Sắp xếp mảng struct Học sinh với nhiều tiêu chí (ổn định)
 Yêu cầu:
 * Struct Student thêm trường int age.
 * Sắp xếp mảng theo tên alphabet; nếu tên giống nhau thì sắp theo tuổi tăng dần.
 * Bubble sort vốn ổn định, hãy tận dụng tính chất đó.*/
void bubble_sort_st2(student* A, int n){
    bool swapped = true;
    for (int i =0; i<n-1; i++) {
        swapped = false;
        for (int j =0; j<n-1-i; j++) {
            if (A[j].name>A[j+1].name || (A[j].name == A[j+1].name && A[j].age>A[j+1].age)) {
                swapped =true;
                swap(A[j], A[j+1]);
            }
        }
        if (!swapped) {
            return;
        }
    }
}

/*Bài tập 8: Đếm số lần hoán đổi khi sắp xếp mảng string
 Yêu cầu:
 * Cho mảng các chuỗi.
 * Thực hiện bubble sort và đếm số lần hoán đổi đã xảy ra.
 * In mảng đã sắp xếp và số lần hoán đổi.
*/
st_lk_2* create_2lk(student data){
    st_lk_2* new_node = new st_lk_2();
    if (!new_node) {
        cerr<<"Erorr"<<endl;
        exit(1);
    }
    new_node->data = data;
    new_node->next = nullptr;
    new_node->prev = nullptr;
    return new_node;
}

void append_lk2(st_lk_2* &head, student data){
    st_lk_2* new_node = create_2lk(data);
    if (!head) {
        head = new_node;
        return;
    }
    st_lk_2* head_tmp = head;
    while (head_tmp->next) {
        head_tmp = head_tmp->next;
    }
    new_node->next = head_tmp->next;
    new_node->prev = head_tmp;
    head_tmp->next = new_node;
}
void print_st2(st_lk_2* head){
    if (!head) {
        cerr<<"Error empty list"<<endl;
        exit(1);
    }
    cout<<"List:"<<endl;
    while (head) {
        cout<<"Name: "<<head->data.name<<'\t'<<"id: "<<head->data.id<<'\t'<<"Gpa: "<<head->data.gpa<<'\t'<<"Tuoi: "<<head->data.age<<endl;
        head = head->next;
    }
}
