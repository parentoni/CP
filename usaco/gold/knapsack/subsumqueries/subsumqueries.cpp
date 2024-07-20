#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll inf = 1e18;
const ll mod = 998244353;

ll n,k;
vector<pair<bool, ll>> ops;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  cin >> n >> k; ops.resize(n);
  for (int i=0;i<n;i++) {
    char m; ll q; cin >> m >> q;
    ops[i] = {m == '+', q};
  }

  vector<vl> dp(n+1, vl(k+1, 0));
  dp[0][0] = 1;
  map<ll,ll> ref;

  for (int o=1;o<=n;o++) {
    for (int s=0;s<=k;s++) {
      if (ops[o-1].first) {
        if (s - ops[o-1].second >= 0) dp[o][s] += dp[o-1][s-ops[o-1].second];
        dp[o][s] += dp[o-1][s];
        dp[o][s] = dp[o][s] % mod;
      } else {

      }


      ref[ops[o-1].second] = o;
    }
  }

  for (int o=0;o<=n;o++) {
    for (int s=0;s<=k;s++) cout << dp[o][s] << " "; 
    cout << endl;
  }
}
