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

// bellman ford, see if current iter is largest then n-1;
void solve() {
  ll n, m; cin >> n >> m;

  vector<pll> adj[n];
  vl d(n, INF);

  for (int i=0;i<m;i++) {
    ll a, b, c; cin >> a >> b >> c;
    adj[a].push_back({b,c});
  }

  ll i = 0;
  d[0] = 0;
  for (;;i++) {
    bool mod = false;

    if (i == n) break;
    for (int j=0;j<n;j++) {
      if (d[j] == INF) continue;
      for (auto u: adj[j]) {
        if (d[u.f] <= d[j] + u.s) continue;
        mod = true;
        d[u.f] = d[j] + u.s;
      }
    }

    if (!mod) break;
  }

  if (i == n) cout << "possible" << endl;
  else cout << "not possible" << endl;

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll t; cin >> t; while(t--) solve();

}
