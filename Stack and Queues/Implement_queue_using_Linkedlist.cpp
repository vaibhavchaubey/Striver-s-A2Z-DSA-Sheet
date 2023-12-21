/* Codestudio  Submission    (Implement Queue Using Linked List) */

/* Problem Statement: You are given 'q' queries, where each query can be o*
the following types:
(1) 1 x -> this means to push the element 'x' in the queue.
(2) 2 -> This means deleting the front element of the queue and returning it. If there's no element in the queue, return -1.
Your task is to implement a queue that supports these two queries.  
You must write an algorithm whose time complexity is O(1), and whose space complexity is O(1). */




/* Solution: */

// Time Complexity: O(1)
// Space Complexity: O(1) 


/**
 * Definition of linked list
 * class Node {
 * 
 * public:
 *     int data;
 *     Node* next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node* next) : data(x), next(next) {}
 * };
 * 
 * Definition of Queue
 * struct Queue {
 *   Node* front;
 *   Node* rear;
 *   void push(int);
 *   int pop();
 *   
 *   Queue() {
 *       front = rear = NULL;
 *   }
 * };
 */

// void Queue::push(int x) {
//     Node* newNode = new Node(x);
//     if(front == NULL){
//         front = newNode;
//         rear = newNode;
//         return;
//     }
//     rear->next = newNode;
//     rear = newNode;
// }

// int Queue::pop() {
//     if(front == NULL){
//         return -1;
//     }
//     int num = front->data;
//     Node* todelete = front;
//     front = front->next;
//     delete todelete;

//     return num;
// }



//////////////////////////////////////////////////////////////////////////////////


/* Linked List Implementation of Queue */


// #include<iostream>
// using namespace std;                      //    1->2->3->4->5
// class node{
//     public:
//     int data;
//     node* next;

//     node(int val){
//         data = val;
//         next = NULL;
//     }
// };
// class queue{
//     node* front;
//     node* back;
//     public:
//     queue(){
//         front = NULL;
//         back = NULL;
//     }
//     void push(int x){                   //enqueue
//         node* n = new node(x);
//         if (front == NULL)
//         {
//             back = n;
//             front = n;
//             return;
//         }
        
//         back->next = n;
//         back = n;
//     }
//     void pop(){                       //dequeue
//         if (front == NULL)
//         {
//             cout<<"Queue underflow"<<endl;
//             return;
//         }
//         node* todelete = front;
//         front = front->next;
//         delete todelete;
//     }
//     int peek(){
//         if (front == NULL)
//         {
//             cout<<"No element in queue"<<endl;
//             return -1;
//         }
//         return front->data;
//     }
//     bool empty(){
//         if (front == NULL)
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

//     cout << q.peek() << endl;
//     q.pop();

//     cout << q.peek() << endl;
//     q.pop();

//     cout << q.peek() << endl;
//     q.pop();

//     cout << q.peek() << endl;
//     q.pop();

//     cout << q.empty() << endl;

//     return 0;
// }