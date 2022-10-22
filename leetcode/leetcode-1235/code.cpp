#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for(int i = 0; i < n; i++){
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end(), [](const vector<int>& jobs1, const vector<int>& jobs2)->bool{
            return jobs1[1] < jobs2[1];
        });
        vector<int> dp(n + 1);
        for(int i = 1; i <= n; i++){
            int k = upper_bound(jobs.begin(), jobs.begin() + i - 1, jobs[i - 1][0], [&](int start, const vector<int>& job)->bool{
                return start < job[1];
            }) - jobs.begin();
            dp[i] = max(dp[i - 1], dp[k] + jobs[i - 1][2]);
        }
        return dp[n];
    }
};
