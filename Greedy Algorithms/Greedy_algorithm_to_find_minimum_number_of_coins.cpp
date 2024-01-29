/* Codestudio  Submission    (Find Minimum Number Of Coins) */

/* Problem Statement: Given an infinite supply of Indian currency i.e. [1, 2, 5, 10, 20, 50, 100, 500, 1000] valued coins and 
an amount 'N'.
Find the minimum coins needed to make the sum equal to 'N'. You have to return the list containing the value of coins required 
in decreasing order. */


/* Solution: Greedy Algorithm  */
// Time Complexity: O(N)              //   where 'N' is the given amount to be changed
// Space Complexity: O(1)


// vector<int> MinimumCoins(int n)
// {
//     int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
//     int size = 9;

//     vector<int> ans;
//     for(int i = size - 1; i >= 0; i--){
//         while(n >= coins[i]){
//             n -= coins[i];
//             ans.push_back(coins[i]);
//         }
//     }

//     return ans;
// }



/* GFG  Submission    (Minimum number of Coins) */

/* Problem Statement: Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 } 
and a target value N.
Find the minimum number of coins and/or notes needed to make the change for Rs N. You must return the list containing the value of 
coins required.  */


/* Solution: Greedy Algorithm  */
// Time Complexity: O(N)              //   where 'N' is the given amount to be changed
// Space Complexity: O(1)


// class Solution{
// public:
//     vector<int> minPartition(int N)
//     {
//         int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
//         int size = 10;
    
//         vector<int> ans;
//         for(int i = size - 1; i >= 0; i--){
//             while(N >= coins[i]){
//                 N -= coins[i];
//                 ans.push_back(coins[i]);
//             }
//         }
    
//         return ans;
//     }
// };





/* QUESTION :-
Given a value X, if we want to make a change for V Rs, and we have an infinite supply of each 
of the denominations in Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} 
valued coins/notes, what is the minimum number of coins and/or notes needed to make the change? */



/* Solution: Greedy Approach.
Approach: A common intuition would be to take coins with greater value first. 
This can reduce the total number of coins needed. Start from the largest possible 
denomination and keep adding denominations while the remaining value is greater than 0. 

Algorithm:  
1) Sort the array of coins in decreasing order.
2) Initialize result as empty.
3) Find the largest denomination that is smaller than current amount.
4) Add found denomination to result. Subtract value of found denomination from amount.
5) If amount becomes 0, then print result.
6) Else repeat steps 3 and 4 for new value of V.
*/


// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// int main()
// {
//     int n = 10;
//     vector<int> a = {1,2,5,10,20,50,100,200,500,2000};
//     int x = 54;

//     sort(a.begin(), a.end(), greater<int>());
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         ans += x/a[i];
//         x -= x/a[i] * a[i];
//     }
//     cout<<ans<<endl;


//     return 0;
// }



/* OR    (Here we print the value of coins) */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n = 10;
    vector<int> a = {1,2,5,10,20,50,100,200,500,2000};
    int x = 54;

    sort(a.begin(), a.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
       while (x >= a[i])
       {
           x -= a[i];
           cout<<a[i]<<" ";
       } 
    }
   

    return 0;
}