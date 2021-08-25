class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        bool ret = false;
        // int n = edges.size();
        vector<int>groups(n, 0);
        set<int> unions;
        for (int i = 0; i < n; i++) {
            groups[i] = i;
        }
        for (auto item : edges) {
            if (groups[item[0]] == groups[item[1]]) {
                return ret;
            }
            int prev = groups[item[1]];
            for (int i = 0; i < n; i++) {
                if (groups[i] == prev) {
                    groups[i] = groups[item[0]];
                } 
            }
        }
        for (auto item : groups) {
            // cout << item << " ";
            unions.insert(item);
        }
        if (unions.size() > 1) return false;
        return true;
    }
};
