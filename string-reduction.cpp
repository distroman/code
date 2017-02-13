//https://www.hackerrank.com/challenges/string-reduction

#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

int stringReduction(string s) {
    int _a = 0, _b = 0, _c = 0, r;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a') 
            _a++;
        else if (s[i] == 'b') 
            _b++;
        else 
            _c++;
    }
    if (_a + _b == 0) 
        r = _c;
    else if (_a + _c == 0) 
        r = _b;
    else if (_b + _c == 0) 
        r = _a;
    else {
        if(s.length() % 2 == 1) {
            if ((_a % 2 == 1) && (_b % 2 == 1))
                r = 2;
            else
                r = 1;
        }
        else {
            if ((_a % 2 == 0) && (_b % 2 == 0)) 
                r = 2;
            else
                r = 1;
        }
    }

    return r;
}

int main() {
    int t;
    string s;
    
    cin >> t;
    while(t--) {
        cin>> s;
        int r = stringReduction(s);
        printf("%d\n",r);  
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
