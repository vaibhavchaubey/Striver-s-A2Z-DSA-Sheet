/* Leetcode  Submission    (1423. Maximum Points You Can Obtain from Cards) */

/* Problem Statement: There are several cards arranged in a row, and each card has an associated number of points. 
The points are given in the integer array cardPoints. In one step, you can take one card from the beginning or from 
the end of the row. You have to take exactly k cards. Your score is the sum of the points of the cards you have taken. 
Given the integer array cardPoints and the integer k, return the maximum score you can obtain. */



/* Solution: Sliding Window */
// Time Complexity: O(N)
// Time Complexity: O(1)


/* Intuition: The cards which we are taking may not be a subarray but the cards which we are not taking is surely form the subarray. 
So in order to get maximum points we have to make the sum of these not taken card subarray minimum. 
Hence this should be maximum  total_pts - sumOfCurrentWindow

1) Let the sum of all points be total_pts. We need to remove a sub-array from cardPoints with length n - k. 
2) Keep a window of size n - k over the array. The answer is max(answer, total_pts - sumOfCurrentWindow) */


// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
//         int n = cardPoints.size();
//         int totalPoints = 0;
//         for(int i = 0; i < n; i++){
//             totalPoints += cardPoints[i];
//         }

//         int sumOfCurrentWindow = 0;
//         for(int i = 0; i < n-k; i++){
//             sumOfCurrentWindow += cardPoints[i];
//         }

//         int ans = totalPoints - sumOfCurrentWindow;
//         for(int i = n-k; i < n; i++){
//             sumOfCurrentWindow -= cardPoints[i-(n-k)];
//             sumOfCurrentWindow += cardPoints[i];
//             ans = max(ans, totalPoints - sumOfCurrentWindow);
//         }

//         return ans;
//     }
// };