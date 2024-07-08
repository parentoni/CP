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
const ll MAX_N = 40000;

ll b, e, p, n, m;
ll diste[MAX_N+1], distb[MAX_N+1], distp[MAX_N+1];
vl adj[MAX_N+1];

ll mode = 0;
queue<ll> q;
void bfs() {

  while (q.size()) {
    ll a = q.front();
    q.pop();

    for (auto u: adj[a]) {
      if (distb[u] != -1 && mode == 0) continue;
      if (diste[u] != -1 && mode == 1) continue;

      q.push(u); 
      if (mode == 0) distb[u] = distb[a] + 1;
      if (mode == 1) diste[u] = diste[a] + 1;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("piggyback");


  cin >> b >> e >> p >> n >> m;

  for (int i=0;i<m;i++) {
    ll x,y; cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  memset(distb, -1, sizeof(distb));
  memset(diste, -1, sizeof(diste));
  memset(distp, -1, sizeof(distp));

  distb[1] = 0; diste[2] = 0;
  
  q.push(1);bfs(); mode = 1;q.push(2); bfs();
  ll ans = INF;

  q.push(n); distp[n] = 0;
  while (q.size()) {
    ll a = q.front();
    q.pop();

    for (auto u: adj[a]) {
      if (distp[u] != -1) continue;
      distp[u] = distp[a] + 1; q.push(u);
    }

  }
  for (int i=1;i<=n;i++) {
    ans = min(ans, b * distb[i] + e * diste[i] + p * distp[i]);
  }
  cout << ans << endl;

}
