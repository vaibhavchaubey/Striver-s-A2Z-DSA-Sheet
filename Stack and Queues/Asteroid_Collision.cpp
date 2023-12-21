/* Leetcode  Submission    (735. Asteroid Collision) */

/* Problem Statement: We are given an array asteroids of integers representing asteroids in a row.
For each asteroid, the absolute value represents its size, and the sign represents its direction 
(positive meaning right, negative meaning left). Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. 
If both are the same size, both will explode. Two asteroids moving in the same direction will never meet. */



/* Solution: Using Stack */
// Time Complexity: O(N)
// Space Complexity: O(N)


// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         int n = asteroids.size();
//         stack<int> st;
//         for(int i = 0; i < n; i++){
//             if(asteroids[i] > 0 || st.empty()){
//                 st.push(asteroids[i]);
//             }
//             else{
//                 while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])){
//                     st.pop();
//                 }
//                 if(!st.empty() && st.top() == abs(asteroids[i])){
//                     st.pop();
//                 }
//                 else{
//                     if(st.empty() || st.top() < 0){
//                         st.push(asteroids[i]);
//                     }
//                 }
//             }
//         }

//         int size = st.size();
//         vector<int> ans(size);
//         for(int i = size-1; i >= 0; i--){
//             ans[i] = st.top();
//             st.pop();
//         }

//         return ans;
//     }
// };

