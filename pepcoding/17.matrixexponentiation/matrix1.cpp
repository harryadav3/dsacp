#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

struct Mat
{
    int sz;
    vector<vector<int>> data;

    // constructor
    Mat(int size)
    {
        sz = size;
        data.resize(sz, vector<int>(sz, 0));
    }

    void identity()
    {
        for (int i = 0; i < sz; i++)
        {
            data[i][i] = 1;
        }
    }
    Mat operator+(Mat& b)
    {
        Mat ans(this->sz);
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                ans.data[i][j] =( data[i][j] - b.data[i][j]) % mod;
            }
        }
        return ans;
    }
    Mat operator-(Mat& b)
    {
        Mat ans(this->sz);
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                ans.data[i][j] = ( data[i][j] + b.data[i][j]) % mod;
            }
        }
        return ans;
    }

    Mat operator*(Mat& b)
    {
        Mat ans(this->sz);
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                for (int k = 0; k < sz; k++)
                {
                    ans.data[i][j] += (data[i][k] * b.data[k][j]) % mod;
                  ans.data[i][j] %= mod;
                }
            }
        }
        return ans;
    }

    Mat operator*(int b){
        Mat ans(this->sz);
        for(int i=0; i<sz; i++){
            for(int j=0; j<sz; j++){
                ans.data[i][j] =( data[i][j] * b) % mod;
            }
        }
        return ans;
    }
        // O(log(b) * (sz^3))

    Mat operator^(int b){
        Mat ans(this->sz);
        ans.identity();
        Mat a = *this;
        while(b){
            if(b&1){
                ans = ans * a;
            }
            a = a * a;
            b = b>>1;
        }
        return ans;
    }

    void print()
    {
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};


int fib ( int n){
        if ( n <= 1 ) { 
            return n ;
        }

        Mat T(2);
        T.data = {
            {1,1},
            {1,0}
        };

        T = T ^ (n-1);
        return T.data[0][0];
}
int main()
{

    // Mat a(3), b(3);

    // b.data[0][0] = 4;

    // a.print();
    // a.identity();
    // a.print();

    // Mat c = a + b;
    // c.print();
    // Mat d = a - b;
    // d.print();
    // Mat e = a * b;
    // e.print();
    int n ; 
    cin >> n;

    for( int i =0; i<20; i++){
        cout<<i<<" "<<fib(i)<<endl;
    }
    return 0;
}