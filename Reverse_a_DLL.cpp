/* Codestudio  Submission    (Reverse A Doubly Linked List) */

/* Problem Statement: You are given a doubly-linked list of size 'N', consisting of positive integers. 
Now your task is to reverse it and return the head of the modified list. */


/* Solution 1: Iterative */
// Time Complexity: O(N)
// Space Complexity: O(1) 


// Node* reverseDLL(Node* head)
// {   
//     Node* prevptr = NULL; 
//     Node* currptr = head; 
//     Node* nextptr; 
//     while(currptr != NULL){
//         nextptr = currptr->next;
//         currptr->prev = nextptr;
//         currptr->next = prevptr;

//         prevptr = currptr;
//         currptr = nextptr;
//     }

//     return prevptr;
// }



/* Solution 2: Recursive */
// Time Complexity: O(N)
// Space Complexity: O(1) 


// Node* reverseDLL(Node* head)
// {   
//     if (head == NULL || head->next == NULL){
//         return head;
//     }

//     Node* newHead = reverseDLL(head->next);

//     newHead->prev = NULL;
//     head->next->next = head;
//     head->prev = head->next;
//     head->next = NULL;

//     return newHead;
// }