#include <bits/stdc++.h>
using namespace std;

// count binary stirng of lenght N wiht no consecutive 1's

int countbinarystring(int n, int lastdigit){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    int ans = 0;
    if(lastdigit == 0){
        ans += countbinarystring(n-1,0);
        ans += countbinarystring(n-1,1);
    }
    else{
        ans += countbinarystring(n-1,0);
    }
    return ans;
}

// print all binary string of lenght N wiht no consecutive 1's

int pbsno(int n, string s){
    if(n==0){
        cout<<s<<endl;
        return 1;
    }
  
    int ans = 0;
    if( s == "" ||s[s.length()-1] == '0'){
        ans += pbsno(n-1,s+"0");
        ans += pbsno(n-1,s+"1");
    }
    else{
        ans += pbsno(n-1,s+"0");
    }
    return ans;
}


int main() {

    // generateallbinary(int n);
    cout<<countbinarystring(3,0 )<<endl;
    pbsno(3,"");
    return 0;
}