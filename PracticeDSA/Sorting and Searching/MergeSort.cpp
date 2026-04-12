//
//  MergeSort.cpp
//  PracticeDSA
//
//  Created by Nguyen Duc Phat on 12/4/26.
//

#include "MergeSort.hpp"
#include <iostream>
#include <vector>
using namespace std;

// mergeSort
void merge(int *A, int left, int mid, int right){
    int i = left, j = mid+1, index = 0;
    int * Temp = new int[right - left +1];
    while (i <= mid && j <= right) {
        if (A[i]<A[j]) {
            Temp[index] = A[i];
            i++;
        }
        else{
            Temp[index] = A[j];
            j++;
        }
        index++;
    }
    while (i <= mid) {
        Temp[index] = A[i];
        i++;
        index++;
    }
    while (j <= right) {
        Temp[index] = A[j];
        j++;
        index++;
    }
    // copy and change the array
    for (int k = 0;k<index;k++){
        A[left+k] = Temp[k];
    }
    delete [] Temp;
    Temp = NULL;
}

void mergeSort(int* A, int left, int right){
    if (left>=right) {
        return;
    }
    int mid = (left+right)/2;
    // recursion
    mergeSort(A,left,mid);
    mergeSort(A,mid+1,right);
    //merge
    merge(A,left,mid,right);
}
/*Bài tập 6: Merge Sort cơ bản trên Struct Hàng Hóa
 * Yêu cầu:
     * Tạo struct Product gồm: string id, double price.
     * Viết hàm Merge Sort phân chia mảng Product và trộn lại theo tiêu chí: Giá (price) tăng dần.
     * In mảng ra màn hình.*/

void mergeProduct(Product* Pd, int left, int mid, int right){
    int i = left, j = mid+1, index = 0;
    Product* Temp = new Product[right - left + 1];
    while (i <= mid && j <= right) {
        if (Pd[i].price < Pd[j].price) {
            Temp[index] = Pd[i];
            i++;
        }
        else{
            Temp[index] = Pd[j];
            j++;
        }
        index++;
    }
    while (i <= mid) {
        Temp[index] = Pd[i];
        i++;
        index++;
    }
    while (j <=mid) {
        Temp[index] = Pd[j];
        j++;
        index++;
    }
    // copy and change the array
    for (int k = 0; k<index; k++) {
        Pd[left+k] = Temp[k];
    }
    delete [] Temp;
    Temp = NULL;
}

void mergeSortProduct(Product* Pd, int left, int right){
    if (left >= right) {
        return;
    }
    int mid = (left+right)/2;
    // recursion
    mergeSortProduct(Pd, left, mid);
    mergeSortProduct(Pd, mid+1, right);
    //merge
    mergeProduct(Pd, left, mid, right);
}

/*Bài tập 7: Sắp xếp mảng Chuỗi theo độ dài (Khẳng định tính Ổn định)
 * Yêu cầu:
     * Cho vector<string> arr = {"dog", "apple", "cat", "bat", "banana"}.
     * Dùng Merge Sort sắp xếp theo độ dài chuỗi tăng dần.
     * Vì Merge Sort là thuật toán ổn định (Stable), "dog", "cat", "bat" phải giữ nguyên thứ tự xuất hiện ban đầu của chúng sau khi sắp xếp.
 * Gợi ý: Trong hàm Merge, điều kiện trộn phải là L[i].length() <= R[j].length(). Dấu = cực kỳ quan trọng để duy trì tính ổn định!*/

void mergeStringLength(vector<string> &arr, int left, int mid, int right){
    int L = left, R = mid+1;
    vector<string> Temp;
    while (L <= mid && R <= right) {
        if (arr[L].length() <= arr[R].length()) {
            Temp.push_back(arr[L]);
            L++;
        }
        else{
            Temp.push_back(arr[R]);
            R++;
        }
    }
    while (L <= mid) {
        Temp.push_back(arr[L]);
        L++;
    }
    while (R <= right) {
        Temp.push_back(arr[R]);
        R++;
    }
    // copy and change the array
    for (int k = 0 ; k<Temp.size(); k++) {
        arr[left+k] = Temp[k];
    }
    Temp.clear();
}
void mergeSortStringLength(vector<string> &arr,int left,int right){
    if (left>=right) {
        return;
    }
    int mid = (left+right)/2;
    //recursion
    mergeSortStringLength(arr, left, mid);
    mergeSortStringLength(arr, mid+1, right);
    //merge
    mergeStringLength(arr, left, mid, right);
    
}
/*Bài tập 8: Hợp nhất (Merge) hai Danh sách liên kết đơn đã sắp xếp (Dạng đề thi thực tế)
 * Yêu cầu:
     * Cho hai DSLK đơn q1 và q2 chứa các số nguyên đã được sắp xếp tăng dần.
     * Viết hàm mergeSortedLists(Node* q1, Node* q2) trả về một head mới chứa tất cả phần tử của cả hai danh sách theo thứ tự tăng dần.
     * Ràng buộc: Chỉ thay đổi các con trỏ next để nối các node lại với nhau, không được cấp phát new Node mới.
 * Gợi ý: Dùng một "Node giả" (Dummy Node) để làm mỏ neo. Dùng 2 con trỏ chạy trên q1 và q2, thằng nào nhỏ hơn thì móc đuôi Dummy Node vào thằng đó.*/

