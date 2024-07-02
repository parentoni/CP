#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;

const ll MAX_N = 1000;

ll s, t, p, ans = 0;
vl adj[MAX_N+1]; 

void solve() {
  vl path;
  
  ll size; cin >> size; path.resize(size);
  for (auto &el: path) cin >> el;


  bool valid = true;
  for (int i=1;i<path.size();i++) {
    bool found = false;
    for (auto el: adj[path[i-1]]) {
      if (el == path[i]) found = true;
    }

    //cout << found << endl;
    if (!found) valid = false;
  }

  if (valid) ans++;

}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> s >> t;

  for (int i=0;i<t;i++) {
    ll a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  cin >> p;

  while (p--) {
    solve();
  }

  cout << ans << endl;
}
