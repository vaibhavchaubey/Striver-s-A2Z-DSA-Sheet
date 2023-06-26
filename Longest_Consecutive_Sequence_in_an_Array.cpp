/* Leetcode  Submission    (128. Longest Consecutive Sequence) */

/* Problem Statement: Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.  */



/* Solution 1: Sorting */
// Time Complexity: O(NlogN)
// Space Complexity: O(1)


// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if(nums.size() == 0){
//             return 0;
//         }
//         sort(nums.begin(), nums.end());
//         int currentStreak = 1;
//         int longestStreak = 1; 
//         int prev = nums[0];

//         for(int i = 1; i < nums.size(); i++){
//             if(nums[i] == prev+1){
//                 currentStreak++;
//             }
//             else if(nums[i] != prev){
//                 currentStreak = 1;
//             }
//             prev = nums[i];
//             longestStreak = max(longestStreak,currentStreak);
//         }
        
//         return longestStreak;
//     }
// };



/* Solution 2: Using Set */
// Time Complexity: O(N + 2N)
// Space Complexity: O(N)


// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if(nums.size() == 0){
//             return 0;
//         }

//         unordered_set<int> s;
//         for(auto num : nums){
//             s.insert(num);
//         }
        
//         int longestStreak = 1; 
//         for(auto num : nums){
//             if(!s.count(num-1)){        //number lesser than num exists or not
//                 int currentNum = num;
//                 int currentStreak = 1;
//                 while(s.count(currentNum + 1)){    //checking if next consecutive number exists or not
//                     currentNum += 1;
//                     currentStreak += 1;
//                 }
//                 longestStreak = max(longestStreak, currentStreak);
//             }
//         }    
        
//         return longestStreak;
//     }
// };