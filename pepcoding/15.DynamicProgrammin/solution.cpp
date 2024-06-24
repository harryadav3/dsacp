#include <bits/stdc++.h>
using namespace std;


class Box {
    public:
    int l, w, h;
    Box(int l, int w, int h) {
        this->l = l;
        this->w = w;
        this->h = h;
    }
};



int masabsolution(vector<Box> &newboxes) {
  
    sort(newboxes.begin(), newboxes.end(), [](Box a, Box b) {
        return a.l > b.l;
    });
    
    vector<int> dp(newboxes.size(), 0);
    for(int i = 0; i < newboxes.size(); i++) {
        dp[i] = newboxes[i].h;
        for(int j = 0; j < i; j++) {
            if(newboxes[j].l > newboxes[i].l && newboxes[j].w > newboxes[i].w) {
                dp[i] = max(dp[i], dp[j] + newboxes[i].h);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
} 
int main() {

    vector<Box> boxes = {Box(3,2,8), Box(1,1,1), Box(2,2,3), Box(4,5,7), Box(1,1,3)};


    cout<<masabsolution(boxes)<<endl;


    return 0;
}