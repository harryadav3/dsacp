#include <bits/stdc++.h>
using namespace std;

void solve(string str, vector<string> &ans, vector<string> &keypad){
    if(str.length() == 0){
        ans.push_back(str);
        return;
    }

    char ch = str[0];
    string ros = str.substr(1);

    string code = keypad[ch - '0'];

    for(int i = 0; i < code.length(); i++){
        solve(ros,ans, keypad);
    }

}

void generateAll(string str, vector<string> &ans, vector<string> &keypad, string asf){
    if(str.length() == 0){
        ans.push_back(asf);
        return;
    }

    char ch = str[0];
    string ros = str.substr(1);

    string code = keypad[ch - '0'];

    for(int i = 0; i < code.length(); i++){
        generateAll(ros,ans, keypad, asf + code[i]);
    }

}
int main() {

vector<string> keypad = { " ", ".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz" };

vector<string> ans;
string str = "78";

solve(str, ans, keypad);
    
for(auto i : ans){  
    cout<<i<<endl;
}
    return 0;
}