#include <bits/stdc++.h>
using namespace std;

// Calculate a ^ b mod 10 ^ 9 + 7
//
// 1011

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
