//https://www.hackerrank.com/challenges/sherlock-and-valid-string/

#include <cmath>
#include <cstdio>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map <char, int> S;
    map <int, int> C;

    string s;
    cin >>s;

    for (int i =0; i<s.length(); i++)
        S[s[i]]++;
    
    for (map<char, int>::iterator it = S.begin(); it != S.end(); it++)
        C[it->second]++;
 
    if (C.size() > 2)
        cout << "NO\n";
    else if (C.size() == 1)
        cout << "YES\n";
    else {
        map<int, int>::iterator it = C.begin();
        int a = (it++)->second;
        int b = it->second;
        if(min(a,b) != 1)
            cout <<"NO\n";
        else
            cout <<"YES\n";        
    }

    return 0;
}
