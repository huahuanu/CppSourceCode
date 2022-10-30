class Solution {
public:

    int len;
    vector<string> result;
    string temp;

    void DFS(int index, string ss){
        if (index == len){
            result.push_back(ss);
            return ;
        }
        string next = ss + temp[index];
        DFS(index + 1, next);

        if (temp[index] >= 'a' && temp[index] <= 'z'){
            next.back() = toupper(next.back());
            DFS(index + 1, next);
        }
    }

    vector<string> letterCasePermutation(string s) {
        len = s.size();
        temp = s;
        for (int i = 0; i < len; i++){
            if (temp[i] >= 'A' && temp[i] <= 'Z'){
                temp[i] = tolower(temp[i]);
            }
        }
        DFS(0, "");
        return result;
    }
};
