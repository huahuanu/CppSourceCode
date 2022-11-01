class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string w1 = word1[0];
        string w2 = word2[0];
        int index1 = 1, index2 = 1;
        short l1 = word1.size(), l2 = word2.size();
        short len1 = w1.size(), len2 = w2.size();
        bool flag = true;

        for (int i = 0; i < len1 && i < len2 && flag; i++){
            if (w1[i] != w2[i]){
                flag = false;
                break;
            }

            if (i + 1 == len1 && index1 < l1){
                len1 += word1[index1].size();
                w1.append(word1[index1++]);
            }
            if (i + 1 == len2 && index2 < l2){
                len2 += word2[index2].size();
                w2.append(word2[index2++]);
            }
        }
        if (len1 != len2)
            flag = false;
        return flag;
    }
};
