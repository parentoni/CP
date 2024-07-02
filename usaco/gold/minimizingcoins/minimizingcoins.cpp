#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setio(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"yes\n"; }
void no() { cout<<"no\n"; }

// values
const ll inf = 1e18;
const ll mod = 1000000007;
const ll MAX_N = 1e6;

ll n, x;
vl coins;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setio("");

  cin >> n >> x; coins.resize(n);
  for (auto &el: coins) cin >> el;

  vl dp(x + 1, inf);

  dp[0] = 0;

  for (int i=1;i<=x;i++) {
    for (auto el: coins) {
      if (i - el < 0) continue;
      dp[i] = min(dp[i], dp[i-el]+1);
    }
  }

  cout << (dp[x] == inf? -1: dp[x])<< endl;

}
