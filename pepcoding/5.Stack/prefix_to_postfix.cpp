#include <bits/stdc++.h>
using namespace std;

bool is_operand(char ch) {
    return ( ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void prefix_to_postfix(string pre){

    stack<string> st;
    for( int i=pre.length()-1; i>=0; i--){

        if( is_operand(pre[i]) ){
            st.push(string(1, pre[i]));
            // cout << "Pushing " << pre[i] << endl;
        } else {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string expression = op1 + op2 + pre[i];
            // st.push(op1 + op2 + pre[i]);
            st.push(expression);
        }
    }
    cout<<st.top()<<endl;
}

int main() {

    
    prefix_to_postfix("++A*BCD");

    return 0;
}