
#include <bits/stdc++.h>
using namespace std;

/**** pre-defined keywords ******/

#define IO                      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb                      push_back
#define ppb                     pop_back
#define upper(s)                transform(s.begin(), s.end(), s.begin(), ::toupper);
#define lower(s)                transform(s.begin(), s.end(), s.begin(), ::tolower);
#define Imax                    pow(10,9)
#define sz(x)                   (int)x.size()
#define setbits                 __builtin_popcount
#define ff                      first
#define ss                      second
#define setbitsll               __builtin_popcountll
#define mp                      make_pair
#define all(x)                  (x).begin(),(x).end()

#define unordered_map           um;
/****** short-hands *******/

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vInt;
typedef stack<int> stInt;
typedef queue<int> qInt;
void heapify(vector<int>&v,int i,int n)
{
    int l = 2 * i;
    int r = l + 1;
    int mx = i;
    if(l<n && v[i]<v[l])
    {
        mx = l;
    }
    if(r<n && v[mx]<v[r])
    {
        mx = r;
    }
    if(mx!=i){
        swap(v[i], v[mx]);
        heapify(v,mx,n);
    }
}
void solve()
{
    vector<int> v = {0,3, 1, 6, 5, 2, 8};

    for (int i = v.size() / 2; i >= 1;i--)
    {
        heapify(v, i,v.size());
    }

    for (int i = 0; i < v.size();i++)
    {
        cout << v[i] << " ";
    }
    
    cout << endl;

    for(int i = v.size() - 1;i > 0;i--)
    {
        swap(v[1], v[i]);
        heapify(v, 1, i);
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
signed main()
{
    
    solve();
    return 0;
}