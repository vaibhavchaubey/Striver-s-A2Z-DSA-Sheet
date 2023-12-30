/* Codestudio  Submission    (Find length of Loop) */

/* Problem Statement: You're given a linked list. The last node might point to null, or it might point to a node in the list, 
thus forming a cycle. Find out whether the linked list has a cycle or not, and the length of the cycle if it does. 
If there is no cycle, return 0, otherwise return the length of the cycle. */


/* Solution:  (Floyd’s Cycle detection algorithm)   (Tortoise-Hare-Approach)   (Slow and Fast Pointer Method)  */
// Time Complexity: O(N)
// Space Complexity: O(1) 


// int lengthOfLoop(Node *head) {
//     Node* slow = head;
//     Node* fast = head;
//     int len = 0;

//     while(fast != NULL && fast->next != NULL){
//         slow = slow->next;
//         fast = fast->next->next;
//         if(slow == fast){
//             len++;
//             slow = slow->next;
//             while(slow != fast){
//                 len++;
//                 slow = slow->next;
//             }

//             return len;
//         }
//     }

//     return 0;
// }