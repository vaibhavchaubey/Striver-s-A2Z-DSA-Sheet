/* Codestudio  Submission    (Stack Implementation Using Array) */

/* Problem Statement: Stack is a data structure that follows the LIFO (Last in First out) principle. 
Design and implement a stack to implement the following functions: 

1. Push (num): Push the given number in the stack if the stack is not full.
2. Pop: Remove and print the top element from the stack if present, else print -1.
3. Top: Print the top element of the stack if present, else print -1.
4. isEmpty: Print 1 if the stack is empty, else print 0.
5. isFull: Print 1 if the stack is full, else print 0. */



/* Solution:  */
// Time Complexity: O(1)
// Space Complexity: O(N) 


// class Stack {
    
// public:
//     int curIdx, n;
//     vector<int> arr;
//     Stack(int capacity) {
//         arr.resize(capacity);
//         n = capacity;
//         curIdx = -1;
//     }

//     void push(int num) {
//         if(curIdx == n-1){
//             return;
//         }
//         curIdx++;
//         arr[curIdx] = num;
//     }

//     int pop() {
//         if(curIdx == -1){
//             return -1;
//         }
//         int num = arr[curIdx];
//         curIdx--;

//         return num;
//     }
    
//     int top() {
//         if(curIdx == -1){
//             return -1;
//         }
//         int num = arr[curIdx];

//         return num;
//     }
    
//     int isEmpty() {
//         return curIdx == -1;
//     }
    
//     int isFull() {
//         return curIdx == n-1;
//     }
    
// };



//////////////////////////////////////////////////////////////////////////////////


/* Array Implementation Of Stack */

// #include<iostream>
// using namespace std;
// #define n 100
// class stack{
//     int* arr;       //Here we dynamically declare an array
//     int top;

//     public:
//     stack(){
//         arr = new int[n];        //allocate memory in array
//         top = -1;   
//     }
//     void push(int x){
//         if(top==n-1){
//             cout<<"Stack Overflow"<<endl;
//             return;
//         }

//         top++;
//         arr[top] = x;
//     }
//     void pop(){
//         if(top==-1){
//             cout<<"Stack Underflow"<<endl;
//             return;
//         }

//         top--;
//     }
//     int Top(){
//         if(top==-1){
//             cout<<"No element in Stack"<<endl;
//             return -1;
//         }
//         return arr[top];
//     }

//     bool empty(){
//         return top==-1; 
//     }
// };
// int main(){
//     stack st;
//     st.push(1);                        //1 is inserted
//     st.push(2);                       //2 is inserted
//     st.push(3);                      //3 is inserted
//     cout<<st.Top()<<endl;           //3
//     st.pop();                      //3 removes
//     cout<<st.Top()<<endl;         //2
//     st.pop();                    //2 removes
//     st.pop();                   //1 removes
//     st.pop();                  // no element to pop
//     cout<<st.empty()<<endl;   //becomes empty so 1


//     return 0;
// }



/* Linked List Implementation of Stack */


// #include<iostream>
// using namespace std;                    //      1<-2<-3<-4<-5   
// class node{
// 	public:
// 	int data;
// 	node* prev;

// 	node(int val){
// 		data = val;
// 		prev = NULL;
// 	}
// };
// class stack{
// 	node* top;
// 	public:
// 	stack(){
// 		top = NULL;
// 	}

// 	void push(int x){
// 		node* n = new node(x);
// 		if (top == NULL)
// 		{
// 			top = n;
// 			return;
// 		}
// 		n->prev = top;
// 		top = n;		
// 	}

// 	void pop(){
// 		if (top == NULL)
// 		{
// 			cout<<"Stack Underflow"<<endl;
// 			return;
// 		}
// 		node* todelete = top;
// 		top = top->prev;
// 		delete todelete;		
// 	}

// 	int Top(){
// 		if (top == NULL)
// 		{
// 			cout<<"No element in Stack"<<endl;
// 			return -1;
// 		}
// 		return top->data;
// 	}

// 	bool empty(){
// 		if (top == NULL)
// 		{
// 			return true;
// 		}
// 		return false;
// 	}
// };
// int main()
// {
// 	stack st;
//     st.push(1);                        //1 is inserted
//     st.push(2);                       //2 is inserted
//     st.push(3);                      //3 is inserted
//     cout<<st.Top()<<endl;           //3
//     st.pop();                      //3 removes
//     cout<<st.Top()<<endl;         //2
//     st.pop();                    //2 removes
//     st.pop();                   //1 removes
//     st.pop();                  // no element to pop
//     cout<<st.empty()<<endl;   //becomes empty so 1

// 	return 0;
// }



/* Linked List Implementation of Stack */

 
// #include<iostream>
// using namespace std;
// class node{
// 	public:
// 	int data;
// 	node* next;                           //Here we use Doubly Linked List
// 	node* prev;

// 	node(int val){
// 		data = val;
// 		next = NULL;
// 		prev = NULL;
// 	}
// };
// class stack{
// 	node* top;
// 	public:
// 	stack(){
// 		top = NULL;
// 	}

// 	void push(int x){
// 		node* n = new node(x);
// 		if (top == NULL)
// 		{
// 			top = n;
// 			return;
// 		}
// 		top->next = n;
// 		n->prev = top;
// 		top = n;		
// 	}

// 	void pop(){
// 		if (top == NULL)
// 		{
// 			cout<<"Stack Underflow"<<endl;
// 			return;
// 		}
// 		node* todelete = top;
// 		top = top->prev;
// 		delete todelete;		
// 	}

// 	int Top(){
// 		if (top == NULL)
// 		{
// 			cout<<"No element in Stack"<<endl;
// 			return -1;
// 		}
// 		return top->data;
// 	}

// 	bool empty(){
// 		if (top == NULL)
// 		{
// 			return true;
// 		}
// 		return false;
// 	}
// };
// int main()
// {
// 	stack st;
//     st.push(1);                        //1 is inserted
//     st.push(2);                       //2 is inserted
//     st.push(3);                      //3 is inserted
//     cout<<st.Top()<<endl;           //3
//     st.pop();                      //3 removes
//     cout<<st.Top()<<endl;         //2
//     st.pop();                    //2 removes
//     st.pop();                   //1 removes
//     st.pop();                  // no element to pop
//     cout<<st.empty()<<endl;   //becomes empty so 1

// 	return 0;
// }