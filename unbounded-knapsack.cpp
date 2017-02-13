//https://www.hackerrank.com/challenges/unbounded-knapsack/

#include <cmath>
#include <cstdio>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t, n , k, x;
    map <int, int> weights;
    cin >> t;
    while (t--) {
        cin >> n >> k;
   
        for (int i = 0; i< n; i++) {
            cin >>x;
            weights[x]++;
        }
        
        int maxfill[k + 1] = {0};
        
        for (int i = 1; i <= k; i++) {
            for (map <int, int>::iterator it = weights.begin(); it != weights.end(); it++) {
                if (it->first <= i) {
                    maxfill[i] = max(maxfill[i], it->first + maxfill[i - it->first]);
                }
            }
        }
        cout << maxfill[k]<<endl;
        weights.clear();
        
    }
    return 0;
}
