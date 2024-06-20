#include <bits/stdc++.h>
using namespace std;

void bublesort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j+1],arr[j]);
            }
        }
    }
}
void bubblesortrecursive(int arr[],int n){
    if(n==1){
        return;
    }
    for(int i=0;i<n-1;i++){
        if(arr[i+1]<arr[i]){
            swap(arr[i+1],arr[i]);
        }
    }
    bubblesortrecursive(arr,n-1);
}

void bubblesortwithoutloop(int arr[],int n,int i){
    //explain this code using comments

    if(n==1){
        return;
    } 
    if(i==n-1){
        bubblesortwithoutloop(arr,n-1,0);
        return;
    } //  this is the base case for the recursive function 
    if(arr[i+1]<arr[i]){
        swap(arr[i+1],arr[i]);
    }
    bubblesortwithoutloop(arr,n,i+1);
}
int main() {

    

    return 0;
}