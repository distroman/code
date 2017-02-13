//https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        int powersetsize = pow(2, nums.size());
        sort(nums.begin(), nums.end());
        
        set <vector<int>> powerset;
        for (int i = 0; i < powersetsize; i++) {
            vector <int> subset;
            for (int j =0; j < nums.size(); j++) {
                if ((i & (1 << j)) != 0) {
                    subset.push_back(nums[j]);
                }
            }
            
            powerset.insert(subset);
        }
        vector <vector <int>> ret(powerset.begin(), powerset.end());
        return ret;
    }
};
