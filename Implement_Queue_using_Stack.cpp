/* Codestudio  Submission    (Queue Using Stack) */

/* Problem Statement: Implement a queue data structure which follows FIFO (First In First Out) property, 
using only the instances of the stack data structure. 
1. To implement means you need to complete some predefined functions, which are supported by a normal queue such that 
it can efficiently handle the given input queries which are defined below.
2. The implemented queue must support the following operations of a normal queue:
a. enQueue (data) : This function should take one argument of type integer and place the integer to the back of the queue.
b. deQueue (): This function should remove an integer from the front of the queue and also return that integer. 
If the queue is empty, it should return -1.
c. peek(): This function returns the element present in the front of the queue. If the queue is empty, it should return -1.
d. isEmpty(): This function should return true if the queue is empty and false otherwise.  */




/* Solution 1: push => Costly        (Using 2 Stacks)
Approach: Use two stacks to ensure FIFO while inserting an element in the queue.
We can make the enQueue operation costly, and perform the deQueue and all other operations in constant time. */

/* Time Complexity: O(N * Q)
where 'N' is the maximum number of elements in the stack at any time and 'Q' is the total number of queries to be performed.
The time complexities of individual operations are:
enQueue : O(N), where ‘N’ is the number of elements in the stack.
deQueue : O(1)
peek : O(1)
isEmpty : O(1)

Space Complexity: O(N)
where ‘N’ is the maximum number of elements which are in the stack at a time.  */


// class Queue {
//     stack<int> st1;
//     stack<int> st2;
    
//     public:
//     Queue() {
//         // Initialize your data structure here.
//     }

//     void enQueue(int val) {
//         // Move all elements from st1 to st2
//         while(!st1.empty()){
//             // To insert a value, first whole of the st1 is transferred to st2, then the new element is inserted in st1
//             st2.push(st1.top());
//             st1.pop();
//         }

//         // Push item into st1
//         st1.push(val);

//         // Push everything back to st1
//         while(!st2.empty()){
//             st1.push(st2.top());
//             st2.pop();
//         }
//     }

//     int deQueue() {
//         if(st1.empty()){
//             return -1;
//         }
//         int num = st1.top();
//         st1.pop();

//         return num;
//     }

//     int peek() {
//         if(st1.empty()){
//             return -1;
//         }
//         int num = st1.top();

//         return num;
//     }

//     bool isEmpty() {
//         return st1.empty();
//     }
// };



/* Solution 2: pop => Costly       (Using 2 Stacks) 
Approach: Use two stacks to ensure FIFO while removing an element in the queue.
We can make the deQueue operation costly, and perform the enQueue operation in constant time. */

/* Time Complexity: O(N * Q) 
where 'N' is the maximum number of elements in the stack at any time and 'Q' is the total number of queries to be performed.
The time complexities of individual operations are:
enQueue : O(1),
deQueue : O(N), where N is the maximum number of elements in the stack at any time.
peek : O(N), where N is the maximum number of elements in the stack at any time.
isEmpty : O(1)

Space Complexity: O(N) 
where ‘N’ is the maximum number of elements which are in the stack at a time.  */


// class Queue {
//     stack<int> st1;
//     stack<int> st2;
    
//     public:
//     Queue() {
//         // Initialize your data structure here.
//     }

//     void enQueue(int val) {
//         st1.push(val);
//     }

//     int deQueue() {
//         if(st1.empty() && st2.empty()){
//             return -1;
//         }
//         if(st2.empty()){
//             while(!st1.empty()){
//                 st2.push(st1.top());
//                 st1.pop();
//             }
//         }
//         int num = st2.top();
//         st2.pop();

//         return num;
//     }

//     int peek() {
//         if(st1.empty() && st2.empty()){
//             return -1;
//         }
//         if(st2.empty()){
//             while(!st1.empty()){
//                 st2.push(st1.top());
//                 st1.pop();
//             }
//         }
//         int num = st2.top();

//         return num;
//     }

