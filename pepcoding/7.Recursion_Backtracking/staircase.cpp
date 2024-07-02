#include <bits/stdc++.h>
using namespace std;
int staircase(int n) {
  if (n == 0) {
    return 1;
  }
  if (n < 0) {
    return 0;
  }
  int ans = 0;
  ans += staircase(n - 1);
  ans += staircase(n - 2);
  ans += staircase(n - 3);
  return ans;
}
int climbingstairprint(int n, vector<int> a){
  if(n== 0 ){
    for( auto i : a){
      cout<<i<<" ";
    }
    cout<<endl;
  }
  if(n<0){
    return 0;
  }
  int ans = 0;
  a.push_back(1);
  ans += climbingstairprint(n-1,a);
  a.pop_back();
  a.push_back(2);
  ans += climbingstairprint(n-2,a);
  a.pop_back();
  a.push_back(3);
  ans += climbingstairprint(n-3,a);
  a.pop_back();
  return ans;

}

int masabsolution(int n, vector<int> v){

    if(n==0){
      v.push_back(0);
      cout<<"[";
      for(auto i : v){
        cout<<i<<",";
      }
      cout<<"]"<<endl;
      v.pop_back(); 
    }
    else if(n < 0){
      return 0;

    }

    v.push_back(n);
    int ans = masabsolution(n-1,v) + masabsolution(n-2,v) + masabsolution(n-3,v);
    v.pop_back();

    return ans;
    
}
int main() {

  int n = staircase(4);
  climbingstairprint(4, {});
  cout << n;
  return 0;
}
