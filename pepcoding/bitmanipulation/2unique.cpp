#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> v = { 3,5,7, 2, 11, 3, 5,2};

    int ans;
    for( auto x : v){
        ans = ans ^ x;

    }
    int c= 0;
    cout<<c<<" "<<endl;
    while( ans & 1 == 1){
        ans>>1;c++;
    }
    int ans1 = ans;
    int fn = 0;

    for(int i=0; i<v.size(); i++){
        int k =v[i];
        k<<c-1;
        if(k&ans == 0){
            fn=fn&v[i];
        }
    }

    cout<<fn<<endl;
    cout<<(fn ^ ans1)<<endl;
    return 0;
}