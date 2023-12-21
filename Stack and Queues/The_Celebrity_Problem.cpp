/* Codestudio  Submission      (The Celebrity Problem) */

/* Problem Statement: There are 'N° people at a party. Each person has been assigned a unique id between O to 'N' - 1(both inclusive). 
A celebrity is a person who is known to everyone but does not know anyone at the party. Given a helper function 'knows(A, B)', 
It will returns "true" if the person having id 'A' know the person having id 'B' in the party, "false" otherwise. 
Your task is to find out the celebrity at the party. Print the id of the celebrity, if there is no celebrity at the 
party then print - 1. */



/* Solution 1: Graph(indegree, outdegree)           (It will give TLE) */
/* Approach: This problem can be modelled as a graph problem. Consider a directed graph having ‘N’ nodes numbered from 0 to ‘N’ - 1.  
If the helper function ‘knows(i, j)’ returns true, then it means that there is a directed edge from node ‘i’ to node ‘j’.  
We can observe that if the celebrity is present then it is represented by a global sink i.e node that has indegree n-1 and outdegree 0. */

// Time Complexity: O(N * N) 
// Space Complexity: O(N) 


// #include <bits/stdc++.h> 
// int findCelebrity(int n) {
// 	vector<int> indegree(n);
// 	vector<int> outdegree(n);
// 	for(int i = 0; i < n; i++){
// 		for(int j = 0; j < n; j++){
// 			if(knows(i, j)){
// 				indegree[j]++;
// 				outdegree[i]++;
// 			}
// 		}
// 	}

// 	int celebrity = -1;
// 	for(int i = 0; i < n; i++){
// 		if(indegree[i] == n-1 && outdegree[i] == 0){
// 			celebrity = i;
// 			break;
// 		}
// 	}

// 	return celebrity;
// }




/* Solution 2:   (It will give TLE) */
/* Approach: check one by one whether the person is a celebrity or not? */

// Time Complexity: O(N * N) 
// Space Complexity: O(1) 


// #include <bits/stdc++.h> 
// int findCelebrity(int n) {
// 	int celebrity = -1;
// 	// Check one by one whether the person is a celebrity or not.
// 	for(int i = 0; i < n; i++){
// 		bool knowAny = false, knownAll = true;   	// condition for celebrity

// 		// Check whether perosn with id 'i' knows any other person.
// 		for(int j = 0; j < n; j++){
// 			if(knows(i, j)){
// 				knowAny = true;
// 				break;
// 			}
// 		}
		
// 		// Check whether perosn with id 'i' is known to all the other person.
// 		for(int j = 0; j < n; j++){
// 			if(i != j && knows(j, i) == 0){
// 				knownAll = false;
// 				break;
// 			}
// 		}

// 		if(knowAny == false && knownAll == true){
// 			celebrity = i;
// 			break;
// 		}
// 	}

// 	return celebrity;
// }




/* Solution 3:  Using Stack  */
/* Approach: push all the ids in the stack, and try to pop out those that cannot be the id of the celebrity.
If for any pair (i, j)  such that ‘i’!= ‘j’, if  ‘knows(i, j)’ returns true, then it implies that the person having id ‘i’ 
cannot be a celebrity as it knows the person having id ‘j’. Similarly if ‘knows(i, j)’ returns false, then it implies that 
the person having id ‘j’ cannot be a celebrity as it is not known by a person having id ‘i’. We can use this observation to 
solve this problem. */

// Time Complexity: O(N) 
// Space Complexity: O(N) 


// #include <bits/stdc++.h>
// int findCelebrity(int n) {
// 	// Create a stack and push all ids in it
// 	stack<int> st;
// 	for(int i = 0; i < n; i++){
// 		st.push(i);
// 	}

// 	// Finding celebrity
// 	while(st.size() > 1){
// 		int i = st.top();
// 		st.pop();
// 		int j = st.top();
// 		st.pop();
		
// 		if(knows(i, j)){
// 			// Because the person having id ‘i’ cannot be a celebrity as it knows the person having id ‘j’
// 			st.push(j);
// 		}
		
// 		else{				// knows(i, j) == false
// 			// Because the person having id ‘j’ cannot be a celebrity as it is not known by a person having id ‘i’
// 			st.push(i);
// 		}
// 	}

// 	int celebrity = st.top();
// 	bool knowAny = false, knownToAll = true;   	// condition for celebrity
	
// 	// Verify whether the celebrity knows any other person
// 	for(int i = 0; i < n; i++){
// 		if(knows(celebrity, i)){
// 			knowAny = true;
// 			break;
// 		}
// 	}
	
// 	// Verify whether the celebrity is known to all the other person
// 	for(int i = 0; i < n; i++){
// 		if(i != celebrity && knows(i, celebrity) == 0){
// 			knownToAll = false;
// 			break;
// 		}
// 	}

// 	if(knowAny == true || knownToAll == false){
// 		celebrity = -1;
// 	}

// 	return celebrity;
// }




/* Solution 4:  Two Pointer Approach   */
/* Approach: Similar to Stack approach, here instead of stack we use two pointer
Run a while loop till 'P' < ‘Q’ and in each iteration do the following.
1)  If ‘knows(P, Q)’ returns true, then increment ‘P’ by 1.
2)  If ‘knows(P, Q)’ returns false, then decrement ‘Q’ by 1.

If for any pair (i, j)  such that ‘i’!= ‘j’, if  ‘knows(i, j)’ returns true, then it implies that the person having id ‘i’ 
cannot be a celebrity as it knows the person having id ‘j’. Similarly if ‘knows(i, j)’ returns false, then it implies that 
the person having id ‘j’ cannot be a celebrity as it is not known by a person having id ‘i’. 
So, the Two Pointer approach can be used where two pointers can be assigned, one at the start and the other at the end of the 
elements to be checked, and the search space can be reduced.  */

// Time Complexity: O(N) 
// Space Complexity: O(1) 


// int findCelebrity(int n) {
// 	// Two pointers pointing at start and end of search space
// 	int i = 0, j = n-1;

// 	// Finding celebrity
// 	while(i < j){
// 		if(knows(i, j)){
// 			// Because the person having id ‘i’ cannot be a celebrity as it knows the person having id ‘j’
// 			i++;
// 		}
		
// 		else{				// knows(i, j) == false
// 			// Because the person having id ‘j’ cannot be a celebrity as it is not known by a person having id ‘i’
// 			j--;
// 		}
// 	}

// 	int celebrity = i;
// 	bool knowAny = false, knownToAll = true;   	// condition for celebrity
	
// 	// Verify whether the celebrity knows any other person
// 	for(int i = 0; i < n; i++){
// 		if(knows(celebrity, i)){
// 			knowAny = true;
// 			break;
// 		}
// 	}
	
// 	// Verify whether the celebrity is known to all the other person
// 	for(int i = 0; i < n; i++){
// 		if(i != celebrity && knows(i, celebrity) == 0){
// 			knownToAll = false;
// 			break;
// 		}
// 	}

// 	if(knowAny == true || knownToAll == false){
// 		celebrity = -1;
// 	}

// 	return celebrity;
// }



