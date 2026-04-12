//
//  QuickSort.cpp
//  PracticeDSA
//
//  Created by Nguyen Duc Phat on 12/4/26.
//

#include "QuickSort.hpp"
#include <iostream>
using namespace std;

// quick sort
void quickSort(int*A, int left, int right){
    if (left >= right) {
        return;
    }
    int i = left, j = left-1, pivot = right;
    while (i < pivot) {
        if (A[i] < A[pivot]) {
            j++;
            swap(A[i],A[j]);
        }
        i++;
    }
    swap(A[j+1], A[pivot]);
    pivot = j+1;
    // recursion
    quickSort(A, left, pivot-1);
    quickSort(A, pivot+1, right);
}

/*Bài tập 1: Quick Sort cơ bản & Đếm số lần Đệ quy
 * Yêu cầu: * Thực hiện Quick Sort trên mảng số nguyên tố tăng dần.
     * Sử dụng phần tử cuối cùng làm Pivot (Lomuto Partition).
     * Tạo một biến toàn cục hoặc truyền tham chiếu để đếm xem có bao nhiêu lời gọi hàm đệ quy đã thực hiện.
 * Gợi ý: Mỗi lần hàm quickSort được gọi, hãy tăng biến đếm lên 1.*/
bool isPrime(int n){
    if (n==2 || n==3) {
        return true;
    }
    if (n<2 || n%2 == 0 || n%3 == 0){
        return false;
    }
    for (int i = 5 ; i<=sqrt(n); i+=6) {
        if (n%i==0 || n%(i+2)==0) {
            return false;
        }
    }
    return true;
}
void createPrimeArray(int* A, int n){
    if(!A || n ==0)return;
    int bucket = 0;
    for (int i = 0; i<n; i++) {
        while (true) {
            bucket = rand()%1000000;
            if (isPrime(bucket)) {
                break;
            }
        }
        A[i] = bucket;
    }
}
void quickSortPrimeArray(int*A, int left, int right, int &countRecursion){
    if (left>=right) {
        return;
    }
    int i = left, j = left-1, pivot = right;
    while (i<pivot) {
        if (A[i]<A[pivot]) {
            j++;
            swap(A[i], A[j]);
        }
        i++;
    }
    swap(A[j+1], A[pivot]);
    pivot = j+1;
    // recursion
    countRecursion++;
    quickSortPrimeArray(A, left, pivot-1, countRecursion);
    countRecursion++;
    quickSortPrimeArray(A, pivot+1, right, countRecursion);
}

/*Bài tập 2: So sánh chiến thuật chọn Pivot
 * Yêu cầu: * Viết 2 phiên bản Quick Sort: 1. Chọn Pivot là phần tử đầu tiên. 2. Chọn Pivot là phần tử giữa(Middle).
     * Chạy thử với một mảng đã sắp xếp sẵn. Cậu sẽ thấy sự khác biệt về tốc độ và số bước nhảy!
 * Gợi ý: Đây là cách để cậu hiểu tại sao việc chọn Pivot "xui" sẽ khiến Quick Sort bị chậm đi thành O(n2).*/

void quickSortFirstPivot(int*A, int left, int right){
    if (left>=right) {
        return;
    }
    int i = right, j = right+1, pivot = left;
    while (i>left) {
        if (A[i] > A[pivot]) {
            j--;
            swap(A[i], A[j]);
        }
        i--;
    }
    swap(A[j-1], A[pivot]);
    pivot = j - 1;
    // recursion
    quickSortFirstPivot(A, left, pivot-1);
    quickSortFirstPivot(A, pivot+1, right);
}

