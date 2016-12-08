/*
 * https://www.hackerrank.com/challenges/coin-change
 */

#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

long int C( int S[], int m, int n )
{
    long int count[n+1];
    memset(count, 0, sizeof(count));
    count[0] = 1;
    for(int i=0; i<m; i++)
        for(int j=S[i]; j<=n; j++)
            count[j] += count[j-S[i]];
    return count[n];
}

int main()
{
	int arr[250]; int n; int m;
    cin >> n >> m;
    for (int i = 0; i<m; i++) 
        cin>>arr[i];
	cout<< C(arr, m, n);
	return 0;
}
