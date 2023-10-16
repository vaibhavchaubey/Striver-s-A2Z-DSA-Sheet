#include <iostream>
#include <vector>
using namespace std;

int countCombinations(const vector<int>& pieces, int K) {
    int N = pieces.size();
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

    dp[0][0] = 1; // Base case: There's one way to make a sum of 0 (no pieces used).

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= K; ++j) {
            dp[i][j] = dp[i - 1][j]; // Exclude the current piece.

            if (j >= pieces[i - 1]) {
                dp[i][j] += dp[i - 1][j - pieces[i - 1]]; // Include the current piece.
            }
        }
    }

    return dp[N][K] - 2;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> pieces(N);
    for (int i = 0; i < N; ++i) {
        cin >> pieces[i];
    }

    int combinations = countCombinations(pieces, K);
    cout << combinations << endl;

    return 0;
}
