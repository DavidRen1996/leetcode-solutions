class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int rows = costs.size();
        int cols = 3;
        vector<int>rprev(rows, INT_MAX);
        vector<int>bprev(rows, INT_MAX);
        vector<int>gprev(rows, INT_MAX);

        rprev[0] = costs[0][0];
        bprev[0] = costs[0][1];
        gprev[0] = costs[0][2];

        for (int i = 1; i < rows; i++) {
            rprev[i] = costs[i][0] + min(bprev[i - 1], gprev[i - 1]);
            bprev[i] = costs[i][1] + min(rprev[i - 1], gprev[i - 1]);
            gprev[i] = costs[i][2] + min(bprev[i - 1], rprev[i - 1]);
        }
        int ret = min(gprev.back(), bprev.back());
        return min(ret, rprev.back());
    }
};