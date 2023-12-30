/* Codestudio  Submission    (Introduction To Doubly Linked List) */

/* Problem Statement: You are given an array 'arr' of size 'n' consisting of positive integers. 
Your task is to make a doubly linked list from the array and return the head of the linked list. 
Here the head of the doubly linked list is the first element of the array, and the tail of the doubly 
linked list is the last element. */


// Time Complexity: O(N)
// Space Complexity: O(1) 


// Node* constructDLL(vector<int>& arr) {
//     Node* head = new Node(arr[0]);
//     Node* temp = head;
//     for(int i = 1; i < arr.size(); i++){
//         Node* currNode = new Node(arr[i]);
//         temp->next = currNode;
//         currNode->prev = temp;
//         temp = temp->next;
//     }

//     return head;
// }