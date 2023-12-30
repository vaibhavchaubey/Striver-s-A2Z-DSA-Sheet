/* Codestudio Submission          (Add one to a number represented as Linked List)  */

/* Problem Statement: You're given a positive integer represented in the form of a singly linked-list of digits. 
The length of the number is 'n' Add 1 to the number, i.e., increment the given number by one. 
The digits are stored such that the most significant digit is at the head of the linked list and the least significant 
digit is at the tail of the linked list. */


/* Solution 1:  (Try to reach the last node of the linked list using recursion)   */
/* Approach: In this approach, we will use recursion to add 1 to the linked list. We can recursively reach the last node, 
add 1 to it and forward the carry to the previous node. 
This solution does not require reversing the linked list.  */

// Time Complexity: O(N) 
// Space Complexity: O(N)       (Recursion)


// int helper(Node* head){
//     // If linked list is empty, return carry
//     if(head == NULL){
//         return 1;
//     }
    
//     // Add carry obtained from next node to current node data
//     int res = head->data + helper(head->next);

//     // Update data and return new carry(to add to the previous node)
//     head->data = res % 10;
    
//     return res/10;      // carry 
// }
// Node *addOne(Node *head)
// {
//     // Add 1 to linked list from end to beginning
//     int carry = helper(head);

//     // If there is carry after processing all nodes,add a new node at the beginning of the linked list.
//     if(carry != 0){
//         Node* newHead = new Node(0);
//         newHead->data = carry;
//         newHead->next = head;

//         return newHead;
//     }
    
//     return head;
// }



/* Solution 2: */
/* Approach: Reversing the given linked list and then add 1 to the first node of the reversed list. */

// Time Complexity: O(N) + O(N) + O(N)              (reverse, iteration, reverse)
// Space Complexity: O(1)


// Node* reverse(Node* head){
//     Node* prevptr = NULL;
//     Node* currptr = head;
//     Node* nextptr;
//     while(currptr != NULL){
//         nextptr = currptr->next;
//         currptr->next = prevptr;

//         prevptr = currptr;
//         currptr = nextptr;
//     }

//     return prevptr;
// }
// Node *addOne(Node *head)
// {
//     if(head == NULL){
//         return new Node(1);
//     }
    
//     head = reverse(head);
//     Node* temp = head;
//     int carry = 1;
//     Node* prev = head;
//     while(head != NULL){
//         int sum = carry + head->data;
//         carry = sum/10;
//         sum = sum % 10;
//         head->data = sum;
//         prev = head;
//         head = head->next;
//     }
    
//     if(carry != 0){
//         Node* newNode = new Node(carry);
//         prev->next = newNode;
//     }

//     Node* ans = reverse(temp);
    
//     return ans;
// }