void quickSortMidPivot(int *A, int left, int right){
    if (left>=right) {
        return;
    }
    int i = left, j = right, mid = (left+right)/2;
    int pivot_Value = A[mid];
    while (i <= j) {
        while (A[i] < pivot_Value) {
            i++;
        }
        while (A[j] > pivot_Value) {
            j--;
        }
        if (i <= j) {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }
    // recursion
    if (left < j) {
        quickSortMidPivot(A, left, j);
    }
    if (i<right){
        quickSortMidPivot(A, i, right);
    }
}
 /*Bài tập 3: Sắp xếp giảm dần với Hoare Partition
  * Yêu cầu: * Tìm hiểu về sơ đồ phân hoạch Hoare (hai con trỏ chạy từ 2 đầu ngược nhau).
      * Áp dụng để sắp xếp mảng số nguyên theo thứ tự giảm dần.
*/
void quickSortHoare(int *A, int left, int right){
    if (left >= right) {
        return;
    }
    int i = left, j = right, mid = (left+right)/2, pivot_Value = A[mid];
    while (i <= j) {
        while (A[i] > pivot_Value) {
            i++;
        }
        while (A[j] < pivot_Value) {
            j--;
        }
        if (i <= j) {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }
    if (left < j) {
        quickSortHoare(A, left, j);
    }
    if (right > i){
        quickSortHoare(A, i, right);
    }
}


/*Bài tập 4: Sắp xếp Danh sách Sinh viên theo GPA
 * Yêu cầu: * Sử dụng lại struct Student { string name; float gpa; }.
     * Dùng Quick Sort để sắp xếp danh sách sinh viên theo GPA giảm dần.
     * Câu hỏi phụ: Nếu 2 sinh viên cùng GPA, thứ tự tên của họ có bị đảo lộn không? (Kiểm tra tính ổn định của Quick Sort).
 B. thứ tự sẽ đảo lộn do i và j sẽ đổi liên tục mà không phân biệt các số giống nhau*/


void quickSortGPA(Student* st1, int left, int right){
    if (left>=right) {
        return;
    }
    int i = left, j = right, pivot = st1[(left+right)/2].gpa;
    while (i <= j) {
        while (st1[i].gpa > pivot) {
            i++;
        }
        while (st1[j].gpa < pivot) {
            j--;
        }
        if (i <= j) {
            swap(st1[i], st1[j]);
            i++;
            j--;
        }
    }
    if (left < j) quickSortGPA(st1, left, j);
    if (right > i) quickSortGPA(st1, i, right);
}

/*Bài tập 5: Sắp xếp mảng C-string (Mảng con trỏ)
 * Yêu cầu: * Tương tự bài Insertion Sort lúc sáng, nhưng dùng Quick Sort để sắp xếp mảng char* arr[] theo thứ tự từ điển.
     * Nhớ dùng strcmp và chỉ hoán đổi địa chỉ con trỏ!*/

void quickSortCString(const char* arr[], int left, int right){
    if (left >= right) {
        return;
    }
    int i = left, j = right;
    const char* B = arr[(left+right)/2];
    while (i <= j) {
        while (strcmp(arr[i], B) < 0) {
            i++;
        }
        while (strcmp(arr[j], B) > 0) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (left < j){
        quickSortCString(arr, left, j);
    }
    if(right > i){
        quickSortCString(arr, i, right);
    }
}
/*Bài tập 6: Bài toán "Lính cứu hỏa" (Quick Select)
 * Yêu cầu: * Không sắp xếp toàn bộ mảng. Hãy viết hàm findKthSmallest(int arr[], int n, int k) để tìm phần tử nhỏ thứ k trong mảng.
     * Ứng dụng: Dựa trên tư tưởng phân hoạch của Quick Sort (nếu Pivot rơi đúng vào vị trí k thì dừng lại). Đây là thuật toán cực nhanh (O(n) trung bình).*/

int partition(int *arr, int left, int right){
    int i = left, j = left-1,pivot = right;
    while (i<pivot) {
        if (arr[i]<arr[pivot]) {
            j++;
            swap(arr[i],arr[j]);
        }
        i++;
    }
    swap(arr[j+1],arr[pivot]);
    pivot = j+1;
    return pivot;
}
int quickSelect(int *arr, int left, int right, int k){
    int p = partition(arr,left,right);
    if(p == k -1) return arr[p];
    else if (p < k-1) return quickSelect(arr, p+1, right, k);
    else return quickSelect(arr, left, p-1,k);
}

int findKthSmallest(int arr[], int n, int k){
    return quickSelect(arr, 0, n-1, k);
}


