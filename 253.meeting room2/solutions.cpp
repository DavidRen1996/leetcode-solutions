class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)return 0;
        priority_queue<int, vector<int>, greater<int>>fini_times;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        for (auto item : intervals) {
            pq.push(make_pair(item[0], item[1]));
        }
        fini_times.push(pq.top().second);
        pq.pop();
        int ret = 1;
        while (!pq.empty()) {
            auto t = pq.top();
            pq.top();
            int fist_fini = fini_times.top();
            if (t.first < fist_fini) {
                //cout<<t.first<<" "<<fist_fini<<endl;
                ret++;
            }
            else {
                //cout<<fist_fini<<endl;
                fini_times.pop();
            }
            pq.pop();
            //fini_times.pop();
            fini_times.push(t.second);
        }
        return ret;
    }
};