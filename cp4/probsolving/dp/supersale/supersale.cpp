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

  
ll n, g;

void solve() {
  cin >> n;
  vl price, weight, carry;

  for (int i=0;i<n;i++) {
    ll a, b; cin >> a >> b;
    price.push_back(a); weight.push_back(b);
  }

  cin >> g; carry.resize(g);
  for (auto &el: carry) cin >> el;

  
  ll ans = 0;
  for (int p=0;p<g;p++) {

    ll dp[1001][31] = {0};
    for (int i=1;i<=n;i++) {
      for (int j=1;j<=carry[p];j++) {

        dp[i][j] = dp[i-1][j];
        if (weight[i-1] <= j) {
          dp[i][j] = max(dp[i][j], dp[i-1][j-weight[i-1]] + price[i-1]);
        }
      }
    }

    ans += dp[n][carry[p]];
  }

  cout << ans << endl;

  
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  ll t; cin >> t; while (t--) solve();
}
