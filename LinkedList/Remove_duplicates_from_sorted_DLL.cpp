/* Codestudio  Submission          (Remove duplicates from a sorted Doubly Linked List)  */

/* Problem Statement: A doubly-linked list is a data structure that consists of sequentially linked nodes, 
and the nodes have reference to both the previous and the next nodes in the sequence of nodes. 
You are given a sorted doubly linked list of size 'n' Remove all the duplicate nodes present in the linked list. */


/* Solution 1: */
/* Approach: If the next element is the same as the current one, try adjusting the links to remove the next element */
// Time Complexity : O(N)
// Space Complexity : O(1)


// Node * removeDuplicates(Node *head)
// {
//     if(head == NULL){
//         return head;
//     }

//     Node* temp = head;
//     while(temp->next != NULL){
//         if(temp->data == temp->next->data){
//             Node* todelete = temp->next;
//             if(todelete->prev != NULL){
//                 todelete->prev->next = todelete->next;
//             }
//             if(todelete->next != NULL){
//                 todelete->next->prev = todelete->prev;
//             }
            
//             delete todelete;
//         }
//         else{
//             temp = temp->next;
//         }
//     }

//     return head;
// }


