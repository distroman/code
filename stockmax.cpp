//https://www.hackerrank.com/challenges/stockmax/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t, n;
    int stocks[50000] ={0};
    int dp[50000]= {0};
   
    cin >>t;
    while (t--) {
        cin >> n;
        for (int i = 0; i<n; i++) {
            cin >>stocks[i];
            dp[i] = stocks[i];
        }
        for (int i = n-2; i>-1; i--) {
            dp[i] = max(dp[i+1], dp[i]);
        }
        
        long int profit = 0;
        for (int i =0; i<n; i++) {
            profit += dp[i] - stocks[i];
        }
        cout << profit<<endl;
    }
    return 0;
}
