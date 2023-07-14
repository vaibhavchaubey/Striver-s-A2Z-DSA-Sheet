/* Leetcode  Submission    (237. Delete Node in a Linked List) */

/* Problem Statement: There is a singly-linked list head and we want to delete a node node in it.
You are given the node to be deleted node. You will not be given access to the first node of head.
All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list. */


// Time Complexity: O(1)
// Space Complexity: O(1) 


// class Solution {
// public:
//     void deleteNode(ListNode* node) {
//         // Since we know input node is not last node, so nextNode will not be null
//         //we copy the next node’s value in the current node. Then, link current node to next of next node.
//         //also delete the next node so to escape memory leak
        
//         ListNode* temp = node->next;
//         node->val = node->next->val;
//         node->next = node->next->next;
//         delete temp;
//     }
// };




/* Codestudio  Submission    (Delete Node Of Linked List) */

/* Problem Statement: You are given the head of a linked list 'list" of size 'n'. 
Your task is to delete the linked list's last node and return the linked list's head. */


// Time Complexity: O(N)
// Space Complexity: O(1) 


// Node *deleteLast(Node *list){
//     Node* temp = list;
//     while(temp->next->next != NULL){
//         temp = temp->next;
//     }

//     Node* todelete = temp->next;
//     temp->next = NULL;
//     delete todelete;

//     return list;
// }