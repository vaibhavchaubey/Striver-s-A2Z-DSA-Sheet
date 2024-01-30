/* GFG  Submission    (N meetings in one room) */

/* Problem Statement: There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] 
is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the 
meeting room at a particular time?
Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting. */


/* Solution: Greedy Algorithm */
/* Approach: The idea is to solve the problem using the greedy approach which is the same as Activity Selection Problem i.e sort 
the meetings by their finish time and then start selecting meetings, starting with the one with least end time and then select 
other meetings such that the start time of the current meeting is greater than the end time of last meeting selected */

// Time Complexity: O(N logN)
// Space Complexity: O(N)


// class Solution
// {
//     public:
//     static bool comp(pair<int, int> &a, pair<int, int> &b){
//         return a.second < b.second;
//     }
//     //Function to find the maximum number of meetings that can
//     //be performed in a meeting room.
//     int maxMeetings(int start[], int end[], int n)
//     {
//         vector<pair<int, int>> arr;         // start[i], end[i]
//         for(int i = 0; i < n; i++){
//             arr.push_back({start[i], end[i]});
//         }
        
//         sort(arr.begin(), arr.end(), comp);
        
//         int ans = 1;
//         int finish = arr[0].second;
//         for(int i = 1; i < n; i++){
//             if(arr[i].first > finish){
//                 ans++;
//                 finish = arr[i].second;
//             }
//         }
        
//         return ans;    
//     }   
// };



/* If we want to Print all meeting numbers */


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
