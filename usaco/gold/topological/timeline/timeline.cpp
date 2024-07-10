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
const ll MAX_N = 1e5;

ll n, m, c, state[MAX_N+1], dp[MAX_N+1];
vl top; vector<pll> adj[MAX_N+1];

void dfs(ll x) {
  if (state[x] != 0) return;
  state[x] = 1;
  for (auto u: adj[x]) {
    dfs(u.first);
  }

  state[x] = 2;
  top.push_back(x);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("timeline");
  cin >> n >> m >> c;

  for (int i=1;i<=n;i++) cin >> dp[i];

  for (int i=0;i<c;i++) {
    ll a, b, w; cin >> a >> b >> w;
    adj[a].push_back({b,w});
  }

  for (int i=1;i<=n;i++) {
    if (state[i] == 0) dfs(i);
  }

  reverse(all(top));
  for (int i=0;i<top.size();i++) {
    for (auto u: adj[top[i]]) {
      dp[u.first] = max(dp[u.first], dp[top[i]] + u.second);
    }
  }
  
  for (int i=1;i<=n;i++) cout << dp[i] << endl;
}
