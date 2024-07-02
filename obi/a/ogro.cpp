#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll,ll>;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  ll e, d; cin >> e >> d;
  
  if (e > d) cout << e + d << endl;
  else cout << 2 * (d-e) << endl;
}
