#include <vector>
#include <iostream>
//#include <algorithm>
using namespace std;


class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int len = nums.size();
        vector<int> minR(len);
        minR[len - 1] = nums[len - 1];
        for (int i = len - 2; i >= 0; i--){
            minR[i] = min(nums[i], minR[i + 1]);
        }
        int maxL = 0;
        for (int i = 0; i < len - 1; i++){
            maxL = max(maxL, nums[i]);
            if (maxL <= minR[i + 1])
                return i + 1;
        }
        return len - 1;
    }
};