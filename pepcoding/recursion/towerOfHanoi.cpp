#include <bits/stdc++.h>
using namespace std;

int towerofHanoi(int n,char src,char dest,char helper){
    if(n==0){
        return 0;
    }
    int ans = 0;
    ans += towerofHanoi(n-1,src,helper,dest);
    cout<<"Move "<<n<<"th disk from "<<src<<" to "<<dest<<endl;
    ans += towerofHanoi(n-1,helper,dest,src);
    return ans;
}

// no of time we need to move the disk is 2^n - 1 
// solve the tower of hanoi for n disks


int main() {

    towerofHanoi(3,'A','C','B');

    return 0;
}