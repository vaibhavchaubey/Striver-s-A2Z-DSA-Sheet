/* Leetcode  Submission    (621. Task Scheduler) */

/* Problem Statement: Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents 
a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could 
complete either one task or just be idle.
However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), 
that is that there must be at least n units of time between any two same tasks.         
Return the least number of units of times that the CPU will take to finish all the given tasks. */



/* Solution 1: Using priority queue */
// Time complexity : O(N * log N)       (where N is the number of tasks)
// Space complexity : O(N)             (remain array)


// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         priority_queue<int> pq;         // maxHeap
//         vector<int> mp(26,0);

//         for(char i:tasks){
//             mp[i-'A']++;  // count the number of times a task needs to be done
//         }   

//         for(int i=0;i<26;++i){
//             if(mp[i]) {
//                 pq.push(mp[i]);
//             }
//         }

//         int time=0;   // stores the total time taken 
//         while(!pq.empty()){
//             vector<int>remain;
//             int cycle=n+1;    // n+1 is the CPU cycle length, if n is the cooldown period then after a task A there will be n more tasks. Hence n+1.

//             while(cycle and !pq.empty()){
//                 int max_freq=pq.top();   // the task at the top should be first assigned the CPU as it has highest frequency
//                 pq.pop();
//                 if(max_freq>1){   // task with more than one occurrence, the next occurrence will be done in the next cycle 
//                     remain.push_back(max_freq-1);   // add it to remaining task list
//                 }
//                 ++time; 
//                 --cycle; 
//             }

//             for(int count:remain){
//                 pq.push(count); 
//             }

//             if(pq.empty())break; // if the priority queue is empty than all tasks are completed and we don't need to include the idle time
//             time+=cycle; // this counts the idle time 
//         }

//         return time;
//     }
// };




/* Solution 2: By deducing a formula */
// Time complexity : O(N)       (where N is the number of tasks)
// Space complexity : O(1)     


/* Approach:-
Let's understand this with an example:

tasks= ['A','A','A','B','B','B','C','D'], n=2
Maximum frequency=3 and maximum occurring task= A,B
Here our possible solution is:

['A'->'B'->'C'] -> ['A','B','D'] ->['A','B']
total time: 3+3+2=8
Notice something: The cycle A->B->other_task is repeating 2 (maximum frequency-1) times and then A->B occurs.
A and B are the maximum frequency elements which are making the cycle of length 3(n+1).

We can say that

total time= (cycle length)*(maximum frequency-1) + number maximum frequency tasks that are left  
i.e total time=(n+1)*(max_freq-1)+count_maxfreq_task

In scenarios where the total time is less than the number of tasks, the minimum time required would be the number of tasks itself. */


// class Solution {
// public:

//     int leastInterval(vector<char>& tasks, int n) {
//         vector<int> mp(26,0);
//         int max_freq = 0, count_maxfreq = 0, sz = tasks.size();
//         for(char i : tasks){
//             mp[i-'A']++;           // count the number of times a task needs to be done
//             if(mp[i-'A'] > max_freq){
//                 max_freq = mp[i-'A'];       // find maximum frequency 
//             }
//         }   

//         for(int i = 0; i < 26; i++){
//             if(mp[i] == max_freq) count_maxfreq++;        // number of tasks having maximum frequency
//         }

//         int time = (max_freq-1) * (n+1) + count_maxfreq; // total time taken to complete all tasks
//         return max(time, sz);
//     }
// };