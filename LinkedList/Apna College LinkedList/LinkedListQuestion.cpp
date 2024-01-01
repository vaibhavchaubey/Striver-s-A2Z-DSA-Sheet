/* 1) oddEvenList       (328. Odd Even Linked List) */

// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     ListNode* oddEvenList(ListNode* head) {
//         if(head == NULL || head->next==NULL){
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




/* 2) MiddleNode      (876. Middle of the Linked List) */

// Time Complexity: O(N/2) ~ O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         if(head == NULL || head->next == NULL){
//             return head;
//         }
//         ListNode* slow = head;
//         ListNode* fast = head;
//         while(fast != NULL && fast->next != NULL){
//             slow = slow->next;
//             fast = fast->next->next;
//         }
        
//         return slow;
//     }
// };




/* 3) DeleteNode      (237. Delete Node in a Linked List) */

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




/* 4) Palindrome            (234. Palindrome Linked List) */

/* Solution 1: */
// Time Complexity: O(N)
// Space Complexity: O(N)


// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         vector<int> vec;
//         ListNode* temp = head;
//         while(temp != NULL){
//             vec.push_back(temp->val);
//             temp = temp->next;
//         }

//         int n = vec.size();
//         for(int i = 0; i < n/2; i++){
//             if(vec[i] != vec[n-i-1]){
//                 return false;
//             }
//         }

//         return true;
//     }
// };



/* Solution 2:  (Slow and Fast Pointer Method)  */
// Time Complexity: O(N/2) + O(N/2) + O(N/2) ~ O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     ListNode* reverse(ListNode* head){
//         ListNode* prevptr = NULL;
//         ListNode* currptr = head;
//         ListNode* nextptr;
//         while(currptr!=NULL){
//             nextptr = currptr->next;
//             currptr->next = prevptr;
//             prevptr = currptr;
//             currptr = nextptr;
//         }
//         return prevptr;
//     }
//     bool isPalindrome(ListNode* head) {
//         if(head == NULL || head->next == NULL){
//             return true;
//         }

//         // STEP 1: Find the middle element
//         ListNode* slow = head;
//         ListNode* fast = head;
//         while(fast!=NULL && fast->next!=NULL){
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         // STEP 2: Reverse the end half
//         slow = reverse(slow);

//         // STEP 3: Compare the start half and end half if found any inequality then return false otherwise return true.
        
//         fast = head;
//         while(slow!=NULL && fast!=NULL){
//             if(slow->val != fast->val){
//                 return false;
//             }
//             slow = slow->next;
//             fast = fast->next;
//         }

//         return true;
//     }
// };




/* 5) Swap Nodes in Pairs         (24. Swap Nodes in Pairs) */


/* Method 1  (Recursive Method)  */

// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         if(head == NULL || head->next == NULL){
//             return head;
//         }

//         ListNode* temp;
//         temp = head->next;
//         head->next = swapPairs(head->next->next);
//         temp->next = head;
        
//         return temp;
//     }
// };




/* Method 2  (Iterative Method)  */

// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         if(head==NULL || head->next==NULL){
//             return head;
//         }
//         int k = 2;
//         ListNode* prevptr = NULL;
//         ListNode* currptr = head;
//         ListNode* nextptr;
//         int count = 0;
//         while(currptr!=NULL && count<k){
//             nextptr = currptr->next;
//             currptr->next = prevptr;

//             prevptr = currptr;
//             currptr = nextptr;
//             count++;
//         }

//         if(nextptr!=NULL){
//             head->next = swapPairs(nextptr);
//         }

//         return prevptr;
//     }
// };




/* 6) Remove Nth Node From End of List       (19. Remove Nth Node From End of List) */


/* Solution 1: */
// Time Complexity: O(N) + O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     int length(ListNode* head){
//         int l=0;
//         ListNode* temp = head;
//         while (temp!=NULL){
//             l++;
//             temp = temp->next;
//         }
//         return l;
//     }
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int l = length(head);
//         int pos = l-n+1;
//         if(pos==1){
//             return head->next;
//         }

//         ListNode* temp = head;
//         int count = 1;
//         while(count!=pos-1){
//             temp = temp->next;
//             count++;
//         }
//         ListNode* todelete = temp->next;
//         temp->next = temp->next->next;
//         delete todelete;
        
//         return head;
//     }
// };



/* Solution 2: */
// Time Complexity: O(N)
// Space Complexity: O(1)


// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* start = new ListNode(0);
//         start->next = head;
//         ListNode* slow = start;
//         ListNode* fast = start;
        
//         for(int i = 1; i <= n; i++){
//             fast = fast->next;
//         }
        
