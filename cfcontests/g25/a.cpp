#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int solve() {
  int n;
  cin >> n;

  string l;
  cin >> l;
  int s =0;
  int o; 
  for (int i=0;i<l.size();i++){
    if (l[i] == '1') {
      o = i;
      s++;
    }
  }

  if (s % 2 == 0) {
    if (s == 2) {
      if (l[o] == l[o-1]) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
    } else {
      cout << "YES" << endl;
    }
  }
  else cout << "NO" << endl;

  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >>t;
  while (t--) {
    solve();
  }
  // cout << r << endl;
}

