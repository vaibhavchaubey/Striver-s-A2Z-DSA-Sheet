// Time Complexity: O(N^2)
// Space Complexity: O(1)


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the numbers: ";
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i-1;
        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (arr[j]>current && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current; 
    }    

    cout<<"Array after Sorting: ";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }



    return 0;    
}