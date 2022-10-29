class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int index = ruleKey[0] == 't' ? 0: (ruleKey[0] == 'c' ? 1: 2);
        return count_if(items.begin(), items.end(), [&](auto& f){return f[index] == ruleValue;});
    }
};
