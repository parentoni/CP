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
const ll MAXN = 2*1e5;
ll n, m;

void solve() {

  vl d(n, INF);
  vector<bool> v(n,0);
  vector<pll> adj[n];

  using T = pll; 
  priority_queue<T, vector<T>, greater<T>> q;

  ll initial = 0, current = 0, a = 0;
  for (int i=0;i<m;i++) {
    ll a, b, c; cin >> a >> b >> c;
    initial += c; adj[a].push_back({b,c});
    adj[b].push_back({a,c});
  }

  d[0] = 0; q.push({0,0});
  while(a < n) {
    if (q.empty()) return;
    pll c = q.top(); q.pop();

    //cout << c.f << " " << c.s << endl;
    if (d[c.s] < c.f) continue;
    a++; current += c.f; v[c.s] = true;

    for (auto el: adj[c.s]) {
      if (!v[el.f] && d[el.f] > el.s) {
        d[el.f] = el.s;
        q.push({d[el.f], el.f});
      }
    }
  }

  cout << initial - current << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(cin >> n >> m) {
    if (n+m == 0) continue;
    solve();
  }
}
