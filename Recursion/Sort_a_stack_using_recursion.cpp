/* Codestudio  Submission    (Sort Stack) */

/* Problem Statement: You are given a stack ‘S’. Your task is to sort the sack recursively.
Note:
Looping through the stack is not allowed.
You need to return a stack that is sorted in descending order.
For example:
Given stack S = 1 3 2 
The output will be 3 2 1 since it is the sorted order. */


/* Solution:  */
/* Approach: The main idea is to remove the elements recursively from the stack until the stack becomes empty and then insert 
those values (from the call-stack  [A call-stack is the stack that is made in the memory when recursive-calls are made. ]), 
back into the stack in a sorted position.

    In each call, remove the top element from the stack.
    Make a recursive call to the function sortStack.
    After the call, insert the element in the stack in a sorted fashion.
    This can be done by removing the top element from the stack until the topmost element is greater than the current element 
    that we want to insert. 
*/

// Time Complexity: O(N * N)
// Space Complexity: O(N)


// #include <bits/stdc++.h> 
// void sortedInsert(stack<int> &s, int key){
// 	if(s.empty() || key > s.top()){
// 		s.push(key);
// 		return;
// 	}

// 	int top = s.top();
// 	s.pop();

// 	// Recur for the remaining elements in the stack.
// 	sortedInsert(s, key);

// 	// Insert the popped element back into the stack
// 	s.push(top);
// }
// void sortStackHelper(stack<int> &s){
// 	if(s.empty()){
// 		return;
// 	}

// 	int top = s.top();
// 	s.pop();
	
// 	// Recur for the remaining elements in the stack.
// 	sortStackHelper(s);

// 	// Insert the popped element back into the sorted s.
// 	sortedInsert(s, top);
// }
// stack<int> sortStack(stack<int> &s)
// {
// 	sortStackHelper(s);

// 	return s;
// }