//         while(fast->next != NULL){
//             slow = slow->next;
//             fast = fast->next;
//         }
//         ListNode* todelete = slow->next;
//         slow->next= slow->next->next;
//         delete todelete;
        
//         return start->next;
//     }
// };




/* 7) Add Two Numbers        (2. Add Two Numbers) */


// Time Complexity : O(max(l1,l2))
// Space Complexity : O(max(l1,l2))


// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* dummyNode = new ListNode(0);
//         ListNode* curr = dummyNode;
//         int carry = 0;
//         while(l1 != NULL || l2 != NULL || carry != 0){
//             int sum = 0;
//             if(l1 != NULL){
//                 sum += l1->val;
//                 l1 = l1->next;
//             }
//             if(l2 != NULL){
//                 sum += l2->val;
//                 l2 = l2->next;
//             }
//             sum += carry;
//             carry = sum/10;                           //if 9+9=18 it will give 1
//             curr->next = new ListNode(sum % 10);     //if 9+9=18 it will give 8
//             curr = curr->next;
//         }

//         return dummyNode->next;
//     }
// };



/* 8) Add Two Numbers II       (445. Add Two Numbers II) */

// Time Complexity : O(m+n)
// Space Complexity : O(m+n)
// Here, m and n are is the number of nodes in l1 and l2 respectively


// class Solution {
// public:
//     ListNode* reverse(ListNode* l){
//         ListNode* prevptr = NULL;
//         ListNode* currptr = l;
//         ListNode* nextptr;
//         while(currptr != NULL){
//             nextptr = currptr->next;
//             currptr->next = prevptr;
//             prevptr = currptr;
//             currptr = nextptr;
//         }
//         return prevptr;
//     }
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* dummyHead = new ListNode(0);
//         ListNode* p = reverse(l1); 
//         ListNode* q = reverse(l2); 
//         ListNode* curr = dummyHead;
//         int carry = 0;
//         while(p != NULL || q != NULL || carry != 0){
//             int sum = 0;
//             if(p != NULL){
//                 sum += p->val;
//                 p = p->next;
//             }
//             if(q != NULL){
//                 sum += q->val;
//                 q = q->next;
//             }
//             sum += carry;
//             carry = sum/10;                           //if 9+9=18 it will give 1
//             curr->next = new ListNode(sum % 10);     //if 9+9=18 it will give 8
//             curr = curr->next;
//         }

//         ListNode* ptr = reverse(dummyHead->next);
        
//         return ptr;
//     }
// };




//9)Sort List                (148. Sort List)

/* Solution 1: */
// Time Complexity: O(N) + O(N) + O(N * logN)
// Space Complexity: O(N)


// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         vector<int> vec;
//         ListNode* temp = head;
//         while(temp != NULL){
//             vec.push_back(temp->val);
//             temp = temp->next;
//         }

//         sort(vec.begin(), vec.end());
        
//         ListNode* dummyNode = new ListNode(0);
//         ListNode* curr = dummyNode;
//         for(int i = 0; i < vec.size(); i++){
//             curr->next = new ListNode(vec[i]);
//             curr = curr->next;
//         }

//         return dummyNode->next;
//     }
// };



/* Solution 2:   (using merge sort) */
// Time Complexity: O(N * logN)
// Space Complexity: O(N)


// class Solution {
// public:
//     ListNode* merge(ListNode* list1, ListNode* list2){
//         ListNode* dummyHead = new ListNode(0);
//         ListNode* ptr = dummyHead;
//         while(list1!=NULL && list2!=NULL){
//             if(list1->val < list2->val){
//                 ptr->next = list1;
//                 list1 = list1->next;
//             }
//             else{
//                 ptr->next = list2;
//                 list2 = list2->next;
//             }
//             ptr = ptr->next;
//         }
//         if(list1 != NULL){
//             ptr->next = list1;
//         }
//         else{
//             ptr->next = list2;
//         }
        
//         return dummyHead->next;
//     }
//     ListNode* getMid(ListNode* head){
//         ListNode* slow = head;
//         ListNode* fast = head;
//         while(fast->next!=NULL && fast->next->next!=NULL){
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         ListNode* mid = slow->next;
//         slow->next = nullptr;
//         return mid;
//     }
//     ListNode* sortList(ListNode* head) {
//         if(head == NULL || head->next == NULL){
//             return head;
//         }
        
//         ListNode* mid = getMid(head);
//         ListNode* left = sortList(head);
//         ListNode* right = sortList(mid);
        
//         return merge(left, right);   
//     }
// };




