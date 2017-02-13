//https://www.hackerrank.com/challenges/playing-with-numbers

#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

#define MAX 4000
#define ZER 2000
#define NEG 1999

using namespace std;

int main() {
    int n, q, x;
        
    int NF[MAX+1];
    long int CF[MAX+1];
    long int CS[MAX+1];
    
    for (int i=0; i<= MAX; i++) {
        NF[i] = CF[i] = CS[i] = 0;
    }
    
    cin>>n;
    for (int i = 0 ; i <n; i++) {
        cin>>x;
        NF[x + ZER] ++;
    }
    
    CF[0] = NF[0];
    CS[0] = NF[0] *(-ZER);
    for (int i = 1; i <= MAX; i++) {
        CF[i] = CF[i-1] + NF[i];
        CS[i] = CS[i-1] + NF[i] * (i - ZER);
    }

    cin >>q;
    
    int C = 0, c;
    for(int i =0 ; i< q; i++) {
        cin >>x;
        C +=x;
        if (C > ZER) c = NEG;
        else if (C < -ZER) c = -NEG;
        else c = C - 1;
        
        long int spos = (CS[MAX] - CS[NEG - c]) + (CF[MAX] - CF[NEG - c])* C;
        long int sneg = CS[NEG - c] + (CF[NEG - c]) * C;        
        cout<< abs(spos) + abs(sneg)<<endl;
    }

    return 0;
}

