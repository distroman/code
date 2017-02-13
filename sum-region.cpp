//https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix {
    vector <vector<int>> matrix;
public:
    NumMatrix(vector<vector<int>> matrix) {
        this->matrix = matrix;
        if (matrix.size() > 0) {
            int r = this->matrix.size();
            int c = this->matrix[0].size();
            for (int i = 0; i < r; i++) {
                for (int j = 1; j < c; j++) {
                    this->matrix[i][j] += this->matrix[i][j-1];
                }
            } 
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ret = 0;
        for (int i = row1; i <= row2; i++) {
            ret += this->matrix[i][col2] - this->matrix[i][col1 -1];
        }
        return ret;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
