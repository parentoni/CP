#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define print(x) for (auto el: x) cout << el << " "; cout << '\n'

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
ll n;

void solve() {
  vl a(n); for (auto &el: a) cin >> el;
  vl lis(n), dp;

  for (int i=0;i<n;i++) {
    ll pos = lower_bound(all(dp), a[i]) - dp.begin();
    if (pos == dp.size()) {
      dp.push_back(a[i]);
    } else {
      dp[pos] = a[i];
    }

    lis[i] = dp.size();
  }

  dp.clear();

  ll ans = 1;
  for (int i=n-1;i>=0;i--) {
    ll pos = lower_bound(all(dp), a[i]) - dp.begin();
    if (pos == dp.size()) {
      dp.push_back(a[i]);
    } else {
      dp[pos] = a[i];
    }

    if (dp.size() == lis[i]) ans = max(ans, lis[i]*2-1);
  }

  cout << ans << endl;


}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> n) solve();
}
