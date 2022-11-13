class Solution {
public:
    string customSortString(string order, string s) {
        int len_order = order.size(), len_s = s.size();
        string result = "";
        vector<bool> flag(len_s, 0);
        for (int i = 0; i < len_order; i++) {
            for (int j = 0; j < len_s; j++) {
                bool f = false;
                if (s[j] == order[i]){
                    flag[j] = 1;
                    if (!f)
                        result.push_back(order[i]);
                }
            }
        }
        for (int i = 0; i < len_s; i++){
            if (flag[i] == 0){
                result.push_back(s[i]);
            }
        }
        return result;
    }
};
