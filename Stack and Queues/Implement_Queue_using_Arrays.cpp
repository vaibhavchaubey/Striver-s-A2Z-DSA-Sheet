/* Codestudio  Submission    (Implement Queue using Arrays) */

/* Problem Statement: Queue is a linear data structure that follows the idea of First In First Out. 
That means insertion and retrieval operations happen at opposite ends.
Implement a simple queue using arrays.
You are given 'query' queries which are either of the 2 types:
1 'e': Enqueue (add) element 'e' at the end of the queue.
2: Dequeue (retrieve) the element from the front of the queue. If the queue is empty, return - 1. */



/* Solution:  */
// Time Complexity: O(1)
// Space Complexity: O(N) 


// class Queue {

// 	int front, rear, n;
// 	vector<int> arr;

// public:
// 	Queue()
// 	{
// 		front = -1;
// 		rear = -1;
// 		arr.resize(100001);
// 		n = 100001;
// 	}

// 	// Enqueue (add) element 'e' at the end of the queue.
// 	void enqueue(int e)
// 	{
// 		if(rear == n-1){
// 			return;
// 		}
// 		rear++;
// 		arr[rear] = e;
// 		if(front == -1){
// 			front++;
// 		}
// 	}

// 	// Dequeue (retrieve) the element from the front of the queue.
// 	int dequeue()
// 	{
// 		if(front == -1 || front > rear){
// 			return -1;
// 		}
// 		int num = arr[front];
// 		front++;
		
// 		return num;
// 	}
// };



//////////////////////////////////////////////////////////////////////////////////


/* Using Array */

// #include <iostream>
// #define n 20
// using namespace std;
// class queue
// {
//     int *arr;
//     int front;
//     int back;

// public:
//     queue()
//     {
//         arr = new int[n];
//         front = -1;
//         back = -1;
//     }
//     void push(int x)                  //enqueue
//     {
//         if (back == n - 1)
//         {
//             cout << "Queue Overflow" << endl;
//             return;
//         }
//         back++;
//         arr[back] = x;

//         if (front == -1)
//         {
//             front++;
//         }
//     }
//     void pop()                            //dequeue
//     {
//         if (front == -1 || front > back)
//         {
//             cout << "No element in queue" << endl;
//             return;
//         }
//         front++;
//     }
//     int peek()                             //top
//     {
//         if (front == -1 || front > back)
//         {
//             cout << "No element in queue" << endl;
//             return -1;
//         }
//         return arr[front];
//     }
//     bool empty()
//     {
//         if (front == -1 || front > back)
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
