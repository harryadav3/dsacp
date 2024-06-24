#include <bits/stdc++.h>
using namespace std;

bool is_operand(char ch) {
    return ( ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void postfix_to_prefix(string s) {

    stack<string> st;
    for(int i= 0; i<s.length(); i++) {

        if(is_operand(s[i])) {
            st.push(string(1, s[i]));
        } else {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            string expression = s[i] + op1 + op2;
            st.push(expression);
        }

    }
        cout << st.top() << endl;
}

int main() {

    postfix_to_prefix("ABC*+D+"); 

    return 0;
}