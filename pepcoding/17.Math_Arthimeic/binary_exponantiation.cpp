#include <bits/stdc++.h>
using namespace std;


/*

3 ^ 4 = 3 * 3 * 3 * 3 = 81

3 ^ 2 -> 3 ^ 4-> 3 ^ 8 -> 3 ^ 16 -> 3 ^ 32 -> 3 ^ 64

for example 

25 = 16 + 8 + 1
which is in binay = 11001 = 2 ^ 4 + 2 ^ 3 + 2 ^ 0 = 16 + 8 + 1 = 25


    a        b           res                a ^ b 
    3^1      25          1                  3
    3^2      12          3                  9
    3^4      6           3                  81
    3^8      3           3*3^8              6561
    3^16     1           3^9 * 3^16         43046721
    3^32     0           3^25               1853020188851841
*/

int binary_exponentiation_gpt(int a, int b, int mod) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res;
}

int binary_expo_masab(int x ,int y, int mod) {
    int res = 1;
    while(y){
        if( y & 1) {
            res *= x;
            // cout<<res<<endl;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}

int binary_exponentiation(int a, int b, int mod) {
  int ans = 1;

  while (b) {
    if (b % 2 == 1) {
      ans = (ans * a);
    }

    a = a * a;
    b /= 2;
  }

  return ans;
}

int main() {
  int a, b;
  cin >> a >> b;

  cout << binary_exponentiation(a, b, 1e9 + 7) << endl;
}
