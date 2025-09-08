/* Codestudio  Submission    (Min Heap Implementation) */

/* Problem Statement: Implement the Min Heap data structure. For information about Heap click here. 
Min heap is a tree data structure where the root element is the smallest of all th elements in the heap. 
Also, the children of every node are smaller than or equal to the root node. 
The insertion and removal of elements from the heap take log('N'), where 'N' is the number of nodes in the tree. 
Implement the "minHeap" class. You will be given the following types of queries 

O extractMinElement(): Remove the minimum element present in the heap, and return it.
1 deleteElement(i): Delete the element present at the 'ith index.
2 insert( key ): Insert the value 'key' in the heap. 

For queries of types 0 and 1, at least one element should be in the heap. */



/* Solution:  */
// Time Complexity: O(N * logN)                 Where ‘N’ is the number of queries.
// Space Complexity: O(N)     


// class minHeap {
// public:
//     vector<int> heap;
//     int n, capacity;
//     // Constructor for the class.
//     minHeap(int cap) {
//         heap.resize(cap);
//         n = 0;
//         capacity = cap;
//     }

//     void heapify(vector<int> &heap, int n, int i){
//         int smallest = i;        // Initialize smallest as root
//         int l = 2 * i + 1;     // left = 2*i + 1
//         int r = 2 * i + 2;    // right = 2*i + 2

//         if(l < n && heap[l] < heap[smallest]){
//             smallest = l;
//         }
//         if(r < n && heap[r] < heap[smallest]){
//             smallest = r;
//         }

//         if(smallest != i){
//             swap(heap[i], heap[smallest]);
//             heapify(heap, n, smallest);
//         }
//     }

//     void heapifyInsert(vector<int> &heap, int n, int i){
//         int parent = (i-1)/2;
//         if(parent >= 0){
//             if(heap[i] < heap[parent]){
//                 swap(heap[i], heap[parent]);
//                 heapifyInsert(heap, n, parent);
//             }
//         }
//     }

//     // Implement the function to remove minimum element.
//     int extractMinElement() {
//         if(n == 0){
//             return -1;
//         }
//         int ele = heap[0];

//         swap(heap[0], heap[n-1]);

//         // Decrease size of heap by 1
//         n = n-1;
        
//         // heapify the root node
//         heapify(heap, n, 0);

//         return ele;
//     }

//     // Implement the function to delete an element.
//     void deleteElement(int ind) {
//         if(ind >= n){
//             return;
//         }

//         swap(heap[ind], heap[n-1]);
//         // Decrease size of heap by 1
//         n = n-1;
        
//         // heapify the node at ind
//         heapify(heap, n, ind);
//     }

//     // Implement the function to insert 'val' in the heap.
//     void insert(int val) {
//         if(n == capacity){
//             return;
//         }
//         heap[n] = val;

//         // Increase the size of Heap by 1
//         n = n + 1;

//         // Heapify the new node following a Bottom-up approach
//         heapifyInsert(heap, n, n-1);
//     }
// };