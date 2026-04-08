//
//  Practice.cpp
//  PracticeDSA
//
//  Created by Nguyen Duc Phat on 8/4/26.
//

#include "Practice.hpp"
#include <iostream>
using namespace::std;
Node* createNode(int data){
    Node* theNewNode = new Node();
    if(!theNewNode) return nullptr;
    theNewNode->data = data;
    theNewNode->next = nullptr;
    return theNewNode;
}
void appendList(Node* &head, int x){
    Node* theNewNode = createNode(x);
    if (!head)
    {
        head = theNewNode;
        return;
    }
    Node* head_temp = head;
    while (head_temp->next)
    {
        head_temp = head_temp->next;
    }
    head_temp->next = theNewNode;
}
void insertFirstList(Node* &head, int x){
    Node* theNewNode = createNode(x);
    if (!head)
    {
        head = theNewNode;
        return;
    }
    theNewNode->next = head;
    head = theNewNode;
    
}
int sizeOfList(Node* head){
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
    
}
void insertListKIndex(Node* &head,int index, int x){
    int sizeList = sizeOfList(head);
    if (index<0 || index>sizeList)
    {
        cout<<"Wrong Index !"<<endl;
        return;
    }
    Node* theNewNode = createNode(x);
    if (index == 0)
    {
        theNewNode->next = head;
        head = theNewNode;
        return;
    }
    Node* head_temp = head;
    for (int i = 0; i<index-1;i++){
        head_temp = head_temp->next;
    }
    if(head_temp->next) theNewNode->next = head_temp->next;
    head_temp->next = theNewNode;
    
}
void printList(Node* head){
    cout<<"List: ";
    while (head->next)
    {
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<head->data<<endl;
    
}
void deleteList(Node* &head){
    if(!head) return;
    Node* head_temp = nullptr;
    while (head)
    {
        head_temp = head;
        head = head->next;
        delete head_temp;
    }
    cout<<"Delete successed!"<<endl;
    
}
void deleteListKIndex(Node* &head,int index){
    int sizeList = sizeOfList(head);
    if (sizeList == 0 || index<0 || index>sizeList-1) {
        return;
    }
    Node* head_temp = head;
    if (index == 0) {
        head = head->next;
        delete head_temp;
        return;
    }
    Node* sellectedNode = nullptr;
    for (int i = 0; i<index-1; i++) {
        head_temp = head_temp->next;
    }
    sellectedNode = head_temp->next;
    head_temp->next = head_temp->next->next;
    delete sellectedNode;
    
}
void reverseList(Node*&head){
    if (!head || !head->next) {
        return;
    }
    Node* tail = head;
    Node* bucket = nullptr;
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
bool isCycleList(Node* head){
    if (!head||!head->next) {
        return false;
    }
    Node* slowNode = head;
    Node* fastNode = head->next;
    while (fastNode && fastNode->next) {
        if (slowNode == fastNode) {
            return true;
        }
        slowNode = slowNode->next;
        fastNode = fastNode->next->next;
    }
    return false;
}
void bubbleSort(int *A, int n){
    if (!A || n == 0) {
        return;
    }
    bool swapped = true;
    for (int i = 0; i<n-1; i++) {
        swapped = false;
        for (int j = 0; j<n-1-i; j++) {
            if (A[j]>A[j+1]) {
                swapped = true;
                swap(A[j],A[j+1]);
            }
        }
        if (!swapped) {
            return;
        }
    }
}
void bubbleSort2(int *A,int n){
    if (!A || n==0) {
        return;
    }
    int left = 0, right = n-1;
    bool swapped = true;
    while (left<=right && swapped == true) {
        swapped = false;
        for (int i = left; i<right; i++) {
            if (A[i]>A[i+1]) {
                swapped = true;
                swap(A[i],A[i+1]);
            }
        }
        right--;
        for (int j = right; j>left; j--) {
            if (A[j]<A[j-1]) {
                swapped = true;
                swap(A[j],A[j-1]);
            }
        }
        left++;
    }
}
void bubbleSortList(Node* &head){
    if (!head || !head->next) {
        return;
    }
    // duyet lan dau
    Node* head_temp = head;
    int sizeList = 0;
    bool swapped = false;
    while (head_temp->next) {
        sizeList++;
        if (head_temp->data > head_temp->next->data) {
            swapped = true;
            swap(head_temp->data, head_temp->next->data);
        }
        head_temp = head_temp->next;
    }
    if(!swapped) return;
    for (int i =0; i<sizeList-1; i++) {
        swapped = false;
        head_temp = head;
        for (int j = 0; j<sizeList-1-i; j++) {
            if (head_temp->data > head_temp->next->data) {
                swapped = true;
                swap(head_temp->data,head_temp->next->data);
            }
            head_temp = head_temp->next;
        }
        if (!swapped) {
            return;
        }
    }
}
/*Bài tập 1: Cài đặt lại hai thuật toán (cơ bản)
 Yêu cầu: Viết hai hàm insertionSort(int arr[], int n) và mergeSort(int arr[], int left, int right) sắp xếp mảng tăng dần. Sau đó kiểm tra với mảng {5, 2, 4, 6, 1, 3}.

 Mục tiêu: Ôn lại cách viết vòng lặp, đệ quy, và trộn mảng.*/
void insertionSort(int arr[], int n){
    if (!arr || n == 0) {
        return;
    }
    int j = 0, target = 0;
    for (int i = 1; i<n; i++) {
        j = i-1;
        target = arr[i];
        while (j>=0 && arr[j]>target) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = target;
    }
}
// merge sort
void merge(int arr[], int left, int mid, int right){
    int i = left, j = mid+1, index = 0;
    int* temp = new int [right - left+1];
    while (i<=mid && j<=right) {
        if (arr[i] < arr[j]) {
            temp[index] = arr[i];
            i++;
        }
        else{
            temp[index] = arr[j];
            j++;
        }
        index++;
    }
    while (i<=mid) {
        temp[index] = arr[i];
        i++;
        index++;
    }
    while (j<=right) {
        temp[index] = arr[j];
        j++;
        index++;
    }
    for (int k = 0; k<index; k++) {
        arr[left + k] = temp[k];
    }
    delete [] temp;
    temp = nullptr;
}
void mergeSort(int arr[], int left, int right){
    if (left>=right) {
        return;
    }
    int mid = (left+right)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr,left,mid,right);
}
/*Bài tập 1: Sắp xếp mảng số nguyên và Đếm số lần "Dịch chuyển" (Shift)
 
 Yêu cầu:

 Cho mảng số nguyên bất kỳ.

 Viết hàm Insertion Sort để sắp xếp mảng tăng dần.

 Thay vì đếm số lần so sánh, hãy đếm xem có tổng cộng bao nhiêu thao tác dịch chuyển phần tử (gán arr[j + 1] = arr[j]) đã diễn ra.

 Gợi ý: Biến đếm sẽ được cộng lên bên trong vòng lặp while khi bạn dời các phần tử lớn hơn sang phải để chừa chỗ trống chèn phần tử mới.*/
int insertionSortCountingShift(int*arr, int n){
    if (!arr || n==0) {
        return 0;
    }
    int j = 0, target = 0 , countShift = 0;
    for (int i = 1; i<n; i++) {
        target = arr[i];
        j = i-1;
        while (j>=0 && arr[j]>target) {
            arr[j+1] = arr[j];
            countShift++;
            j--;
        }
        arr[j+1] = target;
    }
    return countShift;
}

/*Bài tập 2: Sắp xếp các hàng của mảng 2 chiều (Dạng đề thi thực tế)
 * Yêu cầu:
     * Cho mảng 2 chiều B có m hàng và n cột chứa các số nguyên.
     * Viết hàm dùng Insertion Sort để sắp xếp từng hàng của mảng B theo thứ tự giảm dần.
     * In mảng 2 chiều ra màn hình trước và sau khi sắp xếp.
 * Gợi ý: Dùng một vòng lặp for bên ngoài để duyệt qua từng hàng i. Bên trong, áp dụng thuật toán Insertion Sort thuần túy cho mảng 1 chiều B[i].*/

void createRandom2dArray(int ** &B, int m,int n){
    B = new int*[m];
    for (int i=0; i<m; i++) {
        B[i] = new int [n];
    }
    for (int i = 0; i<m; i++) {
        for (int j = 0; j<n; j++) {
            B[i][j] = rand()%100;
            if(rand()%2 == 1) B[i][j] = -B[i][j];
        }
    }
}
void print2DArray(int** B, int m , int n){
    cout<<"2D Array: "<<endl;
    for (int i = 0; i<m; i++) {
        for (int j = 0; j<n; j++) {
            cout<<B[i][j]<<' ';
        }
        cout<<endl;
    }
}

void insertionSortDecrease(int**B, int m, int n){
    int k = 0, target = 0;
    for (int i = 0; i<m; i++) {
        for (int j = 1; j<n; j++) {
            k = j-1;
            target = B[i][j];
            while (k>=0 && B[i][k]<target) {
                B[i][k+1] = B[i][k];
                k--;
            }
            B[i][k+1] = target;
        }
    }
}

void delete2DArray(int** &B, int m){
    if(!B)return;
    for (int i = 0; i<m; i++) {
        delete []   B[i];
    }
    delete [] B;
    B = nullptr;
}

/*Bài tập 3: Xây dựng Danh sách liên kết đơn được sắp xếp sẵn (Online Sorting)
 * Yêu cầu:
     * Tạo struct Node chứa số nguyên và con trỏ next.
     * Viết hàm InsertSorted(Node* &head, int value). Mỗi khi nhận một số mới, hàm sẽ tự động tìm đúng vị trí để chèn node mới vào sao cho DSLK luôn tăng dần.
     * Nhập liên tục 5 số từ bàn phím và in danh sách ra.
 * Gợi ý: Đây chính là tư tưởng của Insertion Sort trên Linked List. Cần xử lý kỹ 2 trường hợp: Chèn vào đầu (nếu số mới nhỏ hơn head) và chèn vào giữa/cuối (dùng con trỏ chạy để tìm vị trí temp->next->data > value).*/
void insertSortedNode(Node* &head, int value){
    Node* theNewNode = createNode(value);
    if (!head || theNewNode->data < head->data) {
        theNewNode->next = head;
        head = theNewNode;
        return;
    }
    Node* head_temp = head;
    while (head_temp->next && head_temp->next->data<theNewNode->data) {
        head_temp = head_temp->next;
    }
    theNewNode->next = head_temp->next;
    head_temp->next = theNewNode;
}


/*Bài tập 4: Sắp xếp mảng C-string bằng mảng con trỏ
 * Yêu cầu:
     * Khai báo mảng con trỏ char* arr[] = {"Zebra", "Apple", "Mango", "Banana"};
     * Dùng Insertion Sort sắp xếp mảng theo thứ tự từ điển tăng dần.
     * Lưu ý: Chỉ hoán đổi các con trỏ (địa chỉ bộ nhớ), TUYỆT ĐỐI không dùng strcpy để sao chép nội dung chuỗi (giúp tối ưu hiệu suất).*/

void insertionSortCString(const char *A[], int n){
    const char* target = nullptr;
    int j = 0;
    for (int i = 1; i<n;i++){
        target = A[i];
        j = i-1;
        while (j>=0 && strcmp(A[j], target)>0) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = target;
    }
}

/*Bài tập 5: Sắp xếp mảng Struct Sinh viên (Cập nhật điểm theo thời gian thực)
 * Yêu cầu:
     * Tạo struct Student gồm: string name, float gpa.
     * Mảng đang có sẵn 4 sinh viên đã được sắp xếp GPA giảm dần.
     * Có 1 sinh viên mới chuyển lớp vào. Viết hàm Insertion Sort chỉ thực hiện đúng 1 vòng lặp để chèn sinh viên mới này vào đúng vị trí của mảng.
 * Gợi ý: Không cần sort lại toàn bộ. Xem sinh viên mới là key, dịch chuyển các sinh viên có GPA thấp hơn sang phải 1 bước rồi chèn vào.*/
void insertionSortStudent(Student *&A, int n, Student newStudent){
    if (!A || n == 0) {
        return;
    }
    int index = n;
    Student* newStudentArray = new Student[n+1];
    for(int i = n-1 ;i>=0;i--){
        if (A[i].gpa < newStudent.gpa) {
            newStudentArray[i+1] = A[i];
            index = i;
        }
        else{
            newStudentArray[i] = A[i];
        }
    }
    newStudentArray[index] = newStudent;
    delete [] A;
    A = newStudentArray;
    
}
