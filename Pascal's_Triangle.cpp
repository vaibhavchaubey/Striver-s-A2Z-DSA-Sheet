/* Leetcode  Submission    (118. Pascal's Triangle) */

/* Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle. (Means print the entire pascal triangle) */

/* Problem Statement: Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it. */


/* Solution: */
// Time Complexity: O(N * N)
// Space Complexity: O(1)


// class Solution {
// public:
//     vector<int> generateRow(int row){
//         long long ans = 1;
//         vector<int> ansRow;
//         ansRow.push_back(1);        //inserting the 1st element

//         //calculate the rest of the elements
//         for(int col = 1; col < row; col++){
//             ans = ans * (row - col);
//             ans = ans / col;
//             ansRow.push_back(ans);
//         }

//         return ansRow;
//     }
//     vector<vector<int>> generate(int numRows) {
//         int n = numRows;
//         vector<vector<int>> ans;
//         // store the entire pascal's triangle
//         for(int row = 1; row <= n; row++){
//             ans.push_back(generateRow(row));
//         }

//         return ans;
//     }
// };


/*                                  OR                              */


/* Solution: */
// Time Complexity: O(N * N)
// Space Complexity: O(1)


// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> ans(numRows);
        
//         for(int i = 0; i < numRows; i++){
//             ans[i].resize(i+1);
//             for(int j = 0; j <= i; j++){    
//                 if(j == 0 || j == i){       // for first and last element
//                     ans[i][j] = 1;
//                 }
//                 else{
//                     ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
//                 }
//             }
//         }
        
//         return ans;
//     }
// };


///////////////////////////////////////////////////////////////////////////////////////////////////


/* Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle. */
/* We have an easier formula to find out the element i.e. r-1Cc-1. */


/* Naive Approach: 
We can separately calculate n!, r!, (n-r)! and using their values we can calculate nCr. 
This is an extremely naive way to calculate. The time complexity will be O(n)+O(r)+O(n-r). */



/* Optimal Approach
Approach:
The steps are as follows:
1) First, we will consider r-1 as n and c-1 as r.
2) After that, we will simply calculate the value of the combination using a loop. 
3) The loop will run from 0 to r. And in each iteration, we will multiply (n-i) with the result and divide the result by (i+1).
4) Finally, the calculated value of the combination will be our answer. */


/* Solution: */
// Time Complexity: O(c)      where c = given column number. Reason: We are running a loop for r times, where r is c-1.
// Space Complexity: O(1)    


// #include <bits/stdc++.h>
// using namespace std;

// int nCr(int n, int r) {
//     long long res = 1;

//     // calculating nCr:
//     for (int i = 0; i < r; i++) {
//         res = res * (n - i);
//         res = res / (i + 1);
//     }
//     return res;
// }

// int pascalTriangle(int r, int c) {
//     int element = nCr(r - 1, c - 1);
//     return element;
// }

// int main()
// {
//     int r = 5; // row number
//     int c = 3; // col number
//     int element = pascalTriangle(r, c);
//     cout << "The element at position (r,c) is: " << element << "n";


//     return 0;
// }


////////////////////////////////////////////////////////////////////////////////////////////////////////


/* Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle. */


/* Naive Approach
In this approach, for every column from 1 to n, we will calculate the element (n, c)
(where n is the given row number and c is the column number that will vary from 1 to n) using the previous method. 
Thus, we will print the row.   */


/* Solution 1: */
// Time Complexity: O(n*r)       where n is the given row number, and r is the column index which can vary from 0 to n-1.
// Space Complexity: O(1) 


// #include <bits/stdc++.h>
// using namespace std;

// int nCr(int n, int r) {
//     long long res = 1;

//     // calculating nCr:
//     for (int i = 0; i < r; i++) {
//         res = res * (n - i);
//         res = res / (i + 1);
//     }
//     return res;
// }

// void pascalTriangle(int n) {
//     // printing the entire row n:
//     for (int c = 1; c <= n; c++) {
//         cout << nCr(n - 1, c - 1) << " ";
//     }
// }

// int main()
// {
//     int n = 5;
//     pascalTriangle(n);
//     return 0;
// }



