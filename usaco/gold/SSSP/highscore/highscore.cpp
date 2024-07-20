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
const ll MAX_N = 2500;

ll n, m;
vector<pll> adj[MAX_N+1];

bool incycle[MAX_N+1], visited[MAX_N+1];

void dfs(ll x) {
  if (visited[x]) return;
  visited[x] = true;
  for (auto u: adj[x]) dfs(u.f);
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i=0;i<m;i++) {
    ll a, b, c; cin >> a >> b >> c;
    adj[a].push_back({b, -1 * c}); // invert the weights
  }

  vl d(MAX_N+1, INF);
  d[1] = 0;
  int i=0;
  vl cycle;
  bool mod = false;

  for (;;i++) {
    mod = false;
    for (int j=1;j<=n;j++) {
      if (d[j] == INF) continue;
      for (auto &[v, w]: adj[j]) {
        if (d[v] > d[j] + w) {
          if (i >= n) {
            if (incycle[v]) continue;
            mod = true;
            incycle[v] = true;
          } else {
            mod = true;
          }

          d[v] = d[j] + w;
        }
      }
    }

    if (mod == false) break;
  }

  for (int i=1;i<=n;i++) {
    if (!visited[i] && incycle[i]) dfs(i);
  }

  if (i > n && visited[n]) {
    cout << -1 << endl;
  } else {
    cout << d[n]*-1 << endl;
  }

}
