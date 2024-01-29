/* GFG  Submission    (Fractional Knapsack) */

/* Problem Statement: Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the 
maximum total value in the knapsack.
Note: Unlike 0/1 knapsack, you are allowed to break the item here. */


/* 'static' is used here to indicate that comp is a static member function of the Solution class, and it can be accessed 
without creating an instance of the class. This is useful when the function is used in a context where an instance of the class is 
not required, such as in sorting algorithms. */


/* Solution: Greedy Algorithm */
// Time Complexity: O(N logN)
// Space Complexity: O(1)


//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


// class Solution
// {
//     public:
//     static bool comp(Item a, Item b){
//         double v1 = (double)a.value / (double)a.weight;
//         double v2 = (double)b.value / (double)b.weight;
        
//         return v1 > v2;
//     }
//     //Function to get the maximum total value in the knapsack.
//     double fractionalKnapsack(int W, Item arr[], int n)
//     {
//         sort(arr, arr+n, comp);
        
//         double maxValue = 0;
//         for(int i = 0; i < n; i++){
//             if(W >= arr[i].weight){
//                 maxValue += arr[i].value;
//                 W -= arr[i].weight;
//             }
//             else{
//                 double vw = (double)arr[i].value / (double)arr[i].weight;
//                 maxValue += vw * W;
//                 break;
//             }
//         }
        
//         return maxValue;
//     }
        
// };




/* Codestudio  Submission    (Fractional Knapsack) */

/* Problem Statement: You have been given weights and values of ‘N’ items. You are also given a knapsack of size ‘W’.
Your task is to put the items in the knapsack such that the total value of items in the knapsack is maximum.
Note: You are allowed to break the items. */


/* Solution: Greedy Algorithm */
// Time Complexity: O(N logN)
// Space Complexity: O(1)


// #include <bits/stdc++.h> 
// bool comp(pair<int, int> &a, pair<int, int> &b){
//     double v1 = (double)a.second / (double)a.first; 
//     double v2 = (double)b.second / (double)b.first;

//     return v1 > v2; 
// }
// double maximumValue (vector<pair<int, int>>& items, int n, int w)
// {
//     // Write your code here.
//     // ITEMS contains {weight, value} pairs.

//     sort(items.begin(), items.end(), comp);
//     double maxValue = 0;
//     for(int i = 0; i < n; i++){
//         if(w >= items[i].first){
//             maxValue += items[i].second;
//             w -= items[i].first;
//         }
//         else{
//             double vw = (double)items[i].second / (double) items[i].first;
//             maxValue += vw * w;
//             break;
//         }
//     }

//     return maxValue;
// }

