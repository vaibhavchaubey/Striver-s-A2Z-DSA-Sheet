/* Codestudio  Submission    (Convert Min Heap To Max Heap) */

/* Problem Statement: You are given an array of size 'N' which is an array representation of min-heap. 
You need to convert this min-heap array representation to a max-heap array representation. 
Return the max-heap array representation. */



/* Solution 1: Sort the array in descending order. */
// Time Complexity: O(N logN)  
// Space Complexity: O(1)     


// vector<int>MinToMaxHeap(int n, vector<int>&arr)
// {
// 	// Sorting in descending order.
// 	sort(arr.begin(), arr.end(), greater<int>());

// 	return arr;
// }




/* Solution 2: Build MaxHeap just like in heap sort. */
// Time Complexity: O(N)  
// Space Complexity: O(1)  


// void heapify(vector<int>& arr, int n, int i){                       
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
// void buildHeap(vector<int>& arr, int n){
//     // Perform reverse level order traversal
//     // from last non-leaf node and heapify
//     // each node
//     for (int i = n/2-1; i >= 0; i--){
//         heapify(arr,n,i);
//     } 
// }
// vector<int>MinToMaxHeap(int n, vector<int>&arr)
// {
// 	buildHeap(arr, n);

// 	return arr;
// }