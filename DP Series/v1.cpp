#include<bits/stdc++.h>
using namespace std;
static bool comp(string& s1, string& s2){
    return s1.size() < s2.size();
}
int main()
{
        vector<int> temp;

        temp.push_back(5);
     int ind = lower_bound(temp.begin(), temp.end(), 4) - temp.begin();

     cout<<ind;

    





    
    return 0;
}