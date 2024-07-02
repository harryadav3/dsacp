#include <bits/stdc++.h>
using namespace std;

const int N = 100;
vector<int> sieve;
vector<int> sum_div, prime, sum_even_odd;
vector<int> all_div[N];

void sieve_func() {
    sieve.resize(N,1);
    sieve[0] = sieve[1] = 0;
    for( int i = 2; i*i <= N; i++) {
        if(sieve[i]) {
            for( int j = i*i; j<= N; j+=i) {
                sieve[j] = 0;
            }
        }
    }
}

void sieve_masab() { 
    sum_div.resize(N,1);
    sum_even_odd.resize(N,1);
    prime.resize(N,1);

    for( int i =1; i< N; i++) {
        for( int j=i; j<N;j+=i){

            if( i != 1 && j != 1) {
                prime[j] = 0;
            }
            sum_div[j] += i;
            all_div[j].push_back(i);
            if( i%2 == 0) {
                sum_even_odd[j] += i;
            } else {
                sum_even_odd[j] -= i;
        }
    }
}
}
int main() {

    // sieve_func();
    // for( int i = 0; i< N; i++) {
    //     if(sieve[i]) cout<<i<<endl;
    // } 

    sieve_masab();

    for( int i = 0; i< N; i++) {
        cout<<i<<" "<<sum_div[i]<<" "<<sum_even_odd[i]<<" "<<prime[i]<<endl;
    }

    cout<<endl;
    return 0;
}