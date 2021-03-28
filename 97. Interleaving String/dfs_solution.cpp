class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if (len1 + len2 != len3)return false;
        int index1 = 0;
        int index2 = 0;
        int index3 = 0;
        while (s1[index1] != s2[index2]) {
            if (s1[index1] == s3[index3]) {
                index1++;
                index3++;
                continue;
            }
            if (s2[index2] == s3[index3]) {
                index2++;
                index3++;
                continue;
            }
            return false;
        }

        if (index1 == len1 - 1 && index2 == len2 - 1)return true;

        bool ret = dfs(s1, s2, s3, index1, index2, index3);
        return ret;
    }

    bool dfs(const string& s1, const string& s2, const string& s3, int i1, int i2, int i3) {
        if (i3 == s3.size()) {
            //cout<<"i3 is:"<<i3<<endl;
            return true;
        }
        if (s1[i1] != s3[i3] && s2[i2] != s3[i3])return false;
        if (s1[i1] == s2[i2]) {
            bool ret = dfs(s1, s2, s3, i1 + 1, i2, i3 + 1) || dfs(s1, s2, s3, i1, i2 + 1, i3 + 1);
            //cout<<dfs(s1, s2, s3, i1+1, i2, i3+1)<<"|"<<dfs(s1, s2, s3, i1, i2+1, i3+1)<<endl;
            return ret;
        }
        while (s1[i1] != s2[i2]) {
            if (s1[i1] == s3[i3]) {
                i1++;
                i3++;
                continue;
            }
            if (s2[i2] == s3[i3]) {
                i2++;
                i3++;
                continue;
            }
            return false;
        }
        //cout<< i1 << " "<< i2 << " "<<i3<<endl;
        if (i1 == s1.size() - 1 && i2 == s2.size() - 1)return true;

        bool ret = dfs(s1, s2, s3, i1, i2, i3);
        //cout<<ret<<endl;
        return ret;
    }
};