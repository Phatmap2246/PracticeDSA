//
//  StackAndQueue.cpp
//  PracticeDSA
//
//  Created by Nguyen Duc Phat on 14/4/26.
//

#include "StackAndQueue.hpp"
#include <iostream>
using namespace ::std;
// stack and queue
/*Bài tập 1: Stack bằng Mảng (Array-based Stack)
 * Yêu cầu: Viết một struct Stack sử dụng mảng tĩnh int arr[100] và một biến int top (chỉ số của phần tử trên cùng, ban đầu top = -1).
 * Các hàm cần viết: push(x) (thêm vào đỉnh), pop() (lấy ra khỏi đỉnh), peek() (xem giá trị đỉnh mà không lấy ra), và isEmpty().*/
Node1* createNode1(int x){
    Node1* theNewNode = new Node1();
    if (!theNewNode) {
        cout<<"Cannot create a new Node!"<<endl;
        return nullptr;
    }
    theNewNode->data = x;
    theNewNode->next = nullptr;
    return theNewNode;
}
void push(Stack &s, int x){
    Node1* theNewNode = createNode1(x);
    theNewNode->next = s.top;
    s.top = theNewNode;
}

int pop(Stack &s){
    if (!s.top) {
        cout<<"The Stack is NULL!"<<endl;
        return INT_MIN;
    }
    int poppedValue = s.top->data;
    Node1* bucket = s.top;
    s.top = s.top->next;
    bucket->next = nullptr;
    delete bucket;
    bucket = nullptr;
    return poppedValue;
}
int peek(Stack &s){
    if (!s.top) {
        cout<<"The Stack is NULL !"<<endl;
        return INT_MIN;
    }
    return s.top->data;
}

bool isEmpty(Stack s){
    if (!s.top) {
        return true;
    }
    return false;
}


/*Bài tập 2: Queue bằng Linked List (Linked List-based Queue)
 * Yêu cầu: Cậu đã rành Linked List rồi, hãy áp dụng nó! Viết struct Queue quản lý bằng 2 con trỏ front (đầu) và rear (cuối).
 * Các hàm cần viết: enqueue(x) (thêm vào sau rear), dequeue() (lấy ra từ front), và isEmpty().
*/

void enqueue(Queue &q, int x){
    Node1* theNewNode = createNode1(x);
    if (!q.front && !q.rear) {
        q.front = q.rear = theNewNode;
        return;
    }
    q.rear->next = theNewNode;
    q.rear = theNewNode;
}

int dequeue(Queue &q){
    if (!q.front) {
        cout<<"The Queue is NULL"<<endl;
        return INT_MIN;
    }
    int select = q.front->data;
    Node1* bucket = q.front;
    q.front = q.front->next;
    delete bucket;
    bucket = nullptr;
    return select;
}

bool isEmptyQ(Queue q){
    if (!q.front) {
        return true;
    }
    return false;
}

/*Bài tập 3: Cỗ máy đảo ngược (Reverse String)
 * Yêu cầu: Cho một chuỗi ký tự (ví dụ: "HELLO"). Hãy dùng Stack để đảo ngược chuỗi này thành "OLLEH".
 * Gợi ý: Cứ push từng chữ cái vào Stack. Sau đó pop liên tục ra. Tính chất "Vào sau ra trước" sẽ tự động lật ngược chuỗi cho cậu!*/
nodeChar* createCharNode(char data){
    nodeChar* theNewNode = new nodeChar();
    if (!theNewNode) {
        cout<<"Cannot create a new CharNode !"<<endl;
        return nullptr;
    }
    theNewNode->data = data;
    theNewNode->next = nullptr;
    return theNewNode;
}
void pushString(charStack &st, char data){
    nodeChar* theNewNode = createCharNode(data);
    theNewNode->next = st.top;
    st.top = theNewNode;
}
char popString(charStack &st){
    if (!st.top) {
        return '\0';
    }
    char bucket = st.top->data;
    nodeChar* prev = st.top;
    st.top = st.top->next;
    delete prev;
    prev = nullptr;
    return bucket;
}
bool isEmptString(charStack &st){
    if (!st.top) {
        return true;
    }
    return false;
}
void reverseString(string data){
    charStack st;
    st.top = nullptr;
    for (int i = 0; i<data.length(); i++) {
        pushString(st, data[i]);
    }
    while (!isEmptString(st)) {
        cout<<popString(st)<<" ";
    }
    cout<<endl;
}
/*Bài tập 4: Bài toán kinh điển - Kiểm tra ngoặc hợp lệ (Valid Parentheses)
 * Yêu cầu: Cho một chuỗi chỉ chứa các dấu ngoặc (), {}, []. Kiểm tra xem nó có hợp lệ không (mở ngoặc nào thì phải đóng đúng loại ngoặc đó theo đúng thứ tự). Ví dụ: ({[]}) là Đúng, ({[}]) là Sai.
 * Gợi ý: Gặp ngoặc mở thì push vào Stack. Gặp ngoặc đóng thì pop thằng trên cùng của Stack ra xem có khớp thành một cặp không. (Bài này có trên LeetCode, cực kỳ hay hỏi khi phỏng vấn!).*/