/* 10) LRU Cache           (146. LRU Cache) */
/* We will put least recently used in Tail side and put most recently used in Head side */

// class LRUCache {
// public:
//     class node{
//         public:
//         int key;
//         int val;
//         node* next;
//         node* prev;
        
//         node(int _key, int _val){
//             key = _key;
//             val = _val;
//         }
//     };
    
//     node* head = new node(-1,-1);
//     node* tail = new node(-1,-1);
    
//     int cap;
//     unordered_map<int,node*> m;
    
//     LRUCache(int capacity) {
//         cap = capacity;
//         head->next = tail;
//         tail->prev = head;
//     }
    
//     void addnode(node* newnode){
//         node* temp = head->next;
//         newnode->next = temp;
//         newnode->prev = head;
//         head->next = newnode;
//         temp->prev = newnode;
//     }
    
//     void deletenode(node* delnode){
//         node* delprev = delnode->prev;
//         node* delnext = delnode->next;
//         delprev->next = delnext;
//         delnext->prev = delprev;
//     }
    
//     int get(int key) {
//         if(m.find(key) != m.end()){
//             node* resnode = m[key];
//             int res = resnode->val;
//             m.erase(key);
//             deletenode(resnode);
//             addnode(resnode);
//             m[key] = head->next;
//             return res;
//         }
//         return -1;
//     }
    
//     void put(int key, int value) {
//         if(m.find(key) != m.end()){
//             node* existinnode = m[key];
//             m.erase(key);
//             deletenode(existinnode);
//         }
//         if(m.size() == cap){
//             m.erase(tail->prev->key);
//             deletenode(tail->prev);
//         }
//         addnode(new node(key,value));
//         m[key] = head->next;
//     }
// };

// /**
//  * Your LRUCache object will be instantiated and called as such:
//  * LRUCache* obj = new LRUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */



/* 11) LFU Cache                   (460. LFU Cache) */


// struct Node{
//     int key, value, cnt;
//     Node* next;
//     Node* prev;
    
//     Node(int _key, int _value){
//         key = _key;
//         value = _value;
//         cnt = 1;
//     }
// };

// struct List{
//     int size;
//     Node* head;
//     Node* tail;
    
//     List(){
//         head = new Node(0,0);
//         tail = new Node(0,0);
//         head->next = tail;
//         tail->prev = head;
//         size = 0;
//     }
    
//     void addFront(Node* node){
//         Node* temp = head->next;
//         node->next = temp;
//         node->prev = head;
//         head->next = node;
//         temp->prev = node;
//         size++;
//     }
    
//     void removeNode(Node* delnode){
//         Node* delprev = delnode->prev;
//         Node* delnext = delnode->next;
//         delprev->next = delnext;
//         delnext->prev = delprev;
//         size--;
//     }
// };

// class LFUCache {
//     map<int, Node*> keyNode;
//     map<int, List*> freqListMap;
//     int maxSizeCache;
//     int minFreq;
//     int curSize;
// public:
//     LFUCache(int capacity) {
//         maxSizeCache = capacity;
//         minFreq = 0;
//         curSize = 0;
//     }
    
//     void updateFreqListMap(Node* node){
//         keyNode.erase(node->key);
//         freqListMap[node->cnt]->removeNode(node);
//         if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0){
//             minFreq++;
//         }
        
//         List* nextHigherFreqList = new List();
//         if(freqListMap.find(node->cnt + 1) != freqListMap.end()){
//             nextHigherFreqList = freqListMap[node->cnt + 1];
//         }
//         node->cnt += 1;
//         nextHigherFreqList->addFront(node);
//         freqListMap[node->cnt] = nextHigherFreqList;
//         keyNode[node->key] = node;
//     }
        
//     int get(int key) {
//         if(keyNode.find(key) != keyNode.end()){
//             Node* node = keyNode[key];
//             int val = node->value;
//             updateFreqListMap(node);
//             return val;
//         }
//         return -1;
//     }
    
//     void put(int key, int value) {
//         if(maxSizeCache == 0){
//             return;
//         }
//         if(keyNode.find(key) != keyNode.end()){
//             Node* node = keyNode[key];
//             node->value = value;
//             updateFreqListMap(node);
//         }
//         else{
//             if(curSize == maxSizeCache){
//                 List* list = freqListMap[minFreq];
//                 keyNode.erase(list->tail->prev->key);
//                 freqListMap[minFreq]->removeNode(list->tail->prev);
//                 curSize--;
//             }
//             curSize++;
//             //new value has to be addedwho is not there previously
//             minFreq = 1;
//             List* listFreq = new List();
//             if(freqListMap.find(minFreq) != freqListMap.end()){
//                 listFreq = freqListMap[minFreq];
//             }
//             Node* node = new Node(key,value);
//             listFreq->addFront(node);
//             keyNode[key] = node;
//             freqListMap[minFreq] = listFreq;
//         }
//     }
// };

