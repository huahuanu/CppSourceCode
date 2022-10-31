class Solution {
public:
    int len;
    vector<string> result;

    void DFS(string s, int index){
        if (index == len){
            result.emplace_back(s);
            return ;
        }
        if (s[index] >= 'a' && s[index] <= 'z'){
            DFS(s, index + 1);
            s[index] ^= 32;
            DFS(s, index + 1);
        }
        else{
            DFS(s, index + 1);
        }
        return ;
    }

    vector<string> letterCasePermutation(string s) {

        len = s.size();
        for (int i = 0; i < len; i++){
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;//to lower
        }
        DFS(s, 0);
        return result;
    }
};
