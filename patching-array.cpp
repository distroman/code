//https://leetcode.com/problems/patching-array/

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int sum = 1, patch = 0;
        for(int i = 0; i < nums.size();) {
            if(sum > n)
                break;
            if(nums[i] <= sum) {
                sum+=nums[i++];
            }
            else {
                sum<<=1;
                patch++;
            }
        }
        if (sum <= n) {
            n = n/sum + 1;
            int x = (int) ceil(log2(n));
            patch += x;
        }
        return patch;
    }
};
