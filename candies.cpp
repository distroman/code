/*
 * https://www.hackerrank.com/challenges/candies
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, ranks[100000] = {0}, candies[100000] = {0}, total = 0;

void candy() {
	candies[0] = 1;
	int _locale = 0;
	for (int i= 1; i< n; i++) {
		if(ranks[i] > ranks[i - 1]) {
			candies[i] = candies[i - 1] + 1;
			_locale = i;
		}
		else if (ranks[i] < ranks[i - 1]){
			candies[i] = 1;
			if(candies[i - 1] == 1) {
				for (int j = i - 1; j> _locale- 1; j--) {
					if(candies[j] > candies[j + 1])
						break;
					candies[j] += 1;
				}
			}
		}
		else {
			candies[i] = 1;
      _locale = i;
		}
	}
} 

void tot() {
	for (int i= 0; i< n; i++) {
		total += candies[i];
	}
}

int main() {
	cin >>n;
	for(int i= 0; i< n; i++) {
		cin>> ranks[i];
	}
	
	candy();
	tot();
	
	cout <<total<<endl;
	return 0;
}
