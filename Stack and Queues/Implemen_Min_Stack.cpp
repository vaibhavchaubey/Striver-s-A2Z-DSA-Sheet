/* Leetcode  Submission    (155. Min Stack) */

/* Problem Statement: Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function. */



/* Solution: */
// Time Complexity: O(N)
// Space Complexity: O(2N) 


// class MinStack {
// public:
//     stack<pair<int, int>> st;                    // val, minEle
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         int minEle;
//         if(st.empty()){
//             minEle = val;
//         }
//         else{
//             minEle = min(st.top().second, val);
//         }

//         st.push({val, minEle});
//     }
    
//     void pop() {
//         st.pop();
//     }
    
//     int top() {
//         return st.top().first;
//     }
    
//     int getMin() {
//         return st.top().second;
//     }
// };




/* Codestudio  Submission    (Min Stack) */

/* Problem Statement: Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
1. Push (num): Push the given number in the stack.
2. Pop: Remove and return the top element from the stack if present, else return -1.
3. Top: return the top element of the stack if present, else return -1.
4. getMin: Returns minimum element of the stack if present, else return -1. */



/* Solution: */
// Time Complexity: O(N)
// Space Complexity: O(2N) 


// #include <bits/stdc++.h>
// // Implement class for minStack.
// class minStack
// {
// 	stack<pair<int, int>> st;	       // val, minEle
	
// 	public:
		
// 		// Constructor
// 		minStack() 
// 		{ 
		
// 		}
		
// 		// Function to add another element equal to num at the top of stack.
// 		void push(int num)
// 		{
// 			int minEle;
// 			if(st.empty()){
// 				minEle = num;
// 			}
// 			else{
// 				minEle = min(st.top().second, num);
// 			}

// 			st.push({num, minEle});
// 		}
		
// 		// Function to remove the top element of the stack.
// 		int pop()
// 		{
// 			if(st.empty()){
// 				return -1;
// 			}
// 			int num = st.top().first;
// 			st.pop();

// 			return num;
// 		}
		
// 		// Function to return the top element of stack if it is present. Otherwise return -1.
// 		int top()
// 		{
// 			if(st.empty()){
// 				return -1;
// 			}
// 			int num = st.top().first;

// 			return num;
// 		}
		
// 		// Function to return minimum element of stack if it is present. Otherwise return -1.
// 		int getMin()
// 		{
// 			if(st.empty()){
// 				return -1;
// 			}
// 			int num = st.top().second;

// 			return num;
// 		}
// };