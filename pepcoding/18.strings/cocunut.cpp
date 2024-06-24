/*
Harley purchased E same power coconuts from a supermarket and now he needs to check them b releasing them from vrous floors fo his apartment. 
his apartment has f floor number I to f x is an nkonw number in the range from 0 to f inlcudse each coconut will break down if release fromfloor x + 1 or above , but will not break down if released from floor x or below

harley can release each cocumut as many times as he want from any floor until  it break down he needs to know the niminum number of co nut releases necessary to ensure that he can figure ou x. 
for illustration if there are three floors and harley has only one cocumt then he has to first puth the coconut on the first floor then on the second floor if the coconut survived and then on the third floor therefore three release are required in the worst case


input format : 
the input nconatin two number , the number of floors and e , the number of coconut s

output format
the output display theminimal number of release dreuqired or it greater than 32 print the word "impossible" after many releases harley get toot tired and cnnot conitnure 


sample input 
input : 100 2
output : 14


if input is more than 32 then print impossible

*/




#include <bits/stdc++.h>
using namespace std;


#include <iostream>
#include <climits>
using namespace std;

bool isPossible(int f, int e, int x) {
    long long int sum = 0;
    long long int power = 1;
    for (int i = 1; i <= e; i++) {
        power *= x;
        sum += power;
        if (sum >= f) {
            return true;
        }
    }
    return false;
}

int main() {
    int f, e;
    cin >> f >> e; // Number of floors and coconuts

    int low = 1, high = f;
    int result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(f, e, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (result == -1 || result > 32) {
        cout << "impossible";
    } else {
        cout << result;
    }

    return 0;
}
