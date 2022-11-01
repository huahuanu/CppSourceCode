class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string w1 = word1[0];
        string w2 = word2[0];
        int index1 = 1, index2 = 1;
        bool flag = true;

        for (int i = 0; i < w1.size() && i < w2.size() && flag; i++){
            if (w1[i] != w2[i]){
                flag = false;
                break;
            }

            if (i + 1 == w1.size() && index1 < word1.size()){
                w1.append(word1[index1++]);
            }
            if (i + 1 == w2.size() && index2 < word2.size()){
                w2.append(word2[index2++]);
            }
        }
        if (w1.size() != w2.size())
            flag = false;
        return flag;
    }
};
