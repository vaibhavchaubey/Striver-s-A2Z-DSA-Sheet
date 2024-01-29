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
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    bool swapped;
    for(int i = 0; i < n-1; i++){
        swapped = false;
        // Last i elements are already in place (that's why we do n-i-1)
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        // IF no two elements were swapped 
        if(swapped == false){
            break;
        }
    }

    cout<<"Array after Sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }


    return 0;    
}


// #include<iostream>
// using namespace std;

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
    
//     int counter = 1;
//     while(counter <= n-1){
//         for (int i = 0; i < n-counter; i++){
//             if(arr[i] > arr[i+1]){
//                 int temp = arr[i];
//                 arr[i] = arr[i+1];
//                 arr[i+1] = temp;
//             }
//         }
//         counter++;
//     }
//     cout<<"Array after Sorting: ";
//     for(int i = 0; i < n; i++){
//         cout<<arr[i]<<" ";
//     }


    
//     return 0;    
// }