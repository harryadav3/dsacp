#include <bits/stdc++.h>
using namespace std;

void printnfriendspartysolororcouple(int i, int n, vector<char> v, string s){
    if(i == n){
        cout<<s<<endl;
        return;
    }
    printnfriendspartysolororcouple(i+1,n,v,s+v[i]);
    printnfriendspartysolororcouple(i+1,n,v,s);
}

// now modify above code so we can print like a is going solo and bc are going as couple in array separated with comma
// a,bc

// now modify above code so we can print like a is going solo and bc are going as couple in array separated with comma


int nfriends(int n){
    if(n == 0){
        return 1;
    }
    if(n == 1){
        return 1;
    }
    if(n == 2){
        return 2;
    }
    return nfriends(n-1) + (n-1)*nfriends(n-2);

}

int main() {

    vector<char> v = {'a','b','c'};

    cout<< nfriends(3)<<endl;
    printnfriendspartysolororcouple(0,3,v,"");

    return 0;
}