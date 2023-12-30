/* Codestudio  Submission    (Delete Last Node of a Doubly Linked List) */

/* Problem Statement: A doubly-linked list is a data structure that consists of sequentially linked nodes, 
and the nodes have reference to both the previous and the next nodes in the sequence of nodes. Given a doubly-linked list, 
delete the node at the end of the doubly linked list. */


// Time Complexity: O(N)
// Space Complexity: O(1) 


// Node * deleteLastNode(Node *head) {
//     if(head == NULL){
//         return NULL;
//     }
//     if(head->next == NULL){
//         delete head;
//         return NULL;
//     }
    
//     Node* temp = head;
//     while(temp->next != NULL){
//         temp = temp->next;
//     }

//     Node* todelete = temp;
//     temp = temp->prev;
//     temp->next = NULL;

//     delete todelete;

//     return head;
// }