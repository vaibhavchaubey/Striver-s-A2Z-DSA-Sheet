/* Leetcode  Submission    (846. Hand of Straights) */

/* Problem Statement: Alice has some number of cards and she wants to rearrange the cards into groups so that each group is 
of size groupSize, and consists of groupSize consecutive cards.
Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she 
can rearrange the cards, or false otherwise. */



/* Solution 1: Using priority queue */
// Time complexity : O(N * log N)       
// Space complexity : O(N)           


// class Solution {
// public:
//     bool isNStraightHand(vector<int>& hand, int groupSize) {
//         int n = hand.size();
//         if(n % groupSize != 0){
//             return false;
//         }

//         priority_queue<int, vector<int>, greater<int>> pq;      // minHeap
//         for(auto it : hand){
//             pq.push(it);
//         }

//         int count = 0;
//         int lastElement = -1;
//         vector<int> remain;
//         while(!pq.empty()){
//             int ele = pq.top();
//             pq.pop();

//             // only add if the group is new or if the next number is consecutive
//             if(lastElement == -1 || ele == lastElement + 1){
//                 lastElement = ele;
//                 count++;
//             }
//             else{
//                 // save all hands which cannot be added in current group
//                 // these will be pushed back into pq once a new group starts
//                 remain.push_back(ele);
//             }
            
//             if(count == groupSize){
//                 count = 0;
//                 lastElement = -1;
//                 for(auto it : remain){
//                     pq.push(it);
//                 }
//                 remain.clear();
//             }
//         }

//         // if a group is incomplete then count will be > 0.
//         return count > 0 ? false : true;
//     }
// };
    




/* Solution 2: Using map */
// Time complexity : O(N * log N)       
// Space complexity : O(N)       


// class Solution {
// public:
//     bool isNStraightHand(vector<int>& hand, int groupSize) {
//         int n = hand.size();
//         if(n % groupSize != 0){
//             return false;
//         }

//         unordered_map<int, int> mp;                     // ele, count
//         for(auto card : hand){
//             mp[card]++;
//         }
        
//         sort(hand.begin(), hand.end());

//         for(int i = 0; i < n; i++){
//             if(mp[hand[i]] == 0){
//                 continue;
//             }

//             for(int j = 0; j < groupSize; j++){
//                 int currCard = hand[i] + j;

//                 if(mp[currCard] == 0){
//                     return false;
//                 }

//                 mp[currCard]--;
//             }
//         }

//         return true;
//     }
// };