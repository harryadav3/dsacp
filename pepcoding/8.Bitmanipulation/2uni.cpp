#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> v = { 3,5,7, 2, 11, 3, 5,2};

        int ans = 0;

        for ( auto x : v){
            ans = ans ^ x;
        }
        int temp = ans;
        int pos = 0;




        while((temp & 1) != 1){
            pos++;
            temp=temp>>1;
        }
        cout<<pos;
        int a=0, b=0;

        for ( auto x: v){
            if( x & (1<<pos))
                a = a ^ x;
            else    
                b =  b ^ x;
        }

        cout<<a<<" "<<b<<" "<<endl;
    return 0;
}