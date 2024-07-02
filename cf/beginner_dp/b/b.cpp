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
ll n; string v;
ll w[3] = {1,3,5};
/**
 * Dynamic programming.
 * Iterative push DP.
 * State: position of rabbit.
 * Transition: dp[i + x] = dp[i+x] || dp[i] if square is not swamp;
 * */

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("lepus");

  cin >> n >> v;

  vector<bool> dp(n,false);
  dp[0] = true; // rabbit can always reach 0th square.


  for (int i=0;i<n;i++) {
    for (auto jump: w) {
      if (i + jump >= n) continue;
      if (v[i+jump] == 'w') continue;

      dp[i+jump] = dp[i+jump] ||  dp[i];
    }
  }

  if (!dp[n-1]) {
    cout << -1 << endl;
    return 0;
  }


  ll r= 0;
  for (int i=0;i<n;i++) if (dp[i] && v[i] == '"') r++;
  cout << r << endl;

}