// /**
//  * Your LFUCache object will be instantiated and called as such:
//  * LFUCache* obj = new LFUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */




/* 12) Merge k Sorted Lists     (23. Merge k Sorted Lists)       (IMP) */



/* Solution 1: Merge lists one by one*/
/* Convert merge k lists problem to merge 2 lists (k-1) times. */
// Time complexity : O(kN) where k is the number of linked lists
// Space complexity : O(1)


// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         if(l1 == NULL){
//             return l2;
//         }
//         if(l2 == NULL){
//             return l1;
//         }

//         ListNode* result;
//         if(l1->val < l2->val){
//             result = l1;
//             result->next = mergeTwoLists(l1->next,l2);
//         }
//         else{
//             result = l2;
//             result->next = mergeTwoLists(l1,l2->next);
//         }

//         return result;        
//     }
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         if(lists.size() == 0){
//             return NULL;
//         }
//         if(lists.size() == 1){
//             return lists[0];
//         }

//         ListNode* ans = mergeTwoLists(lists[0],lists[1]);
//         for(int i = 2; i < lists.size(); i++){
//             ans = mergeTwoLists(ans,lists[i]);
//         }

//         return ans;
//     }
// };




/* Solution 2: Merge with Divide And Conquer        (TO BE USED)   */
/* This approach walks alongside the one above but is improved a lot. We don't need to traverse most nodes many times repeatedly

1) Pair up k lists and merge each pair.
2) After the first pairing, k lists are merged into k/2 lists with average 2N/k length, then k/4, k/8 and so on.
3) Repeat this procedure until we get the final sorted linked list.

Thus, we'll traverse almost N nodes per pairing and merging, and repeat this procedure about logk times */

// Time complexity : O(N logK) where k is the number of linked lists
// Space complexity : O(1)


// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         if(l1 == NULL){
//             return l2;
//         }
//         if(l2 == NULL){
//             return l1;
//         }

//         ListNode* result;
//         if(l1->val < l2->val){
//             result = l1;
//             result->next = mergeTwoLists(l1->next,l2);
//         }
//         else{
//             result = l2;
//             result->next = mergeTwoLists(l1,l2->next);
//         }

//         return result;        
//     }
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         if(lists.size() == 0){
//             return NULL;
//         }
//         if(lists.size() == 1){
//             return lists[0];
//         }

//         int interval = 1;
//         while(interval < lists.size()){
//             for(int i = 0; i+interval < lists.size(); i = i+interval*2){
//                 lists[i] = mergeTwoLists(lists[i],lists[i+interval]);
//             }
//             interval *= 2;
//         }

//         return lists[0];
//     }
// };



/* 13) Remove Duplicates from Sorted List   (83. Remove Duplicates from Sorted List) */

/* Here we have to remove duplicate elements
Ex :-   1->2->3->3->4->4->5     =>       1->2->3->4->5      */


// Time complexity : O(N)
// Space complexity : O(1)


// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         ListNode* temp = head;
//         while(temp != NULL && temp->next != NULL){
//             if(temp->val == temp->next->val){
//                 ListNode* todelete = temp->next;
//                 temp->next = temp->next->next;
//                 delete todelete;
//             }
//             else{
//                 temp = temp->next;
//             }
//         }
//         return head;
//     }
// };




/* 14) Remove Duplicates from Sorted List II   (82. Remove Duplicates from Sorted List II) */

/* Here we have to remove all the nodes that have duplicate elements leaving only distinct numbers from the original list
Ex :-   1->2->3->3->4->4->5     =>       1->2->5      */

/*
first make a dummy node and assign its value equals to 0 and its next points to the head of the given linked list
 
ListNode* dummyNode = new ListNode(0, head);

         OR
         
ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;     
*/

// Time complexity : O(N)
// Space complexity : O(1)


// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         //Here  ListNode(0,head)   means we assign value 0 and its next points to head
//         ListNode* dummyNode = new ListNode(0, head);
//         ListNode* prev = dummyNode;
//         while(head != NULL){
//             if(head->next != NULL && head->val == head->next->val){
//                 while(head->next != NULL && head->val == head->next->val){
//                     head = head->next;
//                 }
//                 prev->next = head->next;
//             }
//             else{
//                 prev = prev->next;
//             }

//             head = head->next;
//         }

//         return dummyNode->next;
//     }
// };

