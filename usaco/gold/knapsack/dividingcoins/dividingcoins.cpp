#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define print(x) for (auto el: x) cout << el << " "; cout << '\n'
#define f first
#define s second

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

void solve() {
  ll n; cin >> n; vl coins(n);
  ll tot = 0;
  for (int i=0;i<n;i++) {
    ll t; cin >> t; tot += t; coins[i] = t;
  }

  vector<vector<bool>> dp(n+1, vector<bool>(tot+1, 0));
  dp[0][0] = 1;
  if (n == 0) {
    cout << 0 << endl;return;
  }
  
  ll ans = INF;
  for (int j=0;j<n;j++) {
    for (int i=1;i<=tot;i++) {
      if (i-coins[j] >= 0) {
        if (dp[j][i-coins[j]]) dp[j+1][i] = true;
      }

      dp[j+1][i] = dp[j+1][i] || dp[j][i];
      if (dp[j+1][i]) ans = min(ans, abs((tot - i) - i));
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  ll t; cin >> t; while(t--) solve();

}
