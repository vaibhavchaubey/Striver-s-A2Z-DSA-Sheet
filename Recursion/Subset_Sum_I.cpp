/* Codestudio  Submission   (Subset Sums)  */


/* Problem Statement: You are given an array 'nums' of ‘n’ integers. 
Return all subset sums of 'nums' in a non-decreasing order. */


/* Time Complexity: O(2^n) + O(2^n log(2^n))
Each index has two ways. You can either pick it up or not pick it. 
So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).

Space Complexity: O(2^n)         (recusion stack) */       


// void findSubSet(int ind, vector<int> &num, int N, vector<int>& ans, int sum){
// 	if(ind == N){
// 		ans.push_back(sum);
// 		return;
// 	}

// 	// element is picked
// 	sum += num[ind];
// 	findSubSet(ind+1, num, N, ans, sum);

// 	// element is not picked
// 	sum -= num[ind];
// 	findSubSet(ind+1, num, N, ans, sum);
// }

// vector<int> subsetSum(vector<int> &num){
// 	int N = num.size();
// 	vector<int> ans;
// 	findSubSet(0, num, N, ans, 0);
// 	sort(ans.begin(), ans.end());

// 	return ans;
// }




/* GFG  Submission   (Subset Sums)  */


/* Problem Statement: Given a list arr of N integers, print sums of all subsets in it. */


/* Time Complexity: O(2^n) + O(2^n log(2^n))
Each index has two ways. You can either pick it up or not pick it. 
So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).

Space Complexity: O(2^n)         (recusion stack) */       


// class Solution 
// {
// public:
//     void findSubSet(int ind, vector<int> arr, int N, vector<int>& ans, int sum){
//         if(ind == N){
//             ans.push_back(sum);
//             return;
//         }
//         // element is picked
//         sum += arr[ind];
//         findSubSet(ind+1,arr,N,ans,sum);
        
//         // element is not picked
//         sum -= arr[ind];
//         findSubSet(ind+1,arr,N,ans,sum);
//     }
//     vector<int> subsetSums(vector<int> arr, int N)
//     {
//         vector<int> ans;
//         findSubSet(0, arr, N, ans, 0);
//         sort(ans.begin(), ans.end());
        
//         return ans;
//     }
// };