

#include <bits/stdc++.h>
using namespace std;


void pushAtBottom(stack<int> &st, int x) {
    if(st.empty()) {
        st.push(x);
        return;
    }
    int y = st.top();
    st.pop();
    pushAtBottom(st, x);
    st.push(y);
}

void reverseStack(stack<int> &st) {
    if(st.empty()) {
        return;
    }
    int x = st.top();
    st.pop();
    reverseStack(st);
    pushAtBottom(st, x);
}

int main() {


    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);


    reverseStack(st);


    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    
        

    return 0;
}