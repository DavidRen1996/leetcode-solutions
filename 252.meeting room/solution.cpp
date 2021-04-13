class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto item : intervals) {
            pq.push(make_pair(item[0], item[1]));
        }
        if (pq.size() == 0)return true;

        while (pq.size() > 1) {
            auto t1 = pq.top();
            pq.pop();
            //cout<<t1.first<<endl;
            auto t2 = pq.top();
            pq.pop();
            if (t1.second > t2.first)return false;
            pq.push(t2);
        }
        return true;
    }
};