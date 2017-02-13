//https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0)
            return 0;
        int m = 0, i;
        stack <int> dp;
        for (i = 0; i< heights.size(); i++) {
            
            while (!dp.empty() && heights[i] < heights[dp.top()]) {
                int k = dp.top();
                dp.pop();
                cout << "area" << heights[k] * (i - k) <<endl;
                m = max(m, heights[k] * (dp.empty() ? i: i - dp.top() - 1));
            }
            dp.push(i);
        }
        int k;
        while(!dp.empty()) {
            k = dp.top();
            dp.pop();
            m = max(m, heights[k] * (dp.empty() ? i: i - dp.top() - 1));
        }
        return m;
    }
};
