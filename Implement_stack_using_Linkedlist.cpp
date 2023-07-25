/* Codestudio  Submission    (Implement Stack With Linked List) */

/* Problem Statement: You must implement the Stack data structure using a Singly Linked List. 
Create a class named 'Stack"which supports the following operations(all in O(1) time):
getSize: Returns an integer. Gets the current size of the stack
isEmpty: Returns a boolean. Gets whether the stack is empty
push: Returns nothing. Accepts an integer. Puts that integer at the top of the stack
pop: Returns nothing. Removes the top element of the stack. It does nothing if the stack is empty.
getTop: Returns an integer. Gets the top element of the stack. Returns -1 if the stack is empty  */




/* Solution :
Approach: Usually, insertion/deletion from a linked list takes O(n) time. 
But that happens because we insert/elements anywhere from the head to the tail. What if we only do those operations at the head? */

// Time Complexity: O(1)
// Space Complexity: O(N) 


/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

// class Stack
// {
//     //Write your code here

// public:
//     Node* top;
//     int n;
//     Stack()
//     {
//         top = NULL;
//         n = 0;
//     }

//     int getSize()
//     {
//         return n;
//     }

//     bool isEmpty()
//     {
//         return n == 0;
//     }

//     void push(int data)
//     {
//         n++;
//         Node* newNode = new Node(data);
//         if(top == NULL){
//             top = newNode;
//             return;
//         }
//         newNode->next = top;
//         top = newNode;
//     }

//     void pop()
//     {
//         if(top == NULL){
//             return;
//         }
//         n--;
//         Node* todelete = top;
//         top = top->next;
//         delete todelete;
//     }

//     int getTop()
//     {
//         if(top == NULL){
//             return -1;
//         }

//         return top->data;
//     }
// };



//////////////////////////////////////////////////////////////////////////////////


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