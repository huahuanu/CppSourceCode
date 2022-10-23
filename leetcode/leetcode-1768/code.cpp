#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string y;
        int l1 = word1.size(), l2 = word2.size();
        for (int i = 0; i < l1 || i < l2; i++){
            if (i < l1)
                y.push_back(word1[i]);
            if (i < l2)
                y.push_back(word2[i]);
        }
        return y;
    }
};
