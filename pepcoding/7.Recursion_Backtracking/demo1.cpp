#include <bits/stdc++.h>
using namespace std;


void solve ( int index , int curValue , int lastValue,  string input, int target, string epxression) {
    for( int i = index ; i < input.size(); i++ ) {

        if( index == input.size()){
            if( curValue == target) {
                cout<<epxression<<endl;
            }
            return;
        }

        if( i != index && input[index] == '0') {
            break;
        }

        string to_operate = input.substr(index, i - index + 1);
        if( to_operate.size() > 9 ) {
            break;
        }
        int value = atoi(to_operate.c_str());

        if( index == 0) {
            solve(i+1, value, value, input, target, epxression + to_operate);
        } else {
            solve(i+1, curValue + value, value, input, target, epxression + "+" + to_operate);
            solve(i+1, curValue - value, -value, input, target, epxression + "-" + to_operate);
            solve(i+1, curValue - lastValue + lastValue * value, lastValue * value, input, target, epxression + "*" + to_operate);
        
        }
    }
}

int main() {


    string input = "125";
    int target = 7; 

    solve(0 , 0 , 0 , input , target, "");

    return 0;
}