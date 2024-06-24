
#include <bits/stdc++.h>
using namespace std;


void solvekeypad(string str, vector<string> &ans , vector<string> &keypad){

    if(str.length() == 0){
        ans.push_back(str);
        return;
    }

    char ch = str[0];
    string ros = str.substr(1);

    string code = keypad[ch - '0'];

    for(int i = 0; i < code.length(); i++){
        solvekeypad(ros,ans, keypad);
    }

}

int main() {

vector<string> keypad = {
    ".;",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tu",
    "vwx",
    "yz"
};

vector<string> ans;
string str = "78";

solvekeypad(str, ans, keypad);

    return 0;
}