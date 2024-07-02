#include <bits/stdc++.h>
using namespace std;

using vl = vector<long long>;
using ll = long long;

ll c, n, m, farms;
vl queries, curr;

int main() {
  ios::sync_with_stdio(0); cin.tie(NULL);

  cin >> c >> n >> m; queries.resize(m); 
  vector<vl>> dp(1001, vl(51, 0));

  for (int i=0;i<n;i++) {
    ll t; cin >> t;
    dp[t][0]++;
  }

  for (auto &el: queries) cin >> el;

  for (int t=0;t<50;t++) {
    for(int i=1;i<=1000;i++) {
      if (i * 2 > c) dp[i][t+1] += dp[i][t] * 2;  
      else {
        dp[i * 2][t+1] += dp[i][t];
      }
    }
  }

  for (auto el: queries) {
    ll ans = 0;
    for (int i=0;i<=1000;i++) ans += dp[i][el];
    cout << ans << endl;
  }

}
