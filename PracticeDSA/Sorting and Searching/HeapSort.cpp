//
//  HeapSort.cpp
//  PracticeDSA
//
//  Created by Nguyen Duc Phat on 13/4/26.
//

#include "HeapSort.hpp"
#include <iostream>
#include <math.h>
using namespace std;

// heapSort
void heapify(int*A, int n, int index){
    if (index>n) {
        return;
    }
    int left = 2*index+1, right = 2*index+2, largest = index;
    if (left < n && A[left] > A[largest]) {
        largest = left;
    }
    if (right < n && A[right] > A[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(A[index], A[largest]);
        heapify(A, n, largest);
    }
}

void heapSort(int *A, int n){
    int theLastParent = n/2 - 1;
    for (int i = theLastParent; i>=0; i--) {
        heapify(A, theLastParent, i);
    }
    for(int i = n -1; i>=0;i--){
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}


/*Bài tập 1: Xây dựng Max Heap cơ bản & Trực quan hóa
 * Yêu cầu: * Viết hàm heapify và buildHeap trên một mảng số nguyên ngẫu nhiên.
     * Chưa cần sắp xếp (chưa gọi hàm pop/swap về cuối mảng). Chỉ chạy xong bước buildHeap rồi in mảng ra màn hình.
 * Gợi ý: Cậu hãy vẽ cái mảng kết quả đó ra giấy dưới dạng Cây nhị phân xem thằng lớn nhất đã ngoi lên gốc (index 0) chưa, và các nút cha có thực sự lớn hơn các nút con chưa.*/

void heapifyBulidHeap(int* A, int n, int index){
    if (index > n) {
        return;
    }
    int left = 2*index+1, right = 2*index+2, largest = index;
    if (left < n && A[left] > A[largest]) {
        largest = left;
    }
    if (right < n && A[right] > A[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(A[index], A[largest]);
        heapify(A, n, largest);
    }
}
void buildHead(int *A, int n){
    int theLastParent = n/2-1;
    for (int  i = theLastParent; i>=0; i--) {
        heapifyBulidHeap(A, n, i);
    }
}

/*Bài tập 2: Sắp xếp giảm dần với Min Heap
 * Yêu cầu: * Code mẫu ông thám tử đưa là Max Heap để sắp xếp Tăng dần.
     * Bây giờ cậu hãy đảo ngược logic: Viết cấu trúc Min Heap (nút cha luôn nhỏ hơn 2 nút con) để sắp xếp mảng theo thứ tự Giảm dần.*/

void heapifyDecrease(int *A, int n, int index){
    if (index > n) {
        return;
    }
    int left = 2*index+1, right = 2*index+2, smallest = index;
    if (left < n && A[left] < A[smallest]) {
        smallest = left;
    }
    if (right < n && A[right] < A[smallest]) {
        smallest = right;
    }
    if (smallest != index) {
        swap(A[index], A[smallest]);
        heapifyDecrease(A, n, smallest);
    }
}

void heapSortDecrease(int *A, int n){
    int theLastParent = n/2-1;
    for (int i = theLastParent; i>=0; i--) {
        heapifyDecrease(A, n, i);
    }
    for (int i = n-1; i>=0; i--) {
        swap(A[0],A[i]);
        heapifyDecrease(A, i, 0);
    }
}

/*Bài tập 3: Đếm số phép hoán đổi (Swap count)
 * Yêu cầu: * Tạo một biến toàn cục để đếm xem Heapsort tốn bao nhiêu lần gọi lệnh swap trong toàn bộ quá trình (cả lúc build heap lẫn lúc sort).
     * Chạy thử với một mảng đã bị sắp xếp ngược (ví dụ: [10, 9, 8, 7, 6]).
 * Gợi ý: Đây là cách để cậu thấy Heapsort ổn định thế nào, số lần swap của nó hiếm khi bị đột biến như Quick Sort khi gặp mảng "xui".*/

void heapifyCountSwap(int*A, int n, int index, int &countSwap){
    if (index > n) {
        return;
    }
    int left = index*2+1, right = 2*index+1, largest = index;
    if (left < n && A[left] > A[largest]) {
        largest = left;
    }
    if (right < n && A[right] > A[largest]) {
        largest = right;
    }
    if (largest != index) {
        countSwap++;
        swap(A[index], A[largest]);
        heapifyCountSwap(A, n, largest, countSwap);
    }
}

void heapSortCountSwap(int *A, int n, int &countSwap){
    int theLastParent = n/2 -1;
    for (int i = theLastParent; i>=0; i--) {
        heapifyCountSwap(A, n, i, countSwap);
    }
    for (int i = n-1; i>=0; i--) {
        heapifyCountSwap(A, i, 0, countSwap);
    }
}

/*Bài tập 4: Hàng đợi ưu tiên (Priority Queue) cho Bệnh viện
 * Yêu cầu: * Sử dụng struct Patient { string name; int age; bool isEmergency; }.
     * Dùng Heapsort để sắp xếp danh sách bệnh nhân: Ai cấp cứu (isEmergency == true) thì được lên đầu. Nếu cùng là cấp cứu (hoặc cùng không cấp cứu), ai lớn tuổi hơn sẽ được ưu tiên khám trước.
 * Câu hỏi phụ: Trong thực tế, mảng này không đứng yên mà liên tục có bệnh nhân mới chạy vào. Cậu nghĩ Heapsort có phù hợp không?*/
/*theo mình thì trong thưc tế mảng này dùng Heapsort sẽ phù hợp vì chỉ cần thêm bệnh nhân mới sẽ được sắp xếp lại theo thứ tự*/
void heapifyPatient(Patient *P,int n, int index){
    if (index > n) {
        return;
    }
    int left = 2*index+1, right = 2*index+2, Largest = index;
    if (left < n) {
        if (P[left].isEmergency && !P[Largest].isEmergency){
            Largest = left;
        }
        else if(P[left].age < P[Largest].age){
            Largest = left;
        }
    }
    if (right < n) {
        if (P[right].isEmergency && !P[Largest].isEmergency) {
            Largest = right;
        }
        else if (P[right].age < P[Largest].age){
            Largest = right;
        }
    }
    if (Largest != index) {
        swap(P[index],P[Largest]);
        heapifyPatient(P, n, Largest);
    }
}

void heapSortPatient(Patient *P, int n){
    int theLastParent = n/2-1;
    for (int i = theLastParent;i>=0;i--){
        heapifyPatient(P, n, i);
    }
    for(int i = n-1;i>=0;i--){
        swap(P[i],P[0]);
        heapifyPatient(P, i, 0);
    }
}

/*Bài tập 5: Heapsort trên mảng C-string (Mảng con trỏ)
 * Yêu cầu: * Dùng Heapsort để sắp xếp mảng char* arr[] theo thứ tự từ điển.
     * Thay vì dùng toán tử > hoặc <, hãy dùng strcmp bên trong hàm heapify để so sánh và hoán đổi địa chỉ con trỏ.*/

void heapifyCString(const char* arr[], int n, int index){
    if (index > n) {
        return;
    }
    int left = index*2+1, right = index*2+2, largest = index;
    if (left < n && strcmp(arr[left],arr[largest])>0) {
        largest = left;
    }
    if (right < n && strcmp(arr[right],arr[largest])>0) {
        largest = right;
    }
    if(largest != index){
        swap(arr[largest], arr[index]);
        heapifyCString(arr, n, largest);
    }
}
void heapSortCString(const char* arr[], int n){
    int theLastParent = n/2-1;
    for (int i = theLastParent; i>=0; i--) {
        heapifyCString(arr, n, i);
    }
    for (int i = n-1; i>=0; i--) {
        swap(arr[i],arr[0]);
        heapifyCString(arr, i, 0);
    }
}
/* Bài tập 6: Bài toán "Top K Trending" (Biến thể Heapsort)
 * Yêu cầu: * Cho mảng 1 triệu phần tử. Không cần sắp xếp toàn bộ. Hãy in ra K phần tử lớn nhất trong mảng.
 * Ứng dụng: Cậu chỉ cần buildHeap một lần, sau đó rút trích (swap gốc xuống cuối) đúng K lần rồi dừng lại. Đây là thuật toán siêu tối ưu để làm bảng xếp hạng Top Server trong Game!*/

void createRandomData(int *&A){
    A = new int[1000000];
    for (int i = 0; i<1000000; i++) {
        A[i] = rand()%10000000;
    }
}

void heapifyTopK(int*A, int n, int index){
    if (index > n) {
        return;
    }
    int left = index*2+1, right = index*2+2, largest = index;
    if (left < n && A[left] > A[largest]) {
        largest = left;
    }
    if (right < n && A[right] > A[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(A[largest], A[index]);
        heapifyTopK(A, n, largest);
    }
}

void topKTrending(int *A, int n, int k){
    int theLastParent = n/2-1;
    for (int  i = theLastParent; i>=0; i--) {
        heapifyTopK(A, n, i);
    }
    int i = n-1;
    while (k!=0) {
        cout<<"So lon: "<<A[0]<<endl;
        swap(A[0], A[i]);
        i--;
        k--;
        heapifyTopK(A, i, 0);
    }
}

/*Bài tập 7: Sắp xếp luồng dữ liệu liên tục (Streaming Data - K-th Largest)
 * Yêu cầu: * Tưởng tượng cậu đang nhận dữ liệu nhiệt độ server truyền về mỗi giây. Cậu phải luôn biết được nhiệt độ lớn thứ K trong hệ thống.
     * Gợi ý: Dùng một Min Heap có kích thước đúng bằng K. Khi có số mới chạy vào, nếu lớn hơn phần tử ở gốc của Min Heap, hãy đá gốc ra và nhét số mới vào, rồi heapify lại.*/
void heapifyMin(int* A, int n, int index){
    if (index > n) {
        return;
    }
    int left = 2*index+1, right = 2*index+2, smallest = index;
    if(left<n && A[left] < A[smallest]){
        smallest = left;
    }
    if (right < n && A[right] < A[smallest]) {
        smallest = right;
    }
    if (smallest != index) {
        swap(A[smallest], A[index]);
        heapifyMin(A, n, smallest);
    }
}
void streamingDataKLargest(int *A, int n, int k){
    int theLastParent = k/2-1;
    for (int i = theLastParent; i>=0; i--) {
        heapifyMin(A, k, i);
    }
    while (n-1>=k) {
        if (A[n-1] > A[0]) {
            A[0] = A[n-1];
            heapifyMin(A, k, 0);
        }
        n--;
    }
    for(int i = 0;i<k;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
/*Bài tập 8: K-ary Heap (Đống K-nhánh)
 * Yêu cầu: * Cây nhị phân (Binary Heap) thì 1 cha có 2 con. Bây giờ cậu hãy nâng cấp thuật toán thành Ternary Heap (1 cha có 3 con).
     * Gợi ý toán học: Viết lại công thức tìm con trái, con giữa, con phải cho nút cha ở index i. Thay đổi vòng lặp trong heapify để so sánh với cả 3 thằng con.*/
void heapifyTernaryHeap(int *A, int n, int index){
    if (index > n) {
        return;
    }
    int left = index*3+1, mid = index*3+2, right = index*3+3, largest = index;
    if (left < n && A[left] > A[largest]) {
        largest = left;
    }
    if (mid < n && A[mid] > A[largest]) {
        largest = mid;
    }
    if (right < n && A[right] > A[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(A[largest], A[index]);
        heapifyTernaryHeap(A, n, largest);
    }
}

void ternaryHeap(int *A, int n){
    int theLastParent = n/3 -1;
    for (int i = theLastParent; i>=0; i--) {
        heapifyTernaryHeap(A, n, i);
    }
    for (int i = n-1; i>=0; i--) {
        swap(A[i], A[0]);
        heapifyTernaryHeap(A, i, 0);
    }
}

/*Bài tập 9: Thuật toán Introsort (Sát thủ giấu mặt của C++)
 * Yêu cầu: * Tìm hiểu cách hàm std::sort của C++ hoạt động ở hậu trường.
     * Viết một hàm lai: Chạy Quick Sort bình thường, nhưng đếm độ sâu đệ quy. Nếu độ sâu vượt quá 2×log(n), lập tức dừng đệ quy Quick Sort và chuyển mảng đó qua cho Heapsort xử lý nốt.
 * Ứng dụng: Tránh hoàn toàn trường hợp O(n2) của Quick Sort mà vẫn giữ được tốc độ bàn thờ.*/
void heapifyIntroSort(int *A, int n, int index){
    if (index > n) {
        return;
    }
    int left = 2*index+1, right = 2*index+2, largest = index;
    if (left < n && A[left] > A[largest]){
        largest = left;
    }
    if (right < n && A[right] > A[largest]) {
        largest = right;
    }
    if (largest != index){
        swap(A[index],A[largest]);
        heapify(A, n, largest);
    }
}

void heapIntroSort(int *A, int n){
    int theLastParent = n/2 -1;
    for (int i = theLastParent; i>=0; i--) {
        heapifyIntroSort(A, n, i);
    }
    for (int i = n-1; i>=0; i--) {
        swap(A[i], A[0]);
        heapifyIntroSort(A, i, 0);
    }
}

void introSort(int *A, int left, int right, int countRecursion){
    if (left >= right) {
        return;
    }
    if (countRecursion >= 2*log((right+1))) {
        heapIntroSort(A + left, right - left +1);
        return;
    }
    int i = left, j =left -1, pivot = right;
    while (i<pivot) {
        if (A[i] < A[pivot]) {
            j++;
            swap(A[i], A[j]);
        }
        i++;
    }
    swap(A[j+1], A[pivot]);
    pivot = j+1;
    //recursion
    countRecursion++;
    introSort(A, left, pivot-1, countRecursion);
    countRecursion++;
    introSort(A, pivot+1, right, countRecursion);
}


