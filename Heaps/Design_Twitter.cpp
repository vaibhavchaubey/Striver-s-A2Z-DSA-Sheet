/* Leetcode  Submission    (355. Design Twitter) */

/* Problem Statement: Design a simplified version of Twitter where users can post tweets, follow/unfollow another user,
and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:
1) Twitter() Initializes your twitter object.
2) void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId.
Each call to this function will be made with a unique tweetId.
3) List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed.
Each item in the news feed must be posted by users who the user followed or by the user themself.
Tweets must be ordered from most recent to least recent.
4) void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
5) void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId. */



/* Solution 1: Using maxHeap */
/*
Time Complexity:

1) postTweet(int userId, int tweetId):
    Time Complexity: O(1)
    Space Complexity: O(1)
    Appending a tweet to the user's tweet list takes constant time.

2) getNewsFeed(int userId):
    Time Complexity: O(M log M), where M is the total number of tweets from the user and the users they follow.
    The code iterates over the tweets of the user and the users they follow, and it uses a priority queue (max heap) to get the most recent tweets. The priority queue operations have a time complexity of O(log M), where M is the size of the priority queue.

3) follow(int followerId, int followeeId):
    Time Complexity: O(1)
    Space Complexity: O(1)
    Inserting a followee to the set of followed users takes constant time.

4) unfollow(int followerId, int followeeId):
    Time Complexity: O(1)
    Space Complexity: O(1)
    Removing a followee from the set of followed users takes constant time.


Space Complexity:

1) userPost (unordered_map<int, vector<pair<int, int>>>):
    Space complexity: O(N + T), where N is the number of users, and T is the total number of tweets.
    Each user has a vector of tweet pairs, and the total number of tweets is the sum of all users' tweet counts.

2) userFollowing (unordered_map<int, set<int>>):
    Space complexity: O(N + F), where N is the number of users, and F is the total number of follow relationships.
    Each user has a set of followees, and the total number of follow relationships is the sum of all users' followee counts.

3) priority_queue (pq):
    Space complexity: O(M), where M is the total number of tweets considered in the news feed operation.
    The priority queue stores tweet pairs.

Overall Space Complexity: O(N + T + F + M)
*/


// class Twitter {
// public:
//     unordered_map<int, vector<pair<int, int>>> userPost;   // userId -> time, tweetId
//     unordered_map<int, set<int>> userFollowing;   // followerId -> followeeId
//     int time;

//     Twitter() {
//         time = 0;
//     }

//     void postTweet(int userId, int tweetId) {
//         userPost[userId].push_back({time++, tweetId});
//     }

//     /* Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
//     // vector<int> getNewsFeed(int userId) {
//     //     priority_queue<pair<int, int>, vector<pair<int, int>>> pq;      // maxHeap    time, tweetId
//     //     for(auto it = userPost[userId].begin(); it != userPost[userId].end(); it++){
//     //         pq.push(*it);
//     //     }

//     //     for(auto it1 = userFollowing[userId].begin(); it1 != userFollowing[userId].end(); it1++){
//     //         int user = *it1;      // get target user   (users who the user followed)
//     //         for(auto it2 = userPost[user].begin(); it2 != userPost[user].end(); it2++){
//     //             pq.push(*it2);
//     //         }
//     //     }

//     //     vector<int> tweets;
//     //     while(!pq.empty()){
//     //         auto it = pq.top();
//     //         pq.pop();
//     //         tweets.push_back(it.second);
//     //         if(tweets.size() == 10) break;
//     //     }

//     //     return tweets;
//     // }

//     /* OR */

//     vector<int> getNewsFeed(int userId) {
//         priority_queue<pair<int, int>, vector<pair<int, int>>> pq;         // maxHeap    time, tweetId

//         vector<pair<int, int>> userTweets = userPost[userId];
//         for(auto tweet : userTweets){
//             pq.push(tweet);
//         }

//         set<int> userFollows = userFollowing[userId];       // get target user   (users who the user followed)
//         for(auto user : userFollows){
//             vector<pair<int, int>> userTweets = userPost[user];
//             for(auto tweet : userTweets){
//                 pq.push(tweet);
//             }
//         }

//         vector<int> tweets;
//         while(!pq.empty()){
//             auto it = pq.top();
//             pq.pop();
//             tweets.push_back(it.second);
//             if(tweets.size() == 10){
//                 break;
//             }
//         }

//         return tweets;
//     }

