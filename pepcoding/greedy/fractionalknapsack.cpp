#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    // sort(arr, arr+n, [](Item a, Item b) {
    //     return (a.value/a.weight) > (b.value/b.weight);
    // });
    sort(arr,arr+n,compare);

    int curWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        } else {
            int remain = W - curWeight;
            finalValue += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }

    return finalValue;
}


double masabsolution ( int W, Item arr[], int n ) {
    
    sort(arr,arr+n,[](Item a, Item b) {
        return a.value > b.value;
    });

    double ans = 0.0;

    for ( int i = 0; i < n; i++ ) {
        if ( arr[i].weight <= W ) {
            ans += arr[i].value;
            W -= arr[i].weight;
        } else {
            ans += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }

    return ans;


}
int main() {

    

    return 0;
}