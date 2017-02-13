//https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map <int, int> m_nums;
        vector <pair <int, int>> cnp;
        vector <int> ret;
        for (int i = 0; i < nums.size(); i++) {
            m_nums[nums[i]]++;
        }
        for (map<int, int>::iterator it = m_nums.begin(); it != m_nums.end(); ++it) {
            cnp.push_back(pair <int, int> (it->first, it->second));
        }
        sort(cnp.begin(), cnp.end(), [](pair <int, int> &left, pair<int, int> &right) {
                                return left.second > right.second; });
        for (int i = 0; i < k; i++) {
            ret.push_back(cnp[i].first);
        }
        return ret;
    }
};