Node* createNodeMS(int data){
    Node* theNewNode = new Node();
    if (!theNewNode) {
        cout<<"Cannot create a new node !"<<endl;
        return NULL;
    }
    theNewNode->data = data;
    theNewNode->next = NULL;
    return theNewNode;
}
void appendListMS(Node* &head, int data){
    Node* theNewNode = createNodeMS(data);
    if (!head) {
        head = theNewNode;
        return;
    }
    Node* head_temp = head;
    while (head_temp->next) {
        head_temp = head_temp->next;
    }
    head_temp->next = theNewNode;
}
void printListMS(Node* head){
    if (!head) {
        cout<<"Head is NULL !"<<endl;
        return;
    }
    cout<<"List: ";
    while (head->next) {
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<head->data<<endl;
}
Node* mergeSortedLists(Node* q1, Node* q2){
    if (!q1 || !q2) {
        cout<<"q1 or q2 is NULL !"<<endl;
        return NULL;
    }
    Node* head = NULL;
    Node* larger = NULL;
    Node* smaller = NULL;
    Node* bucket = NULL;
    if (q1->data > q2->data) {
        larger = q1;
        head = q2;
        smaller = q2;
    }
    else{
        larger = q2;
        head = q1;
        smaller = q1;
    }
    while (smaller->next && larger) {
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


/*Bài tập 9: Ứng dụng Merge Sort - Đếm số cặp nghịch thế (Inversions)
 * Yêu cầu:
     * Cho mảng số nguyên. Một cặp nghịch thế là cặp (i, j) sao cho i < j nhưng arr[i] > arr[j]. (Ví dụ mảng [2, 4, 1, 3] có 3 nghịch thế: (2,1), (4,1), (4,3)).
     * Sửa đổi hàm Merge Sort để nó vừa sắp xếp, vừa đếm và trả về tổng số lượng cặp nghịch thế.
 * Gợi ý: Trong hàm Merge, khi bạn lấy một phần tử từ mảng Phải R[j] đưa vào mảng kết quả trước mảng Trái L[i], điều đó có nghĩa là R[j] nhỏ hơn TẤT CẢ các phần tử còn lại trong mảng Trái. Cộng biến đếm thêm (số phần tử còn lại của mảng Trái).*/

void mergeCountInversion(int*A, int left, int mid, int right, int &count){
    int i = left, j = mid+1, index = 0;
    int * Temp = new int [right - left +1];
    while (i <=mid && j<=right) {
        if (A[i] <= A[j]) {
            Temp[index] = A[i];
            i++;
        }
        else{
            Temp[index] = A[j];
            j++;
            count = count + (mid - i +1);
        }
        index++;
    }
    while (i <= mid) {
        Temp[index] = A[i];
        i++;
        index++;
    }
    while (j <= right) {
        Temp[index] = A[j];
        j++;
        index++;
    }
    // copy and change the array
    for (int k = 0; k<index;k++){
        A[left+k] = Temp[k];
    }
    delete [] Temp;
    Temp = NULL;
}

void mergeSortCountInversion(int *A, int left, int right, int &count){
    if (left>=right) {
        return;
    }
    int mid = (right+left)/2;
    // recursion
    mergeSortCountInversion(A, left, mid,count);
    mergeSortCountInversion(A, mid+1, right,count);
    // merge
    mergeCountInversion(A, left, mid, right, count);
}
/*Bài tập 10: Thuật toán lai (Hybrid Sort) - Kết hợp Merge và Insertion
 * Yêu cầu:
     * Merge Sort rất tốn chi phí gọi đệ quy khi mảng bị chia quá nhỏ.
     * Hãy viết một hàm HybridSort: Ban đầu mảng chia đôi giống hệt Merge Sort. Nhưng khi kích thước mảng con $N \le 5$, hãy dừng đệ quy và gọi hàm InsertionSort để sắp xếp mảng con đó.
     * Cuối cùng vẫn dùng hàm Merge để trộn các mảng con lại.
 * Gợi ý: Trong hàm mergeSort(arr, left, right), thêm lệnh if (right - left + 1 <= 5) { insertionSort(arr, left, right); return; }. Đây chính là tư tưởng nguyên thủy của Timsort (thuật toán sort mặc định của Python và Java) đó!*/

void insertionSortMS(int* arr, int left, int right){
    int j = 0, target = 0;
    for (int i = left+1;i<=right;i++){
        j = i-1;
        target = arr[i];
        while (j>=left && arr[j]>target) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = target;
    }
}

void mergeHybrid(int* arr, int left, int mid, int right){
    int i = left, j = mid+1, index = 0;
    int* Temp = new int [right - left + 1];
    while (i <= mid && j <= right) {
        if (arr[i]<arr[j]) {
            Temp[index] = arr[i];
            i++;
        }
        else{
            Temp[index] = arr[j];
            j++;
        }
        index++;
    }
    while (i <= mid) {
        Temp[index] = arr[i];
        i++;
        index++;
    }
    while (j <= right) {
        Temp[index] = arr[j];
        j++;
        index++;
    }
    // copy and change the array
    for (int k = 0; k<index; k++){
        arr[left+k] = Temp[k];
    }
    delete [] Temp;
    Temp = NULL;
}

void mergeSortHybrid(int* arr, int left, int right){
    if (right - left + 1 <=5 ) {
        insertionSortMS(arr, left, right);
        return;
    }
    int mid = (left+right)/2;
    // recursion
    mergeSortHybrid(arr, left, mid);
    mergeSortHybrid(arr, mid+1, right);
    // merge
    mergeHybrid(arr, left, mid, right);
}
