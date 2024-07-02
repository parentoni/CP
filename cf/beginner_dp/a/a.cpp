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

ll n;
vl values;
/**
 * Dynamic programing.
 * creates an 1-D array that holds the maximum value up to that step. Iterative push DP;
 * */
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("ladder");

  cin >> n; values.resize(n);
  for (auto &el: values) cin >> el;

  vl dp(n+1, -inf);
  dp[0] = 0;

  for (int i=0;i<=n;i++) {
    for (int j=1;j<=2;j++){
      if (i + j > n) continue;
      dp[i+j] = max(dp[i] + values[i+j-1], dp[i+j]);
    }
  }

  cout << dp[n] << endl;
}
