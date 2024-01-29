/* Merge sort is defined as a sorting algorithm that works by dividing an array into smaller subarrays, sorting each subarray,
and then merging the sorted subarrays back together to form the final sorted array.


How does Merge Sort work?
Merge sort is a recursive algorithm that continuously splits the array in half until it cannot be further divided i.e.,
the array has only one element left (an array with one element is always sorted). Then the sorted subarrays are merged
into one sorted array. */


// Time Complexity: O(NlogN)
// Space Complexity: O(N) Since we need an arbitrary array as well


#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    // temp arrays
    int a[n1];
    int b[n2];

    // Copy data to temp arrays a[] and b[]
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;
    // Merge the temp arrays back into array[left..right]
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }

    // Copy the remaining elements of a[], if there are any
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }

    // Copy the remaining elements of b[], if there are any
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "Array after Sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

// OR
/* takeuforward */

// #include<bits/stdc++.h>
// using namespace std;

// void merge(int arr[], int l, int mid, int r){
//     vector<int> temp;      // temp arrays
//     int i = l;              // starting index of left half of arr
//     int j = mid+1;          // starting index of right half of arr

//     //storing elements in the temporary array in a sorted manner
//     while (i <= mid && j <= r)
//     {
//         if (arr[i]<arr[j])
//         {
//             temp.push_back(arr[i]);
//             i++;
//         }
//         else
//         {
//             temp.push_back(arr[j]);
//             j++;
//         }
//     }

//     // if elements on the left half are still left
//     while(i <= mid)
//     {
//         temp.push_back(arr[i]);
//         i++;
//     }

//     // if elements on the right half are still left
//     while(j <= r)
//     {
//         temp.push_back(arr[j]);
//         j++;
//     }

//     // transfering all elements from temporary to arr
//     for(int i = l; i <= r; i++){
//         arr[i] = temp[i-l];
//     }
// }

// void mergeSort(int arr[], int l, int r){
//     if(l<r){
//         int mid = (l+r)/2;

//         mergeSort(arr,l,mid);
//         mergeSort(arr,mid+1,r);

//         merge(arr,l,mid,r);

//     }
// }

// int main()
// {
//     int n;
//     cout<<"Enter size of array: ";
//     cin>>n;
//     int arr[n];
//     cout<<"Enter the numbers: ";
//     for (int i = 0; i < n; i++){
//         cin>>arr[i];
//     }

//     mergeSort(arr,0,n-1);

//     cout<<"Array after Sorting: ";
//     for(int i = 0; i < n; i++){
//         cout<<arr[i]<<" ";
//     }

//     return 0;
// }