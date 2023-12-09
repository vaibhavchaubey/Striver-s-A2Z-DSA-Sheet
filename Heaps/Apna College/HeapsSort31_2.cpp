/* Heapify function works on logN and we are calling it N time so Time Complexity: O(N logN) */

/*
Heap Sort Algorithm for sorting in increasing order:
1. Build a max heap from the input data.
2. At this point, the largest item is stored at the root of the heap.
Replace it with the last item of the heap followed by reducing the size of heap by 1.
Finally, heapify the root of the tree.
3. Repeat step 2 while the size of the heap is greater than 1.
*/

// Time Complexity: O(N logN)
// Auxiliary Space: O(log N), due to the recursive call stack. However, auxiliary space can be O(1) for iterative implementation.


#include<iostream>
using namespace std;
void heapify(int arr[], int n, int i){                   
    int largest = i;      // Initialize largest as root
    int l = 2*i+1;        // left = 2*i + 1
    int r = 2*i+2;        // right = 2*i + 2

    // If left child is larger than root
    if(l < n && arr[l] > arr[largest]){
        largest = l;
    }
    // If right child is larger than largest so far
    if(r < n && arr[r] > arr[largest]){
        largest = r;
    }

    // If largest is not root
    if(largest != i){
        swap(arr[i],arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n)
{

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {40, 10, 30, 50, 60, 15};
    int n = 6;
    heapSort(arr, n);
    printArray(arr, n);

    return 0;
}