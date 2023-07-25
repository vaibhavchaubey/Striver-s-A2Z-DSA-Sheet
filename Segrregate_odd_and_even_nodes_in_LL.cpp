/* Leetcode Submission          (328. Odd Even Linked List)  */

/* Problem Statement: Given the head of a singly linked list, group all the nodes with odd indices together followed 
by the nodes with even indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.
You must solve the problem in O(1) extra space complexity and O(n) time complexity. */


/* Solution: */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     ListNode* oddEvenList(ListNode* head) {
//         if(head == NULL || head->next == NULL){
//             return head;
//         }
        
//         ListNode* odd = head;
//         ListNode* even = head->next;
//         ListNode* evenStart = even;
//         while(odd->next!=NULL && even->next!=NULL){
//             odd->next = even->next;
//             odd = odd->next;
//             even->next = odd->next;
//             even = even->next;
//         }
//         odd->next = evenStart;
        
//         return head;
//     }
// };



/* Codestudio Submission          (Segregate Even And Odd Nodes In a Linked List)  */

/* Problem Statement: You are given the head node of a singly linked list 'head' Your task is to modify the linked list 
in such a way that all the even valued nodes appear before the all odd valued node and order of nodes remain the same. */


/* Solution: */
// Time Complexity: O(N)
// Space Complexity: O(1)


// Node* segregateEvenOdd(Node* head)
// {
//     if(head == NULL || head->next == NULL){
//         return head;
//     }

//     Node* even = new Node(-1);
//     Node* evenStart = even;
//     Node* odd = new Node(-1);
//     Node* oddStart = odd;
//     Node* temp = head;
//     while(temp != NULL){
//         if(temp->data % 2 == 0){
//             even->next = temp;
//             even = even->next;
//         }
//         else{
//             odd->next = temp;
//             odd = odd->next;
//         }
//         temp = temp->next;
//     }

//     even->next = oddStart->next;
//     odd->next = NULL;

//     return evenStart->next;
// }
