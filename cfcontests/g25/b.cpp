#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
int solve() {
  int n, k;
  cin >> n >>k;
  vector<ll> v;
  ll o;
  ll sm = -1;
  for (int i=0;i<n;i++){
    ll r;
    cin >> r;
    if (i == k-1) {
       o = r;
    }
    v.push_back(r);
  }

  int a = 0;
  for (int i=0;i<n;i++){
    int p = 0;
    vector<ll> c = v;
    swap(c[k-1], c[i]);
    while(c.size() != 1) {
      if (c[0] > c[1]) {
        if (c[0] == o) p++;
        c.erase(c.begin()+1);
      } else {
        if (c[1] == o) p++;
        c.erase(c.begin());
      }
    }
    a = max(a, p);
  }

  cout << a << endl;
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--){
    solve();
  }
}

