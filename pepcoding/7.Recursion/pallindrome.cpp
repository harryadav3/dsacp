#include <iostream>

using namespace std;

bool pallindrome(int i, string &s) {

  if (i >= s.size() / 2)
    return true;
  if (s[i] != s[s.size() - 1 - i])
    return false;
  return pallindrome(i + 1, s);
}

int main() {

  string s;
  cin >> s;

  if (pikindrome(0, s))
    cout << "true";
