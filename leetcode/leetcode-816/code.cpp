class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        int len = s.size() - 2;
        vector<string> result;
        s = s.substr(1, len);
        for ( int i = 1; i < len; i++){
            vector<string> left = getIndex(s.substr(0, i));
            if (left.empty())
                continue;
            vector<string> right = getIndex(s.substr(i));
            if (right.empty())
                continue;
            for (auto& j: left) {
                for (auto& k: right) {
                    result.push_back("(" + j + ", " + k + ")");
                }
            }
        }
        return result;
    }
    vector<string> getIndex(string s){
        vector<string> index;
        if (s[0] != '0' || s == "0")
            index.push_back(s);
        for (int i = 1; i< s.size(); i++){
            if ((i != 1 && s[0] == '0') || s.back() == '0')
                continue;
            index.push_back(s.substr(0, i) + "." + s.substr(i));
        }
        return index;
    }

};
