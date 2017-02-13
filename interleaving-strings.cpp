//https://leetcode.com/problems/interleaving-string/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length())
            return false;
        
        string a = s3, b = s1 + s2;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a != b)
            return false;
        set< pair<int, int>> dp, t;
        if(s1[0] == s3[0])
            dp.insert(pair<int, int>(1,0));
        if(s2[0] == s3[0])
            dp.insert(pair<int, int>(0,1));
        if(dp.empty())
            return false;
            
        for (int i = 1; i < s3.length(); i ++) {
            for (std::set<pair<int, int>>::iterator it= dp.begin(); it!= dp.end(); ++it) {
                if (s1[it->first] == s3[i])
                    t.insert(pair<int, int> (it->first + 1, it->second));
                if (s2[it->second] == s3[i])
                    t.insert(pair<int, int> (it->first, it->second + 1));
            }
            if(t.empty())
                return false;
            dp = t; 
            t = set< pair<int, int>>();
        }
        
        return true;
    }
};
