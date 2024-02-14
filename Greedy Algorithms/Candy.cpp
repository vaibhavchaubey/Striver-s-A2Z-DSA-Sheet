/* Leetcode  Submission    (135. Candy) */

/* Problem Statement: There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
You are giving candies to these children subjected to the following requirements:
    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children. */


/* Solution: Greedy Algorithm: Two-Pass Method */
/* 
1) Initialize Candies Array:
We start by creating a candies array of the same length as the ratings array and initialize all its values to 1. 
This is the base case and ensures that every child will receive at least one candy, satisfying the first condition. 

2) Forward Pass: Left to Right
Now, we iterate through the ratings array from the beginning to the end. For each child (except the first), we compare 
their rating with the one to the left. If it's higher, we update the candies array for that child to be one more than 
the child on the left. This takes care of the second condition but only accounts for the child's left neighbor.

3) Backward Pass: Right to Left
After the forward pass, we loop through the array again but in the reverse direction. This time, we compare each child's 
rating with the child to their right. If the rating is higher, we need to make sure the child has more candies than the 
right neighbor. So, we update the candies array for that child to be the maximum between its current number of candies 
and one more than the right neighbor's candies. This ensures that both neighboring conditions are checked and satisfied.

4) Summing it All Up
Finally, we sum up all the values in the candies array. This will give us the minimum total number of candies that need 
to be distributed to satisfy both conditions.
*/

// Time Complexity: O(N)
// Space Complexity: O(N)


// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n = ratings.size();
//         vector<int> candies(n, 1);
//         for(int i = 1; i < n; i++){
//             if(ratings[i] > ratings[i-1]){
//                 candies[i] = candies[i-1] + 1;
//             }
//         }
//         // As we are not able to take count of last element in loops so we adding it to the sum
//         int sum = candies[n-1];       
//         for(int i = n-2; i >= 0; i--){
//             if(ratings[i] > ratings[i+1]){
//                 candies[i] = max(candies[i], candies[i+1] + 1);
//             }
//             sum += candies[i];
//         }
        
//         return sum;
//     }
// };



/* OR */

// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n = ratings.size();
//         vector<int> candies(n, 1);
//         map<int, set<int>> mp;       // num, index
//         for(int i = 0; i < n; i++){
//             if(i > 0 && ratings[i] < ratings[i-1]){
//                 mp[ratings[i]].insert(i);
//             }
//             else if(i < n-1 && ratings[i] < ratings[i+1]){
//                 mp[ratings[i]].insert(i);
//             }
//         }

//         for(auto it : mp){
//             for(auto i : it.second){
//                 if(i > 0 && ratings[i-1] > ratings[i]){
//                     if(candies[i-1] <= candies[i]){
//                         candies[i-1] = 1 + candies[i];
//                     }
//                 }
//                 if(i < n-1 && ratings[i+1] > ratings[i]){
//                     if(candies[i+1] <= candies[i]){
//                         candies[i+1] = 1 + candies[i];
//                     }
//                 }
//             }
//         }

//         int count = 0;
//         for(auto i : candies){
//             count += i;
//         }

//         return count;
//     }
// };