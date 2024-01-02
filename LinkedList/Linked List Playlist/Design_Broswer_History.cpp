/* Leetcode Submission          (1472. Design Browser History)    */

/* Problem Statement: You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.

Implement the BrowserHistory class:

    BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
    void visit(string url) Visits url from the current page. It clears up all the forward history.
    string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
    string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps. */



/* Solution: (Using Doubly LinkedList)
// Time Complexity: BrowserHistory => O(1), visit => O(1), back => O(N), forward => O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(list1 == NULL) return list2;
//         if(list2 == NULL) return list1;
//         ListNode* p1 = list1;
//         ListNode* p2 = list2;
//         ListNode* dummyNode = new ListNode(-1);
//         ListNode* p3 = dummyNode;
//         while(p1 != NULL && p2 != NULL){
//             if(p1->val < p2->val){
//                 p3->next = p1;
//                 p1 = p1->next;
//             }
//             else{
//                 p3->next = p2;
//                 p2 = p2->next;
//             }
//             p3 = p3->next;
//         }
//         if(p1 != NULL){
//             p3->next = p1;
//         }
//         else{
//             p3->next = p2;
//         }

//         return dummyNode->next;
//     }
// };


/* Solution 2: Inplace method without using extra space.

Time Complexity: O(N+M)
Let N be the number of nodes in list l1 and M be the number of nodes in list l2. We have to iterate through both lists. So, the total time complexity is O(N+M).
Space Complexity: O(1)
We are using the same lists just changing links to create our desired list. So no extra space is used. 
Hence, its space complexity is O(1).  */

// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(list1 == NULL) return list2;
//         if(list2 == NULL) return list1;
//         if(list1->val > list2->val) swap(list1,list2);
//         ListNode* res = list1;
//         while(list1 != NULL && list2 != NULL){
//             ListNode* temp = NULL;
//             while(list1 != NULL && list1->val <= list2->val){
//                 temp = list1;
//                 list1 = list1->next;
//             }
//             temp->next = list2;
//             swap(list1,list2);
//         }
        
//         return res;
//     }
// };

