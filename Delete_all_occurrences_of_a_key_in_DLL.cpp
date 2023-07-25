/* Codestudio  Submission          (Delete all occurrences of a given key in a doubly linked list)  */

/* Problem Statement: A doubly-linked list is a data structure that consists of sequentially linked nodes, 
and the nodes have reference to both the previous and the next nodes in the sequence of nodes. 
You're given a doubly-linked list and a key 'K' Delete all the nodes having data equal to 'K'. */


/* Solution:  (Traverse and delete the nodes having same key)   */
// Time Complexity : O(N)
// Space Complexity : O(1)


// Node * deleteAllOccurrences(Node* head, int k) {
//     if(head == NULL){
//         return head;
//     }
    
//     Node* temp = head;
//     while(temp != NULL){
//         if(temp->data == k){
//             Node* todelete = temp;
//             if(temp->prev != NULL){
//                 temp->prev->next = temp->next;
//             }
//             if(temp->next != NULL){
//                 temp->next->prev = temp->prev;
//             }
//             if(temp == head){
//                 head = head->next;
//             }
//             temp = temp->next;
//             delete todelete;
//         }
//         else{
//             temp = temp->next;
//         }
//     }

//     return head;
// }


