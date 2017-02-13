//https://www.hackerrank.com/challenges/red-john-is-back

#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long int sieve(long int n) {
    long int s = 0;
    long int prime[n+ 1];
    for (int i= 2; i<= n; i++) {
    	prime[i] = 1;
    }
 
    for (int p= 2; p* p <= n; p++) {
        if (prime[p] == 1) {
            for (int i= p* 2; i <= n; i += p)
                prime[i] = 0;
        }
    }

    for (int p= 2; p<= n; p++)
       if (prime[p])
          s++;
    
    return s;
}

long int C( int S[], int m, int n )
{
    long int count[n];
    memset(count, 0, sizeof(count));
    count[0] = 1;
    count[1] = 1;
    count[2] = 1;
    count[3] = 2;
    
    for(int i=4; i < n; i++)
        count[i] += count[i-4] + count[i-1];
    return count[n - 1];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t, n;
    int a[2] = {1, 4};
    cin >> t;
    while (t--) {
        cin >> n;
        cout << sieve(C(a, 2, n))<<endl;
    }
    return 0;
}
