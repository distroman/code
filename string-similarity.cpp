//https://www.hackerrank.com/challenges/string-similarity/

#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */


long long int stringSimilarity(string s) {
    long long int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    z[0] = (int) s.length(); long long int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += z[i];
    }
    return sum;
}
int main() {
    int t, i;
    scanf("%d",&t);
    string s;
    for (i=0;i<t;i++) {
        cin>> s;
        long long int res=stringSimilarity(s);
        printf("%lld\n",res);  
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
