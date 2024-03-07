/* Codestudio  Submission    (Reverse Stack Using Recursion) */

/* Problem Statement: Reverse a given stack of 'N' integers using recursion. You are required to make 
changes in the input parameter itself.
Note: You are not allowed to use any extra space other than the internal stack space used due to recursion. */


/* Solution:  */
// Time Complexity: O(N * N)
// Space Complexity: O(N)                   // recursion stack


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