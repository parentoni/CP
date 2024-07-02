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
const ll INF = 1e18;
const ll MOD = 1000000007;
const double EPS = 1e-9;

void solve() {
  ll n; cin >> n;
  ll r; cin >> r;

  for (int i=0;i<n-1;i++) {
    ll t; cin >> t;
    r &= t;
  }
  cout << r << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll t; cin >> t; while(t--) solve();
}
