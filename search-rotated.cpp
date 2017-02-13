//https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int searcher(vector<int>& nums, int beg, int end, int target) {
        if(beg > end)
            return -1;
        if(beg == end)
            return nums[beg] == target ? beg : -1;
        int mid = (beg + end) / 2; 
        if(nums[mid] == target)
            return mid;
        if( nums[beg] <= nums[mid]) {
            if (target < nums[mid] && target >= nums[beg]) 
                return searcher(nums, beg, mid - 1, target);
            return searcher(nums, mid + 1, end, target);
        }
        else {
            if(target <= nums[end] && target > nums[mid])
                return searcher(nums, mid + 1, end, target);
            return searcher(nums, beg, mid - 1, target);
        }
    }
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        return searcher(nums, 0, nums.size() - 1, target);
    }
};
