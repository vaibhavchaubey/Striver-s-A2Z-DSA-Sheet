/* GFG  Submission          (Flattening a Linked List)  */

/* Problem Statement: Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of the next pointer. */



/* Solution 1: Brute Force     
Time Complexity: O(N * N * M)               // total number of nodes present
Space Complexity: O(N * N * M) */


// Node *flatten(Node *root)
// {
//    vector<int> vec;
//    Node* temp = root;
//    while(temp != NULL){
//        if(temp->bottom != NULL){
//            Node* temp1 = temp->bottom;
//            while(temp1 != NULL){
//                vec.push_back(temp1->data);
//                temp1 = temp1->bottom;
//             }
//         }
//        vec.push_back(temp->data);
//        temp = temp->next;
//    }
   
//    sort(vec.begin(), vec.end());
  
//    Node* dummyNode = new Node(0);
//    Node* curr = dummyNode;
//    for(auto it : vec){
//        curr->bottom = new Node(it);
//        curr = curr->bottom;
//    }

//    return dummyNode->bottom;
// }




/* Solution 2:
Approach: 
The idea is to use the Merge() process of merge sort for linked lists. Use merge() to merge lists one by one, 
recursively merge() the current list with the already flattened list. The down pointer is used to link nodes of the flattened list.

Time Complexity: O(N * N * M)               // total number of nodes present
where N is the no of nodes in the main linked list and M is the no of nodes in a single sub-linked list 
Explanation: As we are merging 2 lists at a time,
• After adding the first 2 lists, the time taken will be O(M+M) = O(2M).
• Then we will merge another list to above merged list -> time = O(2M + M) = O(3M).
• Then we will merge another list -> time = O(3M + M).
• We will keep merging lists to previously merged lists until all lists are merged.
• Total time taken will be O(2M + 3M + 4M + …. N*M) = (2 + 3 + 4 + … + N) * M
• Using arithmetic sum formula: time = O((N * N + N – 2) * M/2)
• The above expression is roughly equal to O(N * N * M) for a large value of N

Space Complexity: O(1) */


// Node* mergeTwoLists(Node* a, Node* b){
//     Node* dummyNode = new Node(0);
//     Node* temp = dummyNode;
//     while(a != NULL && b != NULL){
//         if(a->data < b->data){
//             temp->bottom = a;
//             a = a->bottom;
//         }
//         else{
//             temp->bottom = b;
//             b = b->bottom;
//         }
//         temp = temp->bottom;
//     }

//     if(a != NULL){
//         temp->bottom = a;
//     }
//     else{
//         temp->bottom = b;
//     }

//     return dummyNode->bottom;
// }
// Node *flatten(Node *root)
// {
//     // Base Cases
//    if(root == NULL || root->next == NULL){
//        return root;
//    }
   
//    // Recur for list on right
//    root->next = flatten(root->next);
   
//    // Now merge
//    root = mergeTwoLists(root, root->next);
   
//    // Return the root
//     // it will be in turn merged with its left
//    return root;
// }

