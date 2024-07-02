#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  ll a, b, c;
  cin >> a >> b >> c;
  if (a % b == 0) {
    cout << a;
    for (int i=0;i<c;i++){
      cout << 0;
    }
    cout << endl;
    return 0;
  }
  
  a = a * 10;
  for (int i=0; i<=9;i++) {
    if (a % b == 0) {
      cout << a;
      for (int n=0; n<c-1;n++){
        cout << 0;
      }
      cout <<endl;
      return 0;
    }
    a++;
  }

  cout << -1 << endl;
}

