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
const ll MAX_N = 100;

void solve(ll x) {
  if (x != 0) cout << endl;
  ll n, e, t, m; cin >> n >> e >> t >> m;

  vector<pll> adj[n+1];
  vl d(n+1, INF);
  ll ans = 0;

  for (int i=0;i<m;i++) {
    ll a, b, c; cin >> a >> b >> c;
    adj[b].push_back({a,c});
  }


  priority_queue<pll, vector<pll>, greater<pll>> q; q.push({0, e});
  d[e] = 0;
  
  while(q.size()) {
    pll a = q.top(); q.pop();
    if (d[a.s] != a.f) continue;
    if (a.f <= t) ans++;

    for (auto u: adj[a.s]) {
      if (d[u.f] > a.f + u.s) {
        d[u.f] = a.f + u.s;
        q.push({d[u.f], u.f});
      }
    }
  }

  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


  ll t; cin >> t; 
  for (int i=0;i<t;i++) solve(i);
}
