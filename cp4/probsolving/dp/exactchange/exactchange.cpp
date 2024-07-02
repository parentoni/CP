#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using llb = long double;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// geometry
const double PI = 3.14159265358979323846;
double DEG_to_RAD (double d) {return d*PI/180.0;}
double RAD_to_DEG (double r) {return r*180.0/ PI;}

// values
const ll INF = 1e18;
const ll MOD = 1000000007;
const ll MAX_N = 1000000;


void solve() {

  ll k, n, s = 0; cin >> k >> n; vl coins(n);
  for (int i=0;i<n;i++) {
    ll t; cin >> t; s += t; coins[i] = t;
  }


  vl dp(s+1,INF);
  dp[0] = 0;


  for (auto el: coins) {
    for (int i=s;i>=0;i--) {
      if (i - el < 0) continue;
      if (dp[i - el] == INF) continue;

      dp[i] = min(dp[i], dp[i-el]+1);
    }
  }

  
  for (int i=k;i<=s;i++) {
    if (dp[i] == INF) continue;
    cout << i << " " << dp[i] << endl; return;
  }

}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll t; cin >> t; while (t--) solve();
}