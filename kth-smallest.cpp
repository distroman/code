//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        map <int, int> mat;
        for (int i =0; i< matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                mat[matrix[i][j]]++;
            }
        }
        int s =0;
        for (map <int, int>::iterator it = mat.begin(); it != mat.end(); it++) {
            s+= it->second;
            if (s >= k) 
                return it->first;
        }
        return 0;
    }
};
