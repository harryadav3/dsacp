#include <bits/stdc++.h>
using namespace std;
// N boxes ( l, w, h) and we have to stack them in such a way that the base area of the box is strictly less than the area of the box above it and the box with the greater height is always above the box with the smaller height find the max height of the stack
class Box {
    public:
    int l, w, h;
    Box(int l, int w, int h) {
        this->l = l;
        this->w = w;
        this->h = h;
    }
};


int solve(vector<Box> &boxes, int idx) {
    if(idx == boxes.size()) {
        return 0;
    }
    int taken = 0;
    for(int i = idx+1; i < boxes.size(); i++) {
        if(boxes[i].l < boxes[idx].l && boxes[i].w < boxes[idx].w) {
            taken = max(taken, solve(boxes, i) + boxes[i].h);
        }
    }
    int nottaken = solve(boxes, idx+1);
    return max(taken, nottaken);
}

// sort them with max lenght 
// claculate the stack of max height
int masabsolution(vector<Box> &newboxes) {
  //  vector<Box> newboxes;
    // for(auto box: boxes) {
    //     newboxes.push_back(box);
    //     newboxes.push_back(Box(box.l, box.h, box.w));
    //     newboxes.push_back(Box(box.w, box.l, box.h));
    // }
    sort(newboxes.begin(), newboxes.end(), [](Box a, Box b) {
        // return a.l*a.w > b.l*b.w;
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
// solve again and sort them with max lenght and width and then calculate the stack of max height without diong for rotation



int main() {

    vector<Box> boxes = {Box(3,2,8), Box(1,1,1), Box(2,2,3), Box(4,5,7), Box(1,1,3)};

    cout<<solve(boxes, 0)<<endl;
    cout<<masabsolution(boxes)<<endl;


    return 0;
}