/* Optimal Approach
Approach:
The steps are as follows:
1) First, we will print the 1st element i.e. 1 manually.
2) After that, we will use a loop(say i) that runs from 1 to n-1. It will print the rest of the elements.
3) Inside the loop, we will use the above-said formula to print the element. We will multiply the previous answer by (n-i) and then divide it by i itself.
4) Thus, the entire row will be printed. */


/* Solution 2: */
// Time Complexity: O(N)                    where N = given row number.
// Space Complexity: O(1) 


// #include <bits/stdc++.h>
// using namespace std;

// void pascalTriangle(int n) {
//     long long ans = 1;
//     cout << ans << " "; // printing 1st element

//     //Printing the rest of the part:
//     for (int i = 1; i < n; i++) {
//         ans = ans * (n - i);
//         ans = ans / i;
//         cout << ans << " ";
//     }
//     cout << endl;
// }

// int main()
// {
//     int n = 5;
//     pascalTriangle(n);

//     return 0;
// }


////////////////////////////////////////////////////////////////////////////////////////////////////////


/* Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle. (Means print the entire pascal triangle) */


/* Naive Approach
Approach:
The steps are as follows:
1) First, we will run a loop(say row) from 1 to n.
2) We will use a loop(say col) to iterate over each column i.e. from 1 to n. And inside the nested loops, we will do the following steps:
    1) First, we will consider row-1 as n and col-1 as r.
    2) After that, we will simply calculate the value of the combination using a loop. 
    3) The loop will run from 0 to r. And in each iteration, we will multiply (n-i) with the result and divide the result by (i+1).
    4) Finally, we will add the element to a temporary list.
3) After calculating all the elements for all columns of a row, we will add the temporary list to our final answer list.
4) Finally, we will return the answer list. */


/* Solution 1: */
// Time Complexity: O(n*n*r) ~ O(n^3)               where n = number of rows, and r = column index.
// Space Complexity: O(1) 


// #include <bits/stdc++.h>
// using namespace std;

// int nCr(int n, int r) {
//     long long res = 1;

//     // calculating nCr:
//     for (int i = 0; i < r; i++) {
//         res = res * (n - i);
//         res = res / (i + 1);
//     }
//     return (int)(res);
// }

// vector<vector<int>> pascalTriangle(int n) {
//     vector<vector<int>> ans;

//     //Store the entire pascal's triangle:
//     for (int row = 1; row <= n; row++) {
//         vector<int> tempLst; // temporary list
//         for (int col = 1; col <= row; col++) {
//             tempLst.push_back(nCr(row - 1, col - 1));
//         }
//         ans.push_back(tempLst);
//     }
//     return ans;
// }

// int main()
// {
//     int n = 5;
//     vector<vector<int>> ans = pascalTriangle(n);
//     for (auto it : ans) {
//         for (auto ele : it) {
//             cout << ele << " ";
//         }
//         cout << "n";
//     }
//     return 0;
// }



/* Optimal Approach
Now, in the optimal approach of variation 2, we have learned how to generate a row in O(n) time complexity. 
So, in order to optimize the overall time complexity, we will be using that approach for every row. 
Thus the total time complexity will reduce. */


/* Solution 2: */
// Time Complexity: O(N * N)       where N = number of rows
// Space Complexity: O(1) 


// #include <bits/stdc++.h>
// using namespace std;

// vector<int> generateRow(int row) {
//     long long ans = 1;
//     vector<int> ansRow;
//     ansRow.push_back(1); //inserting the 1st element

//     //calculate the rest of the elements:
//     for (int col = 1; col < row; col++) {
//         ans = ans * (row - col);
//         ans = ans / col;
//         ansRow.push_back(ans);
//     }
//     return ansRow;
// }

// vector<vector<int>> pascalTriangle(int n) {
//     vector<vector<int>> ans;

//     //store the entire pascal's triangle:
//     for (int row = 1; row <= n; row++) {
//         ans.push_back(generateRow(row));
//     }
//     return ans;
// }

// int main()
// {
//     int n = 5;
//     vector<vector<int>> ans = pascalTriangle(n);
//     for (auto it : ans) {
//         for (auto ele : it) {
//             cout << ele << " ";
//         }
//         cout << "n";
//     }
//     return 0;
// }




