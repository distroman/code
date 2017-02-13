//https://www.hackerrank.com/challenges/superman-celebrates-diwali/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    /* n: number of buildings
     * h: height of buildings
     * l: jump height loss
     */
     
    int n, h, l;
    cin>>n>>h>>l;
    
    int t;
    vector<vector <int>> b(n, vector <int>(h, 0));
    vector<vector <int>> dp(n, vector <int>(h, 0));
    vector<int> m(h, 0);
    vector<int> p(n, 0);

    for(int i = 0; i < n; i++) {
        cin>>p[i];
        
        for(int j = 0; j < p[i]; j++) {
            cin >> t;
            b[i][t-1]++;
        }
        
        dp[i][h-1] = b[i][h-1];
        m[h-1] = max(m[h-1], dp[i][h-1]);
    }
    
    bool flag = false;
    for (int j = h - 2; j > -1; j--) {
        if(j + l < h) {
            flag = true;
        }
        for (int i = 0; i < n; i++) {
            dp[i][j] = dp[i][j+1] + b[i][j];
            if(flag) {
                dp[i][j] = max(dp[i][j], m[j+l] + b[i][j]);
            }
            m[j] = max(dp[i][j], m[j]);
        }  
    }
    
    cout << m[0] << endl;
    return 0;
}
