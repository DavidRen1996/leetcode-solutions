class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int slen = s.size();
        if (slen == 0)return 0;
        char last = s[0];
        int pivot = 0;
        for (int i = 1; i < slen; i++) {
            if (s[i] != s[0]) {
                pivot = i;
                break;
            }
        }
        if (pivot == 0)return slen;
        char cur = s[pivot];
        int start = 0;
        int ret = 1;
        for (int i = pivot; i < slen; i++) {
            if (s[i] == cur) {
                ret = max(ret, i - start + 1);

            }
            else if (s[i] == last) {
                pivot = i;
                char tmp = cur;
                cur = last;
                last = tmp;
                ret = max(ret, i - start + 1);

            }
            else {
                ret = max(ret, i - start);
                start = pivot;
                pivot = i;
                last = cur;
                cur = s[i];
            }
            //cout<<pivot<<endl;
        }
        return ret;
    }
};