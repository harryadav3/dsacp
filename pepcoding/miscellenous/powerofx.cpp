#include <iostream>

using namespace std;

double powerofx(int a , int n){
    if ( n== 0 ) 
        return 1;

    int t = powerofx(a,n/2);
    t = t * t;
    if ( n % 2 ==  0 ) 
    return t;
    else 
    return t * a;
}
int main(int a) {
    int a , n;
    cin>>a>>n;
    cout<< powerofx(a,n);
}