//     bool isEmpty() {
//         return (st1.empty() && st2.empty());
//     }
// };



/* Solution 3:      (Using 1 Stack)
Approach: This approach is slightly better than the second approach because here we use only one user stack and one 
function call stack which is nothing but recursion. The logic behind this approach is very much similar to the 2nd approach, 
except that we use only one user stack for the deQueue operation. */

/* Time Complexity: O(N * Q)
where 'N' is the maximum number of elements in the stack at any time and ‘Q’ is the total number of queries to be performed.
The time complexities of individual operations are:
enQueue : O(1),
deQueue : O(N),  where ‘N’ is the maximum number of elements in the stack at any time.
peek : O(N), where ‘N’ is the maximum number of elements in the stack at any time.
isEmpty : O(1)

Space Complexity: O(N)
where ‘N’ is the maximum number of elements which are in the stack at a time.  */


// class Queue {
//     stack<int> st1;
    
//     public:
//     Queue() {
//         // Initialize your data structure here.
//     }

//     void enQueue(int val) {
//         st1.push(val);
//     }

//     int deQueue() {
//         if(st1.empty()){
//             return -1;
//         }

//         int x = st1.top();
//         st1.pop();
//         if(st1.empty()){
//             return x;
//         }
//         int item = deQueue();
//         st1.push(x);

//         return item;
//     }

//     int peek() {
//         if(st1.empty()){
//             return -1;
//         }

//         int x = st1.top();
//         st1.pop();
//         if(st1.empty()){
//             st1.push(x);
//             return x;
//         }
//         int item = peek();
//         st1.push(x);

//         return item;
//     }

//     bool isEmpty() {
//         return st1.empty();
//     }
// };



//////////////////////////////////////////////////////////////////////////////////


/* Approach 1 by using 2 Stacks */

// #include<iostream>
// #include<stack>
// using namespace std;
// class queue{
//     stack<int> s1;
//     stack<int> s2;
//     public:
//     void push(int x){                      //enqueue             //Time Complexity: O(1)
//         s1.push(x);
//     }
//     int pop(){                           //dequeue              //Time Complexity: O(N)
//         if (s1.empty() && s2.empty())
//         {
//             cout<<"No element in queue"<<endl;
//             return -1;
//         }
//         if (s2.empty())
//         {
//             while (!s1.empty())
//             {
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//         }
//         int topval = s2.top();
//         s2.pop();
//         return topval;
//     }
//     bool empty(){
//         if (s1.empty() && s2.empty())
//         {
//             return true;
//         }   
//         return false;     
//     }
// };
// int main()
// {
    // queue q;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);

    // cout<<q.pop()<<endl;
    // q.push(5);
    // cout<<q.pop()<<endl;
    // cout<<q.pop()<<endl;
    // cout<<q.pop()<<endl;
    // cout<<q.pop()<<endl;
    // cout<<q.pop()<<endl;


//     return 0;
// }



/* Approach 2 by using only 1 Stack */

// #include<iostream>
// #include<stack>
// using namespace std;
// class queue{
//     stack<int> s1;
//     public:
//     void push(int x){                      //enqueue             //Time Complexity: O(1)
//         s1.push(x);
//     }
//     int pop(){                           //dequeue              //Time Complexity: O(N)
//         if (s1.empty())
//         {
//             cout<<"No element in queue"<<endl;
//             return -1;
//         }
//         int x = s1.top();
//         s1.pop();
//         if (s1.empty())
//         {
//             return x;
//         }
//         int item = pop();
//         s1.push(x); 

//         return item;
//     }
//     bool empty(){
//         if (s1.empty())
//         {
//             return true;
//         }   
//         return false;     
//     }
// };
// int main()
// {
//     queue q;
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.push(4);   

//     cout<<q.pop()<<endl;
//     q.push(5);
//     cout<<q.pop()<<endl;
//     cout<<q.pop()<<endl;
//     cout<<q.pop()<<endl;
//     cout<<q.pop()<<endl;
//     cout<<q.pop()<<endl;


//     return 0;
// }