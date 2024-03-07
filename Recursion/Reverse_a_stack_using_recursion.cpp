/* Codestudio  Submission    (Reverse Stack Using Recursion) */

/* Problem Statement: Reverse a given stack of 'N' integers using recursion. You are required to make 
changes in the input parameter itself.
Note: You are not allowed to use any extra space other than the internal stack space used due to recursion. */


/* Solution:  */
// Time Complexity: O(N * N)
// Space Complexity: O(N)                   // recursion stack


// void insertAtBottom(stack<int> &stack, int ele){
//     if(stack.empty()){
//         stack.push(ele);
//         return;
//     }

//     int top = stack.top();
//     stack.pop();

//     // Recursively call insertAtBottom to insert the element at the bottom
//     insertAtBottom(stack, ele);

//     // Push the removed top element back onto the stack
//     stack.push(top);
// }
// void reverseStack(stack<int> &stack) {
//     if(stack.empty()){
//         return;
//     }
    
//     int top = stack.top();
//     stack.pop();

//     // Recursively call reverseStack to reverse the remaining elements
//     reverseStack(stack);
//     // After reversing the remaining elements, insert the removed top element at the bottom
//     insertAtBottom(stack, top);
// }