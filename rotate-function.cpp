//https://leetcode.com/problems/rotate-function/

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int s = 0, f0 = 0;
        for (int i= 0; i < A.size(); i++) { 
            s += A[i];
            f0 += i * A[i];
        }
        
        int m = f0; 
        int fi = f0;
        for (int i = A.size() - 1; i > 0; i--) {
            fi += s - (A.size() * A[i]);
            m = max(m, fi );
        }
        
        return m;
    }
};
