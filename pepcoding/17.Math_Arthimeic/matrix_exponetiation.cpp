/*



T X f(n) = f(n+1)

[ 1 1 ] [ f(n) ] = [ f(n+1) ]
[ 1 0 ] [ f(n-1) ] = [ f(n)





*/
#include <bits/stdc++.h>
using namespace std;


struct Mat {
    int sz;
    vector<vector<int>> data;

    Mat(int sz)  {
        this->sz = sz;
        data.resize(sz, vector<int>(sz, 0));
    }

    void identity() {
        for( int i = 0; i < sz; i++) {
            data[i][i] = 1;
        }
    }

    Mat operator*(Mat &other) {
        Mat res(sz);
        for( int i = 0; i < sz; i++) {
            for( int j = 0; j < sz; j++) {
                for( int k = 0; k < sz; k++) {
                    res.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return res;
    }

    void print() {
        for( int i = 0; i < sz; i++) {
            for( int j = 0; j < sz; j++) {
                cout<<data[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};



int main() {


    Mat a(2);
    a.data[0][0] = a.data[0][1] = a.data[1][0] = 1;

    Mat b(2);
    b.identity();


    a = a*b;

    a.print();

    

    return 0;
}