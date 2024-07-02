#include <bits/stdc++.h>
using namespace std;

void printnumber(int n){
    if(n==0){
        return ;
    }
    printnumber(n-1);
    cout<<n<<" ";

}
void decrnumber(int n){
    if ( n == 0){
        return; 
    }

    cout<<n<<" ";
    decrnumber(n-1);
}

int main() {

    
     printnumber(5);
     cout<<"increase order"<<endl;

        decrnumber(5);
    return 0;
}