/* GFG  Submission   (Rat in a Maze Problem - I)  */


/* Problem Statement: Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach 
the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to 
destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). 
Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at 
a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move 
to any other cell. */



/* Solution 1: Backtracking */
/* Time Complexity: O(4^N*N)            // because on every cell we need to try 4 different directions.
Space Complexity: O(N*N)               // Maximum Depth of the recursion tree(auxiliary space). */


// class Solution{
//     public:
//     void solve(int i, int j, vector<vector<int>>& m, int n, vector<string>& ans, string move, vector<vector<int>>& vis){
//         if(i == n-1 && j == n-1){
//             ans.push_back(move);
//             return;
//         }

//         //downward
//         if(i+1<n && !vis[i+1][j] && m[i+1][j] == 1){
//             vis[i][j] = 1;
//             solve(i+1,j,m,n,ans,move+'D',vis);
//             // backtracking
//             vis[i][j] = 0;
//         }

//         //left
//         if(j-1>=0 && !vis[i][j-1] && m[i][j-1] == 1){
//             vis[i][j] = 1;
//             solve(i,j-1,m,n,ans,move+'L',vis);
//             // backtracking
//             vis[i][j] = 0;
//         }

//         //right
//         if(j+1<n && !vis[i][j+1] && m[i][j+1] == 1){
//             vis[i][j] = 1;
//             solve(i,j+1,m,n,ans,move+'R',vis);
//             // backtracking
//             vis[i][j] = 0;
//         }

//         //upward
//         if(i-1>=0 && !vis[i-1][j] && m[i-1][j] == 1){
//             vis[i][j] = 1;
//             solve(i-1,j,m,n,ans,move+'U',vis);
//             // backtracking
//             vis[i][j] = 0;
//         }
//     }
//     vector<string> findPath(vector<vector<int>> &m, int n) {
//         vector<string> ans;
//         vector<vector<int>> vis(n, vector<int>(n, 0));
//         if(m[0][0] == 1){
//             solve(0,0,m,n,ans,"",vis);
//         }

//         return ans;
//     }
// };



    
/* Solution 2: Backtracking */          //    (Here we converted our 4 if statement code into 1 for loop)
/* Time Complexity: O(4^N*N)            // because on every cell we need to try 4 different directions.
Space Complexity: O(N*N)               // Maximum Depth of the recursion tree(auxiliary space). */


// class Solution{
//     public:
//     void solve(int i, int j, vector<vector<int>> &m, int n, vector<string> &ans, string move, vector<vector<int>> &vis, int di[], int dj[]){
//         if(i == n-1 && j == n-1){
//             ans.push_back(move);
//             return;
//         }

//         string dir = "DLRU";
//         for(int ind = 0; ind < 4; ind++){
//             int nexti = i + di[ind];
//             int nextj = j + dj[ind];
//             if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && m[nexti][nextj] == 1){
//                 vis[i][j] = 1;
//                 solve(nexti,nextj,m,n,ans,move + dir[ind],vis,di,dj);
//                 vis[i][j] = 0;
//             }
//         }
//     }
//     vector<string> findPath(vector<vector<int>> &m, int n) {
//         vector<string> ans;
//         vector<vector<int>> vis(n,vector<int>(n,0));
//         int di[] = {1,0,0,-1};
//         int dj[] = {0,-1,1,0};
//         if(m[0][0] == 1){
//             solve(0, 0, m, n, ans, "", vis, di, dj);
//         }

//         return ans;
//     }
// };