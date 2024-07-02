

/*

( P / Q ) % M ;

Additive Inverse = if (a % m) = x then (m - x) is the additive inverse of a.
it is a number which when added to a gives 0 as the result.

( 1/ 2) % 5
=> ( 1 * ( 2^-1 ) ) % 5
mode of this = [ ( 1 % 5 ) * ( 2^-1 % 5 ) ] % 5

FLT = Fermat's Little Theorem
if p is prime number  and a is an integer then a^p is congruence to a ( mod p).
in particulat if p does not divie a then a ^ ( p -1 ) is congruence  1 ( mod p)
 ( a^(p-1) ) % p = 1

a ^ p -1 = 1 ( mod p )
a ^ p -2 = a^-1 ( mod p )
a ^ -1 = a ^ p -2 ( mod p )

(  2 * 1/ 2) % 5 = 1
( 2 % 5 ) * ( 2 ^ -1 % 5 ) % 5
( 2 % 5 ) * ( 2 ^ 3 % 5 ) % 5
( 2 % 5 ) * ( 8 % 5 ) % 5
( 2 % 5 ) * ( 3 ) % 5
( 2 ) % 5
( 2 ) % 5 = 2


( 2 ^ 552927 ) % 5 is very costly operation to do it .


*******************
( a / b ) % m 
( ( a % b ) * ( b ^ -1) ) % m


*/

#include <bits/stdc++.h>
using namespace std;

#define int long long int

const int MOD = 1e9 + 7;  

int add(int x, int y) {
    return (x % MOD + y % MOD) % MOD;
}

int sub(int x, int y) {
    return (x % MOD - y % MOD + MOD) % MOD;
}

int mul(int x, int y) {
    return (x % MOD * y % MOD) % MOD;
}

// for modular exponentiation
int powerMod(int x, int y) {
    int res = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            res = mul(res, x);
        }
        x = mul(x, x);
        y >>= 1; // y = y / 2;
    }
    return res;
}

// for modular inverse
int inv(int x) {
    return powerMod(x, MOD - 2);
}

// for modular division
int divi(int a, int b) {
    return mul(a, inv(b));
}

// factorial
// invFact[n] = 
//nCr = n! / ( (n-r)! * r! )
const int N = 1e5;
int fact[N], invFact[N];
void precompute() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
    invFact[N-1] = inv(fact[N-1]);
    for(int i=N- 2 ; i>= 0; i--) {
        invFact[i] = mul(invFact[i + 1], i + 1);
    }
}

int nCr (int n, int r) {
    return mul(fact[n], mul(invFact[n - r], invFact[r]));
}
int32_t main() {
    // cout << divi(2, 5) << endl;
    precompute();
    cout<<nCr(2121,322)<<endl;
    return 0;
}
