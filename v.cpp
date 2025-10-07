#include <bits/stdc++.h>
using namespace std;

vector<int> maxCombinations(vector<int> &nums1, vector<int> &nums2, int k)
{
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    vector<int> ans;
    int n = nums1.size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>> pq; // sum, (i, j)

    set<pair<int, int>> st; // (i, j)

    pq.push({nums1[n - 1] + nums2[n - 1], {n - 1, n - 1}});
    st.insert({n - 1, n - 1});

    for (int cnt = 0; cnt < k; cnt++)
    {
        pair<int, pair<int, int>> top = pq.top();
        pq.pop();

        int sum = top.first;
        int i = top.second.first;
        int j = top.second.second;

        ans.push_back(sum);

        if (i - 1 >= 0)
        {
            int sum = nums1[i - 1] + nums2[j];
            pair<int, int> indexes = {i - 1, j};

            if (st.count(indexes) == 0)
            {
                pq.push({sum, indexes});
                st.insert(indexes);
            }
        }

        if (j - 1 >= 0)
        {
            int sum = nums1[i] + nums2[j - 1];
            pair<int, int> indexes = {i, j - 1};

            if (st.count(indexes) == 0)
            {
                pq.push({sum, indexes});
                st.insert(indexes);
            }
        }
    }

    return ans;
}
int main()
{
    vector<int> nums1 = {7, 3};
    vector<int> nums2 = {1, 6};
    int k = 2;
    vector<int> ans = maxCombinations(nums1, nums2, k);

    for (int i : ans)
    {
        cout << i << " ";
    }

    return 0;
}