/* GFG  Submission    (Missing number) */

/* Problem Statement: Vaibhav likes to play with numbers and he has N numbers. 
One day he was placing the numbers on the playing board just to count that how many numbers he has. 
He was placing the numbers in increasing order i.e. from 1 to N. But when he was putting the numbers back into his bag, 
some numbers fell down onto the floor. He picked up all the numbers but one number, he couldn't find. 
Now he has to go somewhere urgently, so he asks you to find the missing number.
NOTE: Don't use Sorting */


/* Solution 1: using Hashing  */
// Time Complexity: O(2N)
// Space Complexity: O(N)


// int missingNumber(int A[], int N)
// {
//     unordered_map<int, int> mp;
//     for(int i = 0; i < N-1; i++){
//         mp[A[i]]++;
//     }

//     for(int i = 1; i <= N; i++){
//         if(mp[i] == 0){
//             return i;
//         }
//     }

//     return -1;
// }



/* Solution 2: Summation Approach */
// Time Complexity: O(N)
// Space Complexity: O(1) 


// int missingNumber(int A[], int N)
// {
//     int totalSum = (N * (N + 1)) / 2;            // Sum of all numbers from 1 to N
//     int sum = 0;
//     for(int i = 0; i < N-1; i++){
//         sum += A[i];
//     }
    
//     int ans = totalSum - sum;
    
//     return ans;
// }



/* Solution 3: XOR Approach: */
// Time Complexity: O(N)
// Space Complexity: O(1) 


/* XOR Property */
// XOR of same number is 0   (2 ^ 2 = 0)
// XOR of any number with 0 is the number itself     (0 ^ 2 = 2)


// int missingNumber(int A[], int N)
// {
//     int XOR1 = 0;       // XOR of all numbers from 1 to N
//     int XOR2 = 0;       // XOR of all numbers in A[]
//     for(int i = 0; i < N-1; i++){
//         XOR2 ^= A[i];
//         XOR1 ^= i+1; 
//     }
    
//     XOR1 ^= N;
    
//     // Same number will cancel out and at last we get our missing number
//     int ans = XOR1 ^ XOR2;
    
//     return ans;
// }