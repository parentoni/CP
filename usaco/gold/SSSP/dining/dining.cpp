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
const ll MAX_N = 50000;

ll n, m, k;
ll d[MAX_N+1];
ll dh[MAX_N+1];

vector<pll> adj[MAX_N+1];
bool possible[MAX_N+1];
ll hay[MAX_N+1];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("dining");

  cin >> n >> m >> k;
  for (int i=0;i<m;i++) {
    ll a, b, c; cin >> a >> b >> c;
    adj[a].push_back({b,c});
    adj[b].push_back({a,c});
  }

  using T = pll;
  priority_queue<T, vector<T>, greater<T>> q;

  for (int i=1;i<=n;i++) d[i] = INF;
  for (int i=1;i<=n;i++) dh[i] = INF;
  d[n] = 0; q.push({0,n});

  while(q.size()) {
    T a = q.top(); q.pop();
    if (d[a.s] != a.f) continue;

    for (auto &[v, w]: adj[a.s]) {
      if (d[v] > a.f + w) {
        d[v] = a.f + w;
        q.push({d[v], v});
      }
    }
  }

  for (int i=0;i<k;i++) {
    ll a, b;cin >> a >> b;
    hay[a] = max(hay[a], b);
  }

  for (int i=1;i<=n;i++) {
    if (hay[i] == 0) continue; 
    q.push({-hay[i]+d[i], i});
    dh[i] = -hay[i] + d[i];
  }


  while(q.size()) {
    T a = q.top(); q.pop();
    if (dh[a.s] != a.f) continue;
    for (auto &[v, w]: adj[a.s]) {
      if (a.f + w < dh[v]) {
        dh[v] = a.f + w;
        q.push({dh[v], v});
      }
    }
  }

  for (int i=1;i<=n;i++) {
    possible[i] = (-dh[i] + d[i]) >= 0;
  }

  for (int i=1;i<n;i++) {
    cout << possible[i] << endl;
  }

}
