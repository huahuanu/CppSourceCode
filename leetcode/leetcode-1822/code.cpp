#include <vector>
using namespace std;


class Solution {
public:
    int arraySign(vector<int>& nums) {
        int len = nums.size();
        int flag = 1;
        for(int i = 0; i < len && flag != 0; i++){
            flag *= signFunc(nums[i]);
        }
        return flag;
    }
    int signFunc(int x){
        if (x == 0)
            return 0;
        else if (x > 0)
            return 1;
        else
            return -1;
    }
};
