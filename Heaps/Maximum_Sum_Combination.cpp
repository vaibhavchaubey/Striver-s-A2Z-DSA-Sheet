/* InterviewBit  Submission    (Maximum Sum Combinations) */

/* Problem Statement: Given two equally sized 1-D arrays A, B containing N integers each.
A sum combination is made by adding one element from array A and another element of array B.
Return the maximum C valid sum combinations from all the possible sum combinations. */



/* Solution: Using priority queue */
/* 
Time Complexity:

    1) Sorting arrays A and B: O(N log N), where N is the size of the arrays.
    2) Building the priority queue: O(K log N), where K is the number of combinations to find and N is the size of the arrays.
    3) Iterating K times to find the maximum combinations: O(K log N).

    The dominant factor is the sorting step, so the overall time complexity is O(N log N).

Space Complexity:

    1) Vector ans: O(K) for storing the K maximum combinations.
    2) Priority queue pq: O(N) for storing the combinations, as the priority queue may contain at most N elements.
    3) Set my_set: O(N) for storing unique pairs of indices.
    The dominant factor is the priority queue, so the overall space complexity is O(N). 
*/


// vector<int> KMaxCombinations(vector<int>& A,vector<int>& B, int K)
// {
//     // sort both arrays A and B
//     sort(A.begin(), A.end());
//     sort(B.begin(), B.end());
//     vector<int> ans;
//     int N = A.size();

//     // Max heap which contains tuple of the format
//     // (sum, (i, j)) i and j are the indices
//     // of the elements from array A
//     // and array B which make up the sum.
//     priority_queue<pair<int, pair<int, int>>> pq; 

//     // my_set is used to store the indices of
//     // the  pair(i, j) we use my_set to make sure
//     // the indices doe not repeat inside max heap.
//     set<pair<int, int> > my_set;

//     // initialize the heap with the maximum sum
//     // combination ie (A[N - 1] + B[N - 1])
//     // and also push indices (N - 1, N - 1) along
//     // with sum.
//     pq.push(make_pair(A[N - 1] + B[N - 1],
//                       make_pair(N-1, N-1)));

//     my_set.insert(make_pair(N - 1, N - 1));

//     // iterate upto K
//     for (int count = 0; count < K; count++) {

//         // tuple format (sum, (i, j)).
//         pair<int, pair<int, int> > temp = pq.top();
//         pq.pop();

//         ans.push_back(temp.first);

//         int i = temp.second.first;
//         int j = temp.second.second;

//         if(i - 1 >= 0){
//             int sum = A[i - 1] + B[j];

//             // insert (A[i - 1] + B[j], (i - 1, j))
//             // into max heap.
//             pair<int, int> temp1 = make_pair(i - 1, j);

//             // insert only if the pair (i - 1, j) is
//             // not already present inside the map i.e.
//             // no repeating pair should be present inside
//             // the heap.
//             if (my_set.find(temp1) == my_set.end()) {
//                 pq.push(make_pair(sum, temp1));
//                 my_set.insert(temp1);
//             }
//         }

//         // insert (A[i] + B[j - 1], (i, j - 1))
//         // into max heap
//         if(j - 1 >= 0){
//             int sum = A[i] + B[j - 1];
//             pair<int,int> temp1 = make_pair(i, j - 1);

//             // insert only if the pair (i, j - 1)
//             // is not present inside the heap.
//             if (my_set.find(temp1) == my_set.end()) {
//                 pq.push(make_pair(sum, temp1));
//                 my_set.insert(temp1);
//             }
//         }
//     }
    
//     return ans;
// }
// vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
//     vector<int>temp = KMaxCombinations(A,B,C);
    
//     return temp;
// }