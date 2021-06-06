class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int slen = s.size();
        int tlen = t.size();
        int ret = false;
        if (slen == 0) {
            if (tlen == 1)return true;
            return false;
        }
        if (tlen == 0) {
            if (slen == 1)return true;
            return false;
        }
        for (int i = 0; i < slen; i++) {
            //int j=i;
            if (i >= tlen) {
                if (i == slen - 1)return true;
                return false;
            }
            if (t[i] != s[i]) {
                string backup = s;
                s[i] = t[i];
                if (s == t)return true;
                s = backup;
                s.insert(s.begin() + i, t[i]);
                if (s == t)return true;
                s = backup;
                s.erase(i, 1);
                if (s == t)return true;
                return false;
            }
        }
        if (slen == tlen)return false;
        if (tlen == slen + 1)return true;
        return false;
    }
};