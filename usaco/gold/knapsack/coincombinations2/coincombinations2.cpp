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
const ll mod = 1000000007;

ll n, x;
vl coins;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  cin >> n >> x; coins.resize(n);
  for (auto &el: coins) cin >> el;

  vl dp(x, 0);
  dp[0] = 1;

  for (int i=0;i<n;i++) {
    for (int w=1;w<=x;w++) {
      if (w - coins[i] < 0) continue; 
      dp[w] += dp[w - coins[i]];
      dp[w] %= mod;
    }
  }


  cout << dp[x] << endl;

}
