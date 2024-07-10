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
const ll MAX_N = 1000;

ll n, m;
vector<pair<ll, pair<double, double>>> adj[MAX_N+1]; // p.f - to; p.s.f - cost; p.s.s - flow;
ll dist[MAX_N+1];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("pump");

  cin >> n >> m;
  for (int i=0;i<m;i++) {
    ll a, b, c, f; cin >> a >> b >> c >> f;
    adj[a].push_back({b, {c,f}});
    adj[b].push_back({a, {c,f}});
  }

  
  using T = pair<ll , pair<ll, pair<double,double> > >; // p.f - flow/cost * 1e6; p.s.f - to; p.s.s.f - cost; p.s.s.s - flow;
  priority_queue<T, vector<T>, greater<T>> q;

  for (int i=1;i<=n;i++) {dist[i] = INF;}
  dist[1] = 0; q.push({0, {1, {0,INF}}});

  pair<double,double> info;
  while(q.size()){

    T a = q.top(); q.pop();
    if (dist[a.s.f] != a.f) continue; // ensures correct is selected
    if (a.s.f == n) info = a.s.s;

    for (auto &[v,info]: adj[a.s.f]){
      ll cost = floor((a.s.s.f + info.f)/min(info.s, a.s.s.s) * 1e6);
      if (dist[v] > cost) {
        dist[v] = cost;
        q.push({cost, {v, {a.s.s.f + info.f, min(info.s, a.s.s.s)}}});
      }
    }
  }

  cout << (ll)floor(info.s/info.f * 1e6) << endl;

}