bool vaidParentheses(string data){
    charStack st;
    st.top = nullptr;
    char bucket;
    for (int i = 0; i<data.length(); i++) {
        if (data[i] == '[' || data[i] =='(' || data[i] == '{') {
            pushString(st, data[i]);
        }
        else if (data[i] == ']' || data[i] == ')' || data[i] == '}'){
            bucket = popString(st);
            if (bucket != data[i]) {
                return false;
            }
        }
    }
    return true;
}
/*Bài tập 5: Chuyển đổi cơ số (Decimal to Binary)
 * Yêu cầu: Nhập một số nguyên dương N. Dùng Stack để in ra dạng nhị phân của số đó.
 * Gợi ý: Chia liên tiếp N cho 2, lấy phần dư push vào Stack. Khi chia xong, pop toàn bộ Stack ra sẽ được chuỗi nhị phân chuẩn xác.*/

void changeDecToBin(int n){
    Stack st;
    st.top = nullptr;
    int Remainder = -1;
    while (n>0) {
        Remainder = n%2;
        push(st, Remainder);
        n = n /2;
    }
    while (!isEmpty(st)) {
        cout<<pop(st);
    }
    cout<<endl;
    delete st.top;
}

/*Bài tập 6: Mô phỏng hàng đợi mua vé
 * Yêu cầu: Có N người xếp hàng (mỗi người có một cái tên). Viết chương trình mô phỏng:
     * Nhập tên người mới vào cuối hàng.
     * Gọi tên người ở đầu hàng ra mua vé.
     * In ra danh sách những người còn đang đứng đợi.*/

Line* createLine(string name){
    Line* theNewLine = new Line();
    theNewLine->name = name;
    theNewLine->next = nullptr;
    return theNewLine;
}
void enqueueLine(lineQueue &lq, string name){
    Line* theNewLine = createLine(name);
    if (!lq.front) {
        lq.front = lq.rear = theNewLine;
        return;
    }
    lq.rear->next = theNewLine;
    lq.rear = theNewLine;
}
string dequeueLine(lineQueue &lq){
    if (!lq.front) {
        return "NULL";
    }
    string bucket = lq.front->name;
    Line* select = lq.front;
    lq.front = lq.front->next;
    delete select;
    select = nullptr;
    return bucket;
}
void printLine(lineQueue lq){
    if (!lq.front) {
        cout<<"The Line is NULL"<<endl;
        return;
    }
    while (lq.front) {
        cout<<"Name: "<<lq.front->name<<endl;
        lq.front = lq.front->next;
    }
}


/*Bài tập 7: Máy phát số Nhị phân (Generate Binary Numbers)
 * Yêu cầu: Dùng Queue để tạo và in ra N số nhị phân đầu tiên (từ 1 đến N).
 * Gợi ý cực mạnh: Bắt đầu bằng việc enqueue("1"). Trong vòng lặp N lần:
     * Lấy thằng đầu Queue ra (dequeue), in nó ra.
     * Thêm "0" vào đuôi thằng vừa lấy rồi enqueue lại.
     * Thêm "1" vào đuôi thằng vừa lấy rồi enqueue lại.*/

void createBinaryNumbers(int n){
    lineQueue lq;
    lq.front = nullptr;
    lq.rear = nullptr;
    enqueueLine(lq, "1");
    string bucket ="";
    string left ="";
    string right="";
    int i =1;
    while (i<n/2) {
        left ="";
        right="";
        bucket = dequeueLine(lq);
        cout<<bucket;
        left = bucket+"0";
        right = bucket+"1";
        enqueueLine(lq, left);
        enqueueLine(lq, right);
        i++;
    }
    while (i<=n) {
        bucket = dequeueLine(lq);
        cout<<bucket;
        i++;
    }
    cout<<endl;
}
