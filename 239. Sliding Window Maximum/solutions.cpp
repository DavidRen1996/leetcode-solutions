class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int>ret;
        if (k > len)return ret;
        priority_queue<pair<int, int>>pq;
        for (int i = 0; i < k; i++) {
            pq.push(make_pair(nums[i], i));
        }
        pair<int, int>tmp = pq.top();
        int index = tmp.second;
        ret.push_back(tmp.first);
        for (int i = 1; i <= len - k; i++) {
            pq.push(make_pair(nums[i + k - 1], i + k - 1));
            while (!pq.empty()) {
                //cout<<pq.size()<<endl;
                if (pq.top().second < i) {
                    pq.pop();
                }
                else {
                    break;
                }
            }
            ret.push_back(pq.top().first);
            index = pq.top().second;
            continue;
        }
        return ret;
    }
};