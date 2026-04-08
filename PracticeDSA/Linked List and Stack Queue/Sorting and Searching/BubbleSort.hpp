//
//  Self_Practice\.hpp
//  DSA_Practice
//
//  Created by Nguyen Duc Phat on 18/3/26.
//

#ifndef Self_Practice__hpp
#define Self_Practice__hpp

#include <stdio.h>
#include <string>
using namespace::std;
struct Node{
    int data;
    Node* next;
};
struct student {
    string name;
    int id;
    float gpa;
    int age;
};
struct student_list{
    student data;
    student_list* next;
};
struct st_lk_2 {
    student data;
    st_lk_2* next;
    st_lk_2* prev;
};
struct Product{
    string name;
    double price;
    int quanlity;
};
struct Date {
    int day,month,year;
};
void bubble_sort1(int *A, int n);
void append_list_self(Node* &head, int x);
void print_list_self(Node* head);
void bubble_sort2(int *A, int n);
void bubble_sort_list_sefl(Node* &head);
void append_st(student_list* &head, student st1);
void print_st(student_list* head);
void bubble_sort_GPA_List(student_list* &head);
void bubble_sort_name_array(student* list1, int n);
int bubble_sort_string_arr(string* A, int n);
void bubble_sort_product(Product* list2, int n);
void bubble_sort_char(char* A, int n);
void bubble_sort_date(Date* list3, int n);
void bubble_sort_st2(student* A, int n);
void append_lk2(st_lk_2* &head, student data);
void print_st2(st_lk_2* head);
#endif /* Self_Practice__hpp */
