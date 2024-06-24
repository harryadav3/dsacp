#include <bits/stdc++.h>
using namespace std;

void findsubsets(int i, vector<int> &nums, vector<vector<int>> &ans, int n, vector<int> ds, int sum, int target)
{
    if (i == n)
    {

        if (target == sum)
        {
            ans.push_back(ds);
        }
        return;
    }
    ds.push_back(nums[i]);
    sum += nums[i];
    findsubsets(i + 1, nums, ans, n, ds, sum, target);
    sum -= nums[i];
    ds.pop_back();

    findsubsets(i + 1, nums, ans, n, ds, sum, target);
}
int main()
{
    vector<int> nums = {1, 2, 1};
    int target = 2;

    vector<vector<int>> ans;
    vector<int> ds;
    int n = nums.size();
    findsubsets(0, nums, ans, n, ds, 0, target);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}