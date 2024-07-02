#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll,ll>;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vl val;
  ll n, k; cin >> n >> k;

  val.resize(n);
  for (auto &el: val) cin >> el;
  sort(all(val));


  cout << val[n-k] << endl;
}
