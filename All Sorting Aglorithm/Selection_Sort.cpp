// Time Complexity: O(N^2)
// Space Complexity: O(1)


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,mini;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    for (int i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        mini = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j]<arr[mini])
            {
                mini = j;             
            }    
        }

        // Swap the found minimum element with the first element 
        swap(arr[i], arr[mini]);
    }

    cout<<"Array after Sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }


    return 0;    
}

