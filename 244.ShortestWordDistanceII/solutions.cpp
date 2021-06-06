class WordDistance {
private:
    map<string, vector<int>>dict;
public:
    WordDistance(vector<string>& wordsDict) {
        int len = wordsDict.size();
        for (int i = 0; i < len; i++) {
            dict[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int ret = INT_MAX;
        int s1 = 0;
        int s2 = 0;
        // int slen = min(word1.size(), word2.size());
        while(s1 < dict[word1].size() && s2 < dict[word2].size()) {
            ret = min(abs(dict[word1][s1] - dict[word2][s2]), ret);
            // cout << s1 << " " << s2 << endl;
            if (dict[word1][s1] > dict[word2][s2]) {
                s2++;
            } else {
                s1++;
            }
        }
        return ret;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
