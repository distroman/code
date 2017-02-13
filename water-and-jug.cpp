https://leetcode.com/problems/water-and-jug-problem/

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z == 0) 
            return true;
        if(x + y < z)
            return false;
        else {
            if(z % hcf(x, y) == 0)
                return true;
        } 
        return false;
    }
    int hcf(int x, int y) {
        return y == 0 ? x : hcf(y, x % y);
    }
};
