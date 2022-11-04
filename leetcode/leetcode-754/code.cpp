class Solution {
public:
    int reachNumber(int target) {
        int steps = 1, sum = 0;
        if (target < 0)
            target = -target;
        while(sum < target){
            sum += steps++;
        }
        if (sum == target)
            return steps - 1;
        else
            return findSteps(target - sum, steps);
    }
    int findSteps(int delta, int steps){
        while (delta % 2 != 0){
            delta += steps++;
        }
        return steps - 1;
    }
};
