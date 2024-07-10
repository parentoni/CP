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
const ll MAX_N = 1e5;

ll n, m, d[MAX_N+1][2]; // d[x][0] distance from 1 to x. d[x][1] distance from n to x;
vector<pll> adj[MAX_N+1][2]; // forward and backwards
bool visited[MAX_N+1][2];


priority_queue<pll, vector<pll>, greater<pll>> q;
void djikstra(ll s, ll m) {
  q.push({0, s});
  d[s][m] = 0;

  while(q.size()) {
    pll a = q.top();
    q.pop();
    if (d[a.s][m] != a.f) continue;
    for (auto &[v,w]: adj[a.s][m]) {
      if (d[a.s][m] + w < d[v][m]) {
        d[v][m] = d[a.s][m] + w;
        q.push({d[v][m], v});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i=0;i<m;i++) {
    ll a, b, c; cin >> a >> b >> c;
    adj[a][0].push_back({b,c});
    adj[b][1].push_back({a,c});
  }

  for (int i=0;i<2;i++) {
    for (int j=0;j<MAX_N+1;j++) d[j][i] = INF;
  }

  djikstra(1, 0);
  djikstra(n, 1);
  
  // go trough all edges
  ll ans = d[n][0];

  for (int i=1;i<=n;i++) {
    for (auto &[v, w]: adj[i][0]) {
      ans = min(ans, d[i][0] + d[v][1] + w/2);
    }
  }
  cout << ans << endl;

}
