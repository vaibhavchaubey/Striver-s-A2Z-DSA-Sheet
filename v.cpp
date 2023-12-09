#include <bits/stdc++.h>
using namespace std;
static bool comp(string &a, string &b)
{
    if (a.size() != b.size())
    {
        return a.size() < b.size();
    }

    // lexicographical comparision (when a.size() = b.size())
    return a < b;
}

int main()
{
    vector<string> nums = {"3", "100", "7", "10"};

    sort(nums.begin(), nums.end(), comp);

    for (auto num : nums)
    {
        cout << num << " "; // 3 7 10 100
    }

    return 0;
}