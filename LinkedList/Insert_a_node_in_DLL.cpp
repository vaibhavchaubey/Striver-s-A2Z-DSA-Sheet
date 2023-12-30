/* Codestudio  Submission    (Insert at end of Doubly Linked List) */

/* Problem Statement: A doubly-linked list is a data structure that consists of sequentially linked nodes, 
and the nodes have reference to both the previous and the next nodes in the sequence of nodes. 
Given a doubly-linked list and a value 'k', insert a node having value 'k' at the end of the doubly linked list. */


// Time Complexity: O(N)
// Space Complexity: O(1) 


// Node * insertAtTail(Node *head, int k) {
//     Node* n = new Node(k);
//     if(head == NULL){
//         return n;
//     }
    
//     Node* temp = head;
//     while(temp->next != NULL){
//         temp = temp->next;
//     }

//     temp->next = n;
//     n->prev = temp;

//     return head;
// }