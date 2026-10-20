/* GFG  Submission    (N meetings in one room) */

/* Problem Statement: You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 

Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting. */


/* Solution: Greedy Algorithm */
/* Approach: The idea is to solve the problem using the greedy approach which is the same as Activity Selection Problem i.e sort 
the meetings by their finish time and then start selecting meetings, starting with the one with least end time and then select 
other meetings such that the start time of the current meeting is greater than the end time of last meeting selected */

// Time Complexity: O(N logN)
// Space Complexity: O(N)


// class Solution {
//   public:
//     static bool comp(pair<int, int> &a, pair<int, int> &b){
//         return a.second < b.second;
//     }
//     // Function to find the maximum number of meetings that can
//     // be performed in a meeting room.
//     int maxMeetings(vector<int>& start, vector<int>& end) {
//         int n = start.size();
//         vector<pair<int, int>> meetings;
//         for(int i = 0; i < n; i++){
//             meetings.push_back({start[i], end[i]});
//         }
        
//         sort(meetings.begin(), meetings.end(), comp);
        
//         int ans = 1;
//         int finish =  meetings[0].second;
        
//         for(int i = 1; i < n; i++){
//             if(meetings[i].first > finish){
//                 ans++;
//                 finish = meetings[i].second;
//             }
//         }
        
//         return ans;
//     }
// };



/* If we want to Print all meeting numbers */



/* GFG  Submission    (Maximum Meetings in One Room) */

/* Problem Statement: Given two arrays s[] and f[], where s[i] and f[i] denote the start time and finish time of the ith meeting, respectively. There is only one meeting room. A meeting can be scheduled only if its start time is strictly greater than the finish time of the previously selected meeting.

Find the maximum number of meetings that can be scheduled in the room such that no two selected meetings overlap. Return the indices (1-based) of the selected meetings in sorted (increasing) order.

Note: If multiple schedules are possible, prefer meetings with earlier finish times. If two meetings have the same finish time, prefer the meeting with the smaller index. */


/* Solution: Greedy Algorithm */
/* Approach: The idea is to solve the problem using the greedy approach which is the same as Activity Selection Problem i.e sort 
the meetings by their finish time and then start selecting meetings, starting with the one with least end time and then select 
other meetings such that the start time of the current meeting is greater than the end time of last meeting selected */

// Time Complexity: O(N logN)
// Space Complexity: O(N)


// class Solution {
//   public:
//     vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
//         int n = s.size();
//         vector<pair<int, int>> arr;
        
//         for(int i = 0; i < n; i++){
//             arr.push_back({f[i], i});
//         }
        
//         sort(arr.begin(), arr.end());
        
//         vector<int> ans;
        
//         int finish = arr[0].first;
        
//         // Initially select first meeting.
//         ans.push_back(arr[0].second + 1);
        
//         for(int i = 1; i < n; i++){
//             if(s[arr[i].second] > finish){
//                 finish = arr[i].first;
//                 ans.push_back(arr[i].second + 1);
//             }
//         }
        
//         sort(ans.begin(), ans.end());
        
//         return ans;
//     }
// };




///////////////////////////////////////////////////////////////////////////////////////






// // C++ program to find maximum number of meetings
// #include <bits/stdc++.h>
// using namespace std;

// // Function for finding maximum meeting in one room
// void maxMeetings(int s[], int f[], int N)
// {
// 	pair<int, int> a[N + 1];
// 	int i;
// 	for (i = 0; i < N; i++) {
// 		a[i].first = f[i];
// 		a[i].second = i;
// 	}

// 	// Sorting of meeting according to their finish time.
// 	sort(a, a + N);

// 	// Time_limit to check whether new
// 	// meeting can be conducted or not.
// 	int time_limit = a[0].first;

// 	// Vector for storing selected meeting.
// 	vector<int> m;

// 	// Initially select first meeting.
// 	m.push_back(a[0].second + 1);

// 	// Check for all meeting whether it
// 	// can be selected or not.
// 	for (i = 1; i < N; i++) {
// 		if (s[a[i].second] > time_limit) {
// 			// Push selected meeting to vector
// 			m.push_back(a[i].second + 1);

// 			// update time limit
// 			time_limit = a[i].first;
// 		}
// 	}

// 	// Print final selected meetings.
// 	for (int i = 0; i < m.size(); i++) {
// 		cout << m[i] << " ";
// 	}
// }

// // Driver's code
// int main()
// {
// 	// Starting time
// 	int s[] = { 1, 3, 0, 5, 8, 5 };

// 	// Finish time
// 	int f[] = { 2, 4, 6, 7, 9, 9 };

// 	// Number of meetings.
// 	int N = sizeof(s) / sizeof(s[0]);

// 	// Function call
// 	maxMeetings(s, f, N);

// 	return 0;
// }
