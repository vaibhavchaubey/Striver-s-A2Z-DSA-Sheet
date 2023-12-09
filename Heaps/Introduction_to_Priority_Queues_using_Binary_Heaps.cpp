/* Codestudio  Submission    (Implement a priority queue) */

/* Problem Statement: You have to implement the pop function of Max Priority Queue and implement using a heap.
Functions :
a) push(int x) : 'x' has to be inserted in the priority queue. This has been implemented already
b) pop() : return the maximum element in the priority queue, if priority queue is empty then return '-1'. */



/* Solution 1: Using Heap in C++ STL */
// Time Complexity: O(logN)  
// Space Complexity: O(1)     


// int pop(vector<int> &heap)
// {
//     int n = heap.size();
//     if(n == 0){
//         return -1;
//     }
//     int ele = heap[0];

//     swap(heap[0], heap[n-1]);
//     heap.pop_back();
//     make_heap(heap.begin(), heap.end());

//     /* OR */

//     // pop_heap(heap.begin(), heap.end());   //move the largest element at the end of the heap
//     // heap.pop_back();


//     return ele;
// }

// // Code Snippet of the push function: 
// //
// //     void push(vector<int> &heap, int x)
// //     {
// //           heap.push_back(x);
// //
// //            // Posistion of the current inserted element.
// //            int pos=heap.size()-1;
// //
// //            // Shifting the element up until it reaches the top most node if it is larger than its parent.
// //            while(pos>0)
// //            {
// //                int parent = (pos-1)/2;
// //                if(heap[pos] > heap[parent])
// //                {
// //                    swap(heap[parent],heap[pos]);
// //                    pos=parent;
// //               }
// //              else
// //              {
// //                  // As parent is larger the element now is in its correct position. 
// //                  break;
// //              }
// //          }
// //      }




/* Solution 2: Implement heapify function */
// Time Complexity: O(logN)  
// Space Complexity: O(1)  


// void heapify(vector<int> &heap, int n, int i){
//     int largest = i;        // Initialize largest as root
//     int l = 2 * i + 1;     // left = 2*i + 1
//     int r = 2 * i + 2;    // right = 2*i + 2

//     if(l < n && heap[l] > heap[largest]){
//         largest = l;
//     }
//     if(r < n && heap[r] > heap[largest]){
//         largest = r;
//     }

//     if(largest != i){
//         swap(heap[i], heap[largest]);
//         heapify(heap, n, largest);
//     }
// }
// int pop(vector<int> &heap)
// {
//     int n = heap.size();
//     if(n == 0){
//         return -1;
//     }
//     int ele = heap[0];

//     // Replace root with last element
//     swap(heap[0], heap[n-1]);
//     heap.pop_back();
    
//     // heapify the root node
//     heapify(heap, n-1, 0);

//     return ele;
// }

// // Code Snippet of the push function: 
// //
// //     void push(vector<int> &heap, int x)
// //     {
// //           heap.push_back(x);
// //
// //            // Posistion of the current inserted element.
// //            int pos=heap.size()-1;
// //
// //            // Shifting the element up until it reaches the top most node if it is larger than its parent.
// //            while(pos>0)
// //            {
// //                int parent = (pos-1)/2;
// //                if(heap[pos] > heap[parent])
// //                {
// //                    swap(heap[parent],heap[pos]);
// //                    pos=parent;
// //               }
// //              else
// //              {
// //                  // As parent is larger the element now is in its correct position. 
// //                  break;
// //              }
// //          }
// //      }