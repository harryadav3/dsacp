#include <bits/stdc++.h>
using namespace std;

  
// create a match function with return bool if the string matches the regex pattern
// if the pattern is empty and the string is empty return true

bool match(string pattern, string str) {
    if(pattern.size() == 0 && str.size() == 0) {
        return true;
    }
    if(pattern.size() == 0) {
        return false;
    }
    if(str.size() == 0) {
        for(int i = 0; i < pattern.size(); i++) {
            if(pattern[i] != '*') {
                return false;
            }
        }
        return true;
    }
    if(pattern[0] == str[0] || pattern[0] == '?') {
        return match(pattern.substr(1), str.substr(1));
    } else if(pattern[0] == '*') {
        return match(pattern.substr(1), str) || match(pattern, str.substr(1));
    } else {
        return false;
    }
}

int main() {
    // ? - single character
    // * - multiple character 

    string pattern = "a*b";
    string str = "aaaab";

    cout<<match(pattern, str)<<endl;

    return 0;
}