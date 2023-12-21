/* Codestudio  Submission    (Minimum Window Subsequence) */

/* Problem Statement: You are given two strings 'S' and 'T. Your task is to find the minimum (Contiguous) substring 'W' of 'S', 
such that 'T' is a subsequence of 'W' A subsequence is a sequence that can be derived from another sequence by removing zero or 
more elements, without changing the order. A substring is a contiguous part of a string. */



/* Solution 1: Brute Force */
// Time Complexity: O(N * N)    where N is the length of string S
// Space Complexity: O(1)     


// string minWindow(string S, string T)
// {
// 	string ans = "";
// 	int minLen = INT_MAX;
// 	for(int i = 0; i < S.size(); i++){
// 		string str = "";
// 		int k = 0;
// 		for(int j = i; j < S.size(); j++){
// 			str += S[j];
// 			if(S[j] == T[k]){
// 				k++;
// 			}
// 			if(k == T.size()){
// 				if(minLen > (j - i + 1)){
// 					minLen = j - i + 1;
// 					ans = str;
// 				}
// 				break;
// 			}
// 		}
// 	}

// 	return ans;
// }




/* Solution 2: Sliding Window */
/* As we are first moving forward, and then backwards. At ith iteration, in the worst case, we might have to traverse the 
string till the end. So at each index, if we are traversing the whole string again, complexity will be O(N ^ 2) */

// Time Complexity: O(N * N)            where N is the length of string S
// Space Complexity: O(1)   



// string minWindow(string S, string T)
// {
// 	int minLen = INT_MAX;
// 	int i = 0, j = 0, k = 0, start = 0;
// 	while(j < S.size()){
// 		if(S[j] == T[k]){
// 			k++;
// 		}
// 		// If we finally reach the end of string T, we can start shrinking our window
// 		if(k == T.size()){
// 			i = j;
// 			k = T.size() - 1;
// 			// We are doing k-- in order to minimise our window size
// 			// iterates backward from the current position of 'j' to find the minimum substring
// 			while(i >= 0 && k >= 0){
// 				if(S[i] == T[k]){
// 					k--;
// 				}
// 				i--;
// 			}
// 			i++;
// 			// Updating our window, if we found an element of minimum length
// 			if(minLen > (j - i + 1)){
// 				minLen = j - i + 1;
// 				start = i;
// 			}
// 			k = 0; 
// 			j = i;
			
// 		}
// 		j++;
// 	}

// 	if(minLen != INT_MAX){
// 		return S.substr(start, minLen);
// 	} 
// 	else{
// 		return "";
// 	}
// }