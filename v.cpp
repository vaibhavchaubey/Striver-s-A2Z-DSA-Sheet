

/* Intuition
We can solve this problem by using DP as after reading question we can observe that there is variable starting point and variable 
ending point as we start at any building in first row and have to reach any building in the last row and hence there can be 
multiple ways reaching the last row and from that possible ways we have to take the path which give minimum energy. */


/* Approach
We can start at any of the building int the first row. 
Now we can move by making Only valid moves in next buildings in 4 directions (up, left, down, right). 
When we move to next building we use absolute of difference in height between the current building and the next building. */


/* Solution: Using Tabulation */
// Time Complexity: O(rows * cols)
// Space Complexity: O(rows * cols)

#include <bits/stdc++.h>
using namespace std;

int minimunEnergyNeeded(vector<vector<int>>& buildings) {
    int rows = buildings.size();
    int cols = buildings[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));
    
    // Base Condition
    for (int col = 0; col < cols; col++) {
        dp[0][col] = 0;
    }
    
    for (int i = 1; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // 4 dir: up, left, down, right.
            int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
            for (int k = 0; k < 4; k++) {
                int row = i + dir[k][0];
                int col = j + dir[k][1];
                
                if (row >= 0 && row < rows && col >= 0 && col < cols) {
                    // calculate energy 
                    int energy = buildings[i][j] - buildings[row][col];
                    dp[i][j] = min(dp[i][j], max(dp[row][col], abs(energy)));
                }
            }
        }
    }

    int mininumEnergy = INT_MAX;
    for (int j = 0; j < cols; j++) {
        mininumEnergy = min(mininumEnergy, dp[rows - 1][j]);
    }
    
    return mininumEnergy;
}

int main() {

    // vector<vector<int>> buildings = {{2, 5, 3}, {1, 4, 5}, {3, 2, 2}};        // ans => 2

    vector<vector<int>> buildings = {{2, 3}, {1, 4}};                       // ans => 1
    
    int ans = minimunEnergyNeeded(buildings);
    cout << "Minimum Energy Needed: " << ans << endl;


    return 0;
}
