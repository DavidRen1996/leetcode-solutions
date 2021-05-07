class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int len = wordsDict.size();
        int i1 = -1;
        int i2 = -1;
        int ret = INT_MAX;
        for (int i = 0; i < len; i++) {
            if (wordsDict[i] == word1) {
                i1 = i;
            }
            if (wordsDict[i] == word2) {
                i2 = i;
            }
            if (i1 < 0 || i2 < 0) {
                continue;
            }

            ret = min(ret, abs(i1 - i2));
        }
        return ret;
    }
};