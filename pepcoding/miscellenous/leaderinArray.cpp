#include <bits/stdc++.h>
using namespace std;

int main() {

    
    int a[] = { 15, -1, 7, 2 ,5 , 4 ,2 ,3};

    int maxy  = a[7];int count = 0;

    for ( int i = 7; i >= 0; i-- ){
        if( a[i] > maxy ) {
            count++;
            maxy = a[i];
        } 
    }

    cout<<"The answer is " << count << endl;
    return 0;
}