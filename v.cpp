


#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}

int main()
{
    vector<int> a = {38289,33170,1859,23863,45658,24408,38353,21761,46411,41237,46956,33613,49349,26026,11031,19190,45358,32843,7054,14184,46050,19610,12625,14179,4066,6866,9996,34864,26222,1262,27512,40674,9793,14583,34325,23768,40373,10787,23397,2298,42342,26340,19552,1612,7014,44006,18885,14427,3821,41595,40575,26085,34594,49448,41457,37147,15003,18172,6585,29405,11315,29488,26525,40889,27485,31122,29281,8787,3008,41470,34402,9184,25736};
    long long k = 526314;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}


