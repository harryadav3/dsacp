#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int maxDepth(string str) {
        
        #include <algorithm>

                #include <algorithm>

                stack<char> s;
                int maxi = 0;

                for (auto i : str) {
                    if (i == '(') {
                        s.push(')');
                        maxi = max(static_cast<int>(s.size()), maxi);
                    } else if (i == ')' && s.top() == ')') {
                        s.pop();
                    }
                }

        return maxi;
    }
};