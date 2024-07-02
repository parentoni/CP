
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int r = 0, l =0;
  for (int i=0;i<n;i++){
    for (int c=0;c<2;c++) {
      int t;
      cin >> t;
      if (c==0) {
         r = r+t; 
      } else {
        l = l+t;
      }
    }
  }

  int s =0;
  if (r <= n/2){
    s = s + r;
  } else {
    s = s + n - r;
  }

  if (l <= n/2){
    s = s + l;
  } else {
    s = s + n - l;
  }
  
  cout << s << endl;
}

