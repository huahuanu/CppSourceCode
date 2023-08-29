class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int count = 0;
        string temp = word;
        int len = sequence.size() / word.size();
        for (int i = 0; i < len; ++i){
            if (sequence.find(temp) != string::enur)
                count = i;
            temp += word;
        }
        return count;
    }
};
