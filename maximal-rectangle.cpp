//https://leetcode.com/problems/maximal-rectangle/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
    
        if(matrix.size() == 0)
            return 0;
            
        vector<vector <int>> counts(matrix.size(), vector <int> (matrix[0].size(),0));

        for (int j =0; j <matrix[0].size(); j++)
            counts[0][j] = matrix[0][j] - '0';
        for (int i = 1; i <matrix.size(); i++) {
            for (int j = 0; j <matrix[0].size(); j++) {
                if(matrix[i][j] == '1')
                    counts[i][j] = counts[i - 1][j] + 1;
                else 
                    counts[i][j] = 0;
            }
        }

        int maxi = 0;
        for (int i =0; i <counts.size(); i++) {
            
            int j = 0;
            stack <int> dp;
            for (j = 0; j <counts[0].size(); j++) {
                
                while (!dp.empty() && counts[i][j] < counts[i][dp.top()]) {
                    int k = dp.top();
                    dp.pop();
                    maxi = max(maxi, counts[i][k] * (dp.empty() ? j: j - dp.top() - 1));
                }
                dp.push(j);
            } 
            
            int k;
            while(!dp.empty()) {
                k = dp.top();
                dp.pop();
                maxi = max(maxi, counts[i][k] * (dp.empty() ? j: j - dp.top() - 1));
            }
        }
        
        return maxi;
    }
};
