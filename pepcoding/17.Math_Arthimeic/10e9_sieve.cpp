#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> prime;
vector<int> prime_vector;

void sieve_fun() {
   prime.resize(N, 1);
    prime[0] = prime[1] = 0;
    for( int i = 2; i*i <= N; i++) {
            if(prime[i] == 0) continue;
            for( int j = i*i; j<= N; j+=i) {
                prime[j] = 0;
            }
        }
        for( int i=2; i <N;i++) {
            if(prime[i]) prime_vector.push_back(i);
    }
} 

void solve( int m , int n) {
    map<int,int> mp;
    for( int i = m; i<= n; i++) {
        mp[i] = 1;
    } 
    for( auto p : prime_vector) {
        if( p*p > n) break;

        int start;
        if( p >=m && p<= n) start = p*2;
        else start = ( m/p ) * p + ( m % p == 0 ? 0 : p);

        for ( int i = start ; i <= n ; i+= p ) {
            mp[i] = 0;
        }

    }
}

int main() {

   sieve_fun();
   int t;
   cin>>t;

    while(t--) {
         int m ,n;
        cin>>m>>n;
         solve(m, n); 
    }
    return 0;
}