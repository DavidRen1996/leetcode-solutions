class Solution {
public:
    string minWindow(string s, string t) {
        int tlen = t.size();
        int slen = s.size();
        string ret = "";
        map<char, int>sd;
        map<char, int>td;
        set<char>chars;
        for (auto item : t) {
            td[item]++;
            chars.insert(item);
        }
        int start = 0;
        int end = -1;
        for (int i = 0; i < slen; i++) {
            if (td[s[i]] == 0) {
                continue;
            }
            sd[s[i]]++;
            if (sd[s[i]] == td[s[i]]) {
                set<char>::iterator it = find(chars.begin(), chars.end(), s[i]);
                chars.erase(it);
            }
            if (chars.empty()) {
                end = i;
                break;
            }
        }
        if (!chars.empty())return ret;
        ret = s.substr(start, end - start + 1);
        while (end < slen) {
            while (td[s[start]] == 0) {
                start++;
            }
            if (ret.size() > end - start + 1) {
                ret = s.substr(start, end - start + 1);
            }
            sd[s[start]]--;
            //cout<<start<<" "<<sd[s[start]]<<" ";
            if (sd[s[start]] < td[s[start]]) {
                end++;
                while (end < slen) {
                    if (td[s[end]] > 0) {
                        sd[s[end]]++;
                    }

                    if (s[end] == s[start]) {
                        start++;
                        if (ret.size() > end - start + 1) {
                            ret = s.substr(start, end - start + 1);
                        }
                        break;
                    }
                    end++;
                }
            }
            else {
                start++;
            }
            //cout<<end<<endl;
        }
        return ret;
    }
};