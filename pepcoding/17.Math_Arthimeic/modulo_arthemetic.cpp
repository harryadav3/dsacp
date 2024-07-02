#include <bits/stdc++.h>
using namespace std;

/*

if we take moudle with c then the resul is 0 <= res <= c-1

if we take moudle with -c then the resul is -c+1 <= res <= 0

- the mode = 1e9+7 is used in competitive programming because it is a prime number and it is the largest 9 digit prime number. As INT_MAX = 2^31-1 = 2147483647 < 1e9+7 has 9 digits.

- 1e9+7 is used to avoid overflow in the intermediate calculations.

( a + b ) % c = ( ( a % c ) + ( b % c ) ) % c
( a - b ) % c = ( ( a % c ) - ( b % c ) + c ) % c
( a * b ) % c = ( ( a % c ) * ( b % c ) ) % c
( a / b ) % c != ( ( a % c ) / ( b % c ) ) % c


- (a/b) % c = (a * (b^-1)) % c
- (a/b) % c = (a * (b^(c-2))) % c

*************** negative number
( -b % c ) =  ( c - b ) % c
( a - b ) % c = ( ( a % c ) - ( b % c ) + c ) % c
( a * b ) % c = ( ( a % c )  * ( b * c ) ) % c
( a / b ) % c = ( ( a % c ) * ( b^-1 % c ) ) % c
( a / b ) % c = ( ( a % c ) * ( b^(c-2) % c ) ) % c


( -3 % 5 ) = ( 5 - 3 ) % 5 = 2
( 7 - 3 ) % 5 = ( ( 7 % 5 ) - ( 3 % 5 ) + 5 ) % 5 = 4
( 7 / 3 ) % 5 = ( ( 7 % 5 ) * ( 3^-1 % 5 ) ) % 5 = ( ( 7 % 5 ) * ( 2 % 5 ) ) % 5 = 4
( 7 / 3 ) % 5 = ( ( 7 % 5 ) * ( 3^(5-2) % 5 ) ) % 5 = ( ( 7 % 5 ) * ( 3^3 % 5 ) ) % 5 = 4


************************************

as we know remainder > 0 

divident = divisor * quotient + remainder

*/


// Q1 take a large string as input and then find does the number is divisible by small numbe ror not 

/*
9988 / 7 
9 % 7 = 2
98 % 7 = 0
988 % 7 = 6
9888 % 7 = 3

( 9 * 10 + 9 ) % 7 = 2
( 2 * 10 + 9 ) % 7 = 0
( 0 * 10 + 8 ) % 7 = 6
( 6 * 10 + 8 ) % 7 = 3
*/

void divisible_by(string s, int n) {
    int num = 0;
    for(int i = 0; i < s.size(); i++) {
        num = (num*10 + (s[i] - '0')) % n;
    }
    cout<<num<<endl;
    if( num == 0) {
        cout<<"Yes Divisible"<<endl;
    } else {
        cout<<"Not Divisible"<<endl;
    }
}



int main() {
    string s = "29834917349817401847981745601983461829746";
    int n = 22;

    divisible_by(s, n); 

    return 0;
}