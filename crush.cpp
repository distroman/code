//https://www.hackerrank.com/challenges/crush

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long int n, m, a, b, k;
    
    cin>>n>>m;
    long int *N = new long int[n+1]();
    for (int i = 0; i< m; i++) {
        cin >> a >> b >> k;
        N[a] += k;
        if(b < n) N[b+1] -= k;
    }
    long int max =0l, l = 0l;
    for (int i = 0; i<n+1; i++) {
        l += N[i];
        if(max < l) max = l;
    }
    cout <<max;
    return 0;
}
