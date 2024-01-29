
#include <iostream>
using namespace std;

int func(int i, int sum) {

  if (i < 1) {
    cout << sum;
    return 0;
  }
  return -1;
}

int main() {

  int n;
  cin >> n;
  func(8, n);

  return 0;
}
