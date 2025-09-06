/* Building Heap from Array */

/* Approach: The leaf nodes need not to be heapified as they already follow the heap property.
Also, the array representation of the complete binary tree contains the level order traversal of the tree.
So the idea is to find the position of the last non-leaf node and perform the heapify operation of each
non-leaf node in reverse level order.  */


/* Time Complexity Analysis:
-------------------------
heapify():
  - For a node at index i, heapify can move it down at most to a leaf.
  - Height of heap = O(log N)
  - So, worst-case time for heapify = O(log N)

buildHeap():
  - Calls heapify for all non-leaf nodes (≈ N/2 nodes).
  - Naively: O(N/2) * O(log N) = O(N log N)
  - But actually, nodes near the bottom take much less time (their height is smaller).
  - Summation of work across levels gives O(N).

✅ Final Time Complexity = O(N)

Space Complexity Analysis:
--------------------------
- heapify() is recursive → recursion depth = O(log N) (height of heap).
- Other variables use constant space O(1).

✅ Final Auxiliary Space = O(log N)
   (If heapify is written iteratively, space = O(1)) */


// Time Complexity: O(N)
// Auxiliary Space: O(N) (Recursive Stack Space)


// #include<iostream>
// using namespace std;
// void heapify(int arr[], int n, int i){
//     int largest = i;      // Initialize largest as root
//     int l = 2*i+1;        // left = 2*i + 1
//     int r = 2*i+2;        // right = 2*i + 2

//     // If left child is larger than root
//     if(l < n && arr[l] > arr[largest]){
//         largest = l;
//     }
//     // If right child is larger than largest so far
//     if(r < n && arr[r] > arr[largest]){
//         largest = r;
//     }

//     // If largest is not root
//     if(largest != i){
//         swap(arr[i],arr[largest]);
//         // Recursively heapify the affected sub-tree
//         heapify(arr,n,largest);
//     }
// }

// void buildHeap(int arr[], int n){
//     // Perform reverse level order traversal
//     // from last non-leaf node and heapify
//     // each node
//     for (int i = n/2-1; i >= 0; i--)
//     {
//         heapify(arr,n,i);
//     }
// }

// void printArray(int arr[], int n){
//     for (int i = 0; i < n; i++)
//     {
//         cout<<arr[i]<<" ";
//     }cout<<endl;
// }
// int main()
// {

// /* Binary Tree Representation of input array                Final Heap
// .              40                                               60
// .            /    \                                           /    \
// .           10     30              ---------->               50     30
// .          / \     /                                        /  \    /
// .         50  60  15                                       40  10  15
// .
// */
//     int arr[] = {40,10,30,50,60,15};      //60 50 30 40 10 15
//     int n = 6;
//     buildHeap(arr,n);
//     printArray(arr,n);

//     return 0;
// }



/* Deletion in Heap */

/* Process of Deletion:
Since deleting an element at any intermediary position in the heap can be costly,
so we can simply replace the element to be deleted by the last element and delete the last element of the Heap.

1) Replace the root or element to be deleted by the last element.
2) Delete the last element from the Heap.
3) Since, the last element is now placed at the position of the root node.
So, it may not follow the heap property. Therefore, heapify the last node placed at the position of root. */


/* Time Complexity Analysis:
-------------------------
- Replacing root with last element = O(1)
- Deleting last element (reducing size) = O(1)
- Heapify from root = O(log N)  [height of heap]

✅ Final Time Complexity = O(log N)

Space Complexity Analysis:
--------------------------
- heapify() uses recursion → recursion depth = O(log N)
- Extra variables = O(1)

✅ Final Auxiliary Space = O(log N)
   (If heapify is iterative → O(1))
*/


// Time complexity: O(logN) where N is no of elements in the heap
// Auxiliary Space: O(N)


// #include<iostream>
// using namespace std;
// void heapify(int arr[], int n, int i){
//     int largest = i;            // Initialize largest as root
//     int l = 2*i+1;             // left = 2*i + 1
//     int r = 2*i+2;            // right = 2*i + 2

//     if(l < n && arr[l] > arr[largest]){
//         largest = l;
//     }

//     if(r < n && arr[r] > arr[largest]){
//         largest = r;
//     }

//     if(largest != i){
//         swap(arr[i],arr[largest]);

//         // Recursively heapify the affected sub-tree
//         heapify(arr,n,largest);
//     }
// }

// void deleteRoot(int arr[], int &n){

//     // Get the last element
//     int lastElement = arr[n-1];

//     // Replace root with last element
//     arr[0] = lastElement;

//     // Decrease size of heap by 1
//     n = n-1;

//     // heapify the root node
//     heapify(arr,n,0);
// }

// void printarray(int arr[], int n){
//     for (int i = 0; i < n; i++)
//     {
//         cout<<arr[i]<<" ";
//     }cout<<endl;
// }
// int main()
// {

// /* Array representation of Max-Heap           (Delete - 10)
// .             10                   5
// .            /  \                 / \
// .           5    3      ->       4   3
// .          / \                  /
// .         2   4                2
// .
// */

//     int arr[] = {10,5,3,2,4};
//     int n = 5;
//     deleteRoot(arr,n);
//     printarray(arr,n);

//     return 0;
// }



/* Insertion in Heaps */

/* Process of Insertion:
Elements can be inserted to the heap following a similar approach as discussed above for deletion.
The idea is to:

1) First increase the heap size by 1, so that it can store the new element.
2) Insert the new element at the end of the Heap.
3) This newly inserted element may distort the properties of Heap for its parents.
So, in order to keep the properties of Heap, heapify this newly inserted element following a bottom-up approach. */


/* Time Complexity Analysis:
-------------------------
- Insert element at end = O(1)
- Bubble up (heapify) = O(log N)   [height of heap]
✅ Final Time Complexity = O(log N)

Space Complexity Analysis:
--------------------------
- Input array = O(N)
- heapify() uses recursion = O(log N)

✅ Final Space Complexity = O(N + log N) ≈ O(N)
✅ Final Auxiliary Space = O(log N)
   (If iterative heapify is used → O(1))
*/



// Time complexity: O(logN) where N is no of elements in the heap
// Auxiliary Space: O(N)


#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{

    // Find parent
    int parent = (i - 1) / 2; // i-1  as there is 0 base indexing
    // For Max-Heap
    // If current node is greater than its parent
    // Swap both of them and call heapify again
    // for the parent
    if (parent >= 0)
    {
        if (arr[i] > arr[parent])
        {
            swap(arr[i], arr[parent]);

            heapify(arr, n, parent);
        }
    }
}

void insertNode(int arr[], int &n, int key)
{

    // Increase the size of Heap by 1
    n = n + 1;

    // Insert the element at end of Heap
    arr[n - 1] = key;

    // Heapify the new node following a
    // Bottom-up approach
    heapify(arr, n, n - 1);
}

void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{

    /* Array representation of Max-Heap           (Insert 15)
    .             10                   10                   15
    .            /  \                 /  \                 /  \
    .           5    3      ->       5    3       ->      5    10
    .          / \                  / \  /               / \   /
    .         2   4                2  4 15              2   4 3
    .
    */

    int arr[] = {10, 5, 3, 2, 4};
    int n = 5;
    int key = 15;
    insertNode(arr, n, key);
    printarray(arr, n);

    return 0;
}