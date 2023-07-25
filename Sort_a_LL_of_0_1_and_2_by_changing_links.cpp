/* Codestudio Submission          (Sort linked list of 0s 1s 2s)  */

/* Problem Statement: Given a linked list of 'N' nodes, where each node has an integer value that can be 0, 1, or 2. 
You need to sort the linked list in non-decreasing order and the return the head of the sorted list. */


/* Solution 1: Brute Force  */
// Time Complexity: O(N) + O(N) + O(N * logN)
// Space Complexity: O(N)


// Node* sortList(Node *head){
//     vector<int> vec;
//     Node* temp = head;
//     while(temp != NULL){
//         vec.push_back(temp->data);
//         temp = temp->next;
//     }

//     sort(vec.begin(), vec.end());
    
//     Node* dummyNode = new Node(0);
//     Node* curr = dummyNode;
//     for(int i = 0; i < vec.size(); i++){
//         curr->next = new Node(vec[i]);
//         curr = curr->next;
//     }

//     return dummyNode->next;
// }



/* Solution 2:   (Count the number of occurrences, then update the linked list)    */
/* Approach: The approach would be counting the number of occurrences of 0, 1, and 2. 
Then updating the data of the linked list in sorted order. */

// Time Complexity: O(N) + O(N)
// Space Complexity: O(1)


// Node* sortList(Node *head){
//     int zero = 0, one = 0, two = 0;
//     Node* temp = head;
//     while(temp != NULL){
//         if(temp->data == 0){
//             zero++;
//         }
//         else if(temp->data == 1){
//             one++;
//         }
//         else{
//             two++;
//         }

//         temp = temp->next;
//     }

//     temp = head;

//     while(temp != NULL){
//         if(zero != 0){
//             temp->data = 0;
//             zero--;
//         }
//         else if(one != 0){
//             temp->data = 1;
//             one--;
//         }
//         else if(two != 0){
//             temp->data = 2;
//             two--;
//         }

//         temp = temp->next;
//     }

//     return head;
// }



/* Solution 3:   (Separate each node and reconnect)    */
// Time Complexity: O(N)
// Space Complexity: O(1)


// Node* sortList(Node *head){
//     Node* zero = new Node(-1);
//     Node* zeroStart = zero;
//     Node* one = new Node(-1);
//     Node* oneStart = one;
//     Node* two = new Node(-1);
//     Node* twoStart = two;
//     Node* temp = head;

//     while(temp != NULL){
//         if(temp->data == 0){
//             zero->next = temp;
//             zero = zero->next;
//         }
//         else if(temp->data == 1){
//             one->next = temp;
//             one = one->next;
//         }
//         else{
//             two->next = temp;
//             two = two->next;
//         }

//         temp = temp->next;
//     }

//     /* Connect 0 - 1 and 1 - 2 and 2 - NULL */
//     zero->next = oneStart->next;
//     one->next = twoStart->next;
//     two->next = NULL;

//     return zeroStart->next;
// }