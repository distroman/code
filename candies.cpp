//https://leetcode.com/problems/candy/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int N = ratings.size();
        vector <int> candies(N, 1);
        for(int i = 1; i < N; i++) {
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
            else 
                candies[i] = 1;
        }
        
        for(int i = N-1; i > 0; i--) {
            if (ratings[i - 1] >  ratings[i] &&
                candies[i - 1] <= candies[i])
                candies[i - 1] = candies[i] + 1;
            
        }
        
        int candy = 0;
        for(int i = 0; i < N; i++) {
            cout << candies[i] <<endl;
            candy += candies[i];
        }
        
        return candy;
        
    }
};
