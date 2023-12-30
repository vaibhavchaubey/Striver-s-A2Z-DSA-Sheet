/* Leetcode  Submission          (138. Copy List with Random Pointer)  */

/* Problem Statement: A linked list of length n is given such that each node contains an additional random pointer, 
which could point to any node in the list, or null.
Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has 
its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should 
point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. 
None of the pointers in the new list should point to nodes in the original list.
For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding 
two nodes x and y in the copied list, x.random --> y.
Return the head of the copied linked list.
The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list. */



/* Solution 1: Brute Force  */ 
// Time Complexity: O(N) + O(N)              
// Space Complexity: O(N) 


// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         unordered_map<Node*, Node*> mp;

//         Node* temp = head;
//         //first iteration for inserting deep nodes of every node in the hashmap
//         while(temp != NULL){
//             Node* newNode = new Node(temp->val);
//             mp[temp] = newNode;
//             temp = temp->next;
//         }

//         temp = head;
//         //second iteration for linking next and random pointer as given question
//         while(temp != NULL){
//             Node* node = mp[temp];
//             node->next = (temp->next != NULL) ? mp[temp->next] : NULL;
//             node->random = (temp->random != NULL) ? mp[temp->random] : NULL;
//             temp = temp->next;
//         }
        
//         return mp[head];
//     }
// };




/* Solution 2: Optimized */ 
// Time Complexity: O(N) + O(N) + O(N)              
// Space Complexity: O(1) 


// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         //step 1
//         Node* temp = head;
//         while(temp != NULL){
//             Node* newNode = new Node(temp->val);
//             newNode->next = temp->next;
//             temp->next = newNode;
//             temp = temp->next->next;
//         }

//         //step 2
//         Node* itr = head;
//         while(itr != NULL){
//             if(itr->random != NULL){
//                 itr->next->random = itr->random->next;
//             }
//             itr = itr->next->next;
//         }

//         //step 3
//         Node* dummyNode = new Node(0);
//         itr = head;
//         temp = dummyNode;
//         Node* fast;
//         while(itr != NULL){
//             fast = itr->next->next;
//             temp->next = itr->next;
//             itr->next = fast;
//             temp = temp->next;
//             itr = fast;
//         }

//         return dummyNode->next;
//     }
// };