//     /* Follower follows a followee */
//     void follow(int followerId, int followeeId) {
//         if(followerId != followeeId){
//             userFollowing[followerId].insert(followeeId);
//         }
//     }

//     /* Follower unfollows a followee */
//     void unfollow(int followerId, int followeeId) {
//         userFollowing[followerId].erase(followeeId);
//     }
// };



/* Solution 2: Using minHeap */
/*
Time Complexity:

1) postTweet(int userId, int tweetId):
    Time Complexity: O(1)
    Space Complexity: O(1)
    Appending a tweet to the user's tweet list takes constant time.

2) getNewsFeed(int userId):
    Time Complexity: O(M log 10) ~ O(M), where M is the total number of tweets from the user and the users they follow.
    The code iterates over the tweets of the user and the users they follow, and it uses a priority queue (min heap) to get the most recent tweets. The priority queue operations have a time complexity of O(log 10) ~ O(1), where 10 is the size of the priority queue.

3) follow(int followerId, int followeeId):
    Time Complexity: O(1)
    Space Complexity: O(1)
    Inserting a followee to the set of followed users takes constant time.

4) unfollow(int followerId, int followeeId):
    Time Complexity: O(1)
    Space Complexity: O(1)
    Removing a followee from the set of followed users takes constant time.


Space Complexity:

1) userPost (unordered_map<int, vector<pair<int, int>>>):
    Space complexity: O(N + T), where N is the number of users, and T is the total number of tweets.
    Each user has a vector of tweet pairs, and the total number of tweets is the sum of all users' tweet counts.

2) userFollowing (unordered_map<int, set<int>>):
    Space complexity: O(N + F), where N is the number of users, and F is the total number of follow relationships.
    Each user has a set of followees, and the total number of follow relationships is the sum of all users' followee counts.

3) priority_queue (pq):
    Space complexity: O(10) ~ O(1), where 10 is the total number of tweets considered in the news feed operation.
    The priority queue stores tweet pairs.

Overall Space Complexity: O(N + T + F)
*/


// class Twitter {
// public:
//     unordered_map<int, vector<pair<int, int>>> userPost;   // userId -> time, tweetId
//     unordered_map<int, set<int>> userFollowing;   // followerId -> followeeId
//     int time;

//     Twitter() {
//         time = 0;
//     }

//     void postTweet(int userId, int tweetId) {
//         userPost[userId].push_back({time++, tweetId});
//     }

//     /* Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
//     // vector<int> getNewsFeed(int userId) {
//     //     priority_queue<pair<int, int>, vector<pair<int, int>>> pq;      // maxHeap    time, tweetId
//     //     for(auto it = userPost[userId].begin(); it != userPost[userId].end(); it++){
//     //         pq.push(*it);
//     //     }

//     //     for(auto it1 = userFollowing[userId].begin(); it1 != userFollowing[userId].end(); it1++){
//     //         int user = *it1;      // get target user   (users who the user followed)
//     //         for(auto it2 = userPost[user].begin(); it2 != userPost[user].end(); it2++){
//     //             pq.push(*it2);
//     //         }
//     //     }

//     //     vector<int> tweets;
//     //     while(!pq.empty()){
//     //         auto it = pq.top();
//     //         pq.pop();
//     //         tweets.push_back(it.second);
//     //         if(tweets.size() == 10) break;
//     //     }

//     //     return tweets;
//     // }

//     /* OR */

//     vector<int> getNewsFeed(int userId) {
//         priority_queue<pair<int, int>, vector<pair<int, int>>> pq;         // maxHeap    time, tweetId

//         vector<pair<int, int>> userTweets = userPost[userId];
//         for(auto tweet : userTweets){
//             pq.push(tweet);
//         }

//         set<int> userFollows = userFollowing[userId];       // get target user   (users who the user followed)
//         for(auto user : userFollows){
//             vector<pair<int, int>> userTweets = userPost[user];
//             for(auto tweet : userTweets){
//                 pq.push(tweet);
//             }
//         }

//         vector<int> tweets;
//         while(!pq.empty()){
//             auto it = pq.top();
//             pq.pop();
//             tweets.push_back(it.second);
//             if(tweets.size() == 10){
//                 break;
//             }
//         }

//         return tweets;
//     }

//     /* Follower follows a followee */
//     void follow(int followerId, int followeeId) {
//         if(followerId != followeeId){
//             userFollowing[followerId].insert(followeeId);
//         }
//     }

//     /* Follower unfollows a followee */
//     void unfollow(int followerId, int followeeId) {
//         userFollowing[followerId].erase(followeeId);
//     }
// };