/* Codestudio  Submission    (Stack using queue) */

/* Problem Statement: Implement a Stack Data Structure specifically to store integer data using two Queues. 
There should be two data members, both being Queues to store the data internally. You may use the inbuilt Queue.
Implement the following public functions:
1. Constructor: It initializes the data members (queues) as required.
2. push (data) This function should take one argument of type integer. It pushes the element into the stack and returns nothing.
3. pop() : It pops the element from the top of the stack and, in turn, returns the element being popped or deleted. 
In case the stack is emnty. it returns -1.
4. top : It returns the element being kept at the top of the stack. In case the stack is empty, it returns -1.
5. size() : It returns the size of the stack at any given instance of time.
6. isEmpty() : It returns a boolean value indicating whether the stack is empty or not. */



/* Solution 1: Push => Costly       (Using 2 Queues) 
Approach: Try alternatively swapping elements between the two queues and make push operation costly. 
This method ensures that every new element entered in the queue ‘q1’ is always at the front. */

/* Time Complexity: O(N * Q)
where ‘N’ denotes the maximum number of elements in the queue, and ‘Q’ denotes the number of queries.
During each push operation, we transfer all the elements of ‘q1’ to ‘q2’.

Space Complexity: O(max(N1, N2))
where ‘N1' and ‘N2’ denote the size of queues ‘q1’ and ‘q2’.
We use two queues of size ‘N1’ and ‘N2’.  */


// class Stack {
// 	queue<int> q1;
//     queue<int> q2;

//    public:
//     Stack() {
//         // Implement the Constructor.
//     }

//     /*----------------- Public Functions of Stack -----------------*/

//     int getSize() {
//         return q1.size();
//     }

//     bool isEmpty() {
//         return q1.empty();
//     }

//     void push(int element) {
//         q2.push(element);
//         while(!q1.empty()){
//             q2.push(q1.front());
//             q1.pop();
//         }

//         swap(q1, q2);
//     }

//     int pop() {
//         if(q1.empty()){
//             return -1;
//         }
//         int num = q1.front();
//         q1.pop();

//         return num;
//     }

//     int top() {
//         if(q1.empty()){
//             return -1;
//         }
        
//         return q1.front();
//     }
// };



/* Solution 2: pop => Costly        (Using 2 Queues)
Approach: Try alternatively swapping elements between the two queues and make pop operation costly. */

/* Time Complexity: O(N * Q)
where ‘N’ denotes the maximum number of elements in the queue, and ‘Q’ denotes the number of queries.
During each push operation, we transfer all the elements of ‘q1’ to ‘q2’.

Space Complexity: O(max(N1, N2))
where ‘N1' and ‘N2’ denote the size of queues ‘q1’ and ‘q2’.
We use two queues of size ‘N1’ and ‘N2’.  */


// class Stack {
// 	queue<int> q1;
//     queue<int> q2;

//    public:
//     Stack() {
//         // Implement the Constructor.
//     }

//     /*----------------- Public Functions of Stack -----------------*/

//     int getSize() {
//         return q1.size();
//     }

//     bool isEmpty() {
//         return q1.empty();
//     }

//     void push(int element) {
//         q1.push(element);
//     }

//     int pop() {
//         if(q1.empty()){
//             return -1;
//         }
//         while(q1.size() != 1){
//             q2.push(q1.front());
//             q1.pop();
//         }
//         int num = q1.front();
//         q1.pop();
//         swap(q1, q2);

//         return num;
//     }

//     int top() {
//         if(q1.empty()){
//             return -1;
//         }
//         while(q1.size() != 1){
//             q2.push(q1.front());
//             q1.pop();
//         }
//         int num = q1.front();
//         q1.pop();
//         q2.push(num);
//         swap(q1, q2);

//         return num;
//     }
// };



/* Solution 3:      (Using 1 Queue)
Approach: Try alternatively swapping elements between the two queues and make pop operation costly. */

/* Time Complexity: O(N*Q)
where ‘N’ denotes the maximum number of elements in the queue, and ‘Q’ denotes the number of queries.
During each push operation, we re-transfer all the elements of ‘q1’ back to ‘q1’.

Space Complexity: O(N), where ‘N’ denotes the maximum number of elements in the queue.
We are using a queue of size ‘N’.  */


// class Stack {
// 	queue<int> q1;

//    public:
//     Stack() {
//         // Implement the Constructor.
//     }

//     /*----------------- Public Functions of Stack -----------------*/

//     int getSize() {
//         return q1.size();
//     }

//     bool isEmpty() {
//         return q1.empty();
//     }

//     void push(int element) {
//         int size = q1.size();
//         q1.push(element);

//         for(int i = 0; i < size; i++){
//             q1.push(q1.front());
//             q1.pop();
//         }
//     }

//     int pop() {
//         if(q1.empty()){
//             return -1;
//         }
//         int num = q1.front();
//         q1.pop();

//         return num;
//     }

//     int top() {
//         if(q1.empty()){
//             return -1;
//         }
        
//         return q1.front();;
//     }
// };



//////////////////////////////////////////////////////////////////////////////////


/* Push => Costly */

// #include<iostream>
// #include<queue>
// using namespace std;
// class Stack{
//     int N;
//     queue<int> q1;
//     queue<int> q2;
//     public:
//     Stack(){
//         N = 0;
//     }
//     void push(int val){
//         q2.push(val);
//         N++;
//         while(!q1.empty()){
//             q2.push(q1.front());
//             q1.pop();
//         }
//         swap(q1, q2);               //Reversing q1 & q2
//     }
//     void pop(){
//         q1.pop();
//         N--;
//     }
//     int top(){
//         return q1.front();  
//     }
//     int size(){
//         return N;
//     }
// };
// int main()
// {
//     Stack st;
//     st.push(1);
//     st.push(2);
//     st.push(3);
//     st.push(4);
//     cout<<st.top()<<endl;      //4
//     st.pop();
//     cout<<st.top()<<endl;     //3
//     st.pop();
//     cout<<st.top()<<endl;     //2
//     st.pop();
//     cout<<st.top()<<endl;    //1
//     st.pop();
//     cout<<st.size()<<endl;   //0


//     return 0;
// }



/* pop => costly */

// #include<iostream>
// #include<queue>
// using namespace std;
// class Stack{
//     int N;
//     queue<int> q1;
//     queue<int> q2;
//     public:
//     Stack(){
//         N = 0;
//     }
//     void pop(){
//         if(q1.empty()){
//             return;
//         }
//         while (q1.size() != 1)
//         {
//             q2.push(q1.front());
//             q1.pop();
//         }
//         q1.pop();
//         N--;
//         swap(q1, q2);               //Reversing q1 & q2
//     }
//     void push(int x){
//         q1.push(x);
//         N++;
//     }
//     int top(){
//         if(q1.empty()){
//             return -1;
//         }
//         while (q1.size() != 1)
//         {
//             q2.push(q1.front());
//             q1.pop();
//         }
//         int ans = q1.front();
//         q1.pop();
//         q2.push(ans);
//         swap(q1, q2);               //Reversing q1 & q2

//         return ans;
//     }
//     int size(){
//         return N;
//     }
// };
// int main()
// {
//     Stack st;
//     st.push(1);
//     st.push(2);
//     st.push(3);
//     st.push(4);
//     cout<<st.top()<<endl;            //4
//     st.pop();
//     cout<<st.top()<<endl;          //3
//     st.pop();
//     cout<<st.top()<<endl;        //2
//     st.pop();
//     cout<<st.top()<<endl;      //1
//     st.pop();
//     cout<<st.size()<<endl;   //0


//     return 0;
// }