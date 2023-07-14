/* Codestudio  Submission    (Introduction To Linked List) */

/* Problem Statement: You are given an array 'arr' of size 'n' consisting of positive integers. 
Make a linked list from the array and return the head of the linked list. 
The head of the linked list is the first element of the array, and the tail of the linked list is the last element. */


// Time Complexity: O(N)
// Space Complexity: O(1) 


// Node* constructLL(vector<int>& arr) {
//     Node* head = new Node(arr[0]);
//     Node* temp = head;
//     for(int i = 1; i < arr.size(); i++){
//         Node* currNode = new Node(arr[i]);
//         temp->next = currNode;
//         temp = temp->next;
//     }

//     return head;
// }