#include <bits/stdc++.h>
using namespace std;


void validparenthesis(int n, int open, int close, string s){
    if(open == n && close == n){
        cout<<s<<endl;
        return;
    }
    if(open < n){
        validparenthesis(n,open+1,close,s+"(");
    }
    if(close < open){
        validparenthesis(n,open,close+1,s+")");
    }
}

void printvalidparenthesis(vector<string> &ans, int n, int open, int close, string s){
    if(open == n && close == n){
        // ans.push_back(s);
        cout<<s<<endl;
        return;

    }
    if(open < n){

        validparenthesis(n,open+1,close,s+"(");
    }
    if(close < open){
        validparenthesis(n,open,close+1,s+")");
    }
}

void backprintvalidparenthesis(vector<string> &ans, int n, int open, int close, string s){
    if(open == n && close == n){
        ans.push_back(s);
        return;

    }
    if(open < n){
        s+="(";
        validparenthesis(n,open+1,close,s);
        s.pop_back();
    }
    if(close < open){
        s+=")";
        validparenthesis(n,open,close+1,s);
        s.pop_back();
    }
}
int main() {
    vector<string> ans;
    // printvalidparenthesis(ans,4,0,0,"");

backprintvalidparenthesis(ans,3,0,0,"");
    for(auto i : ans){
        cout<<i<<endl;
    }
    return 0;
}