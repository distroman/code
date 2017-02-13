//https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool frz = false;
        bool fcz = false;
        
        for (int i = 0; i < matrix.size(); i++) {
            if(matrix[i][0] == 0) {
                fcz = true;
                break;
            }
                
        }
        cout << "1" << endl;
        for (int i = 0; i < matrix[0].size(); i++) {
            if(matrix[0][i] == 0) {
                frz = true;
                break;
            }
        }
        cout << "2" << endl;
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        cout << "3" << endl;
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        cout << "4" << endl;
        if (frz) {
            for (int i = 0; i < matrix[0].size(); i++) {
                matrix[0][i] = 0;
            }
        }
        cout << "5" << endl;
        if (fcz) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
