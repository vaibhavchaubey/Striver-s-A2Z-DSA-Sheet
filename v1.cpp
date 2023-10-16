#include <iostream>
#include <vector>

using namespace std;

vector<int> Solve(int N, int K, vector<int>& parents, vector<int>& salary_order) {
    vector<bool> receivedSalary(N, false); // Initialize an array to track who received the salary
    vector<int> result;

    for (int i = 0; i < K; i++) {
        int currentMember = salary_order[i];

        while (currentMember != -1 && !receivedSalary[currentMember]) {
            receivedSalary[currentMember] = true;
            currentMember = parents[currentMember];
        }
    }

    for (int i = 0; i < N; i++) {
        if (receivedSalary[i]) {
            result.push_back(i);
        }
    }

    return result;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> parents(N);
    vector<int> salary_order(K);

    for (int i = 0; i < N; i++) {
        cin >> parents[i];
    }

    for (int i = 0; i < K; i++) {
        cin >> salary_order[i];
    }

    vector<int> result = Solve(N, K, parents, salary_order);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
