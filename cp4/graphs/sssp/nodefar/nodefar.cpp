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
ll n, casen = 1;

void solve() {
  //precalculate bfs for all nodes;
  map<ll, vl> adj;
  map<ll, map<ll, ll>> distance;

  ll count = 0;
  for (int i=0;i<n;i++) {
    ll a, b; cin >> a >> b; 
    if (adj[a].size() == 0) count++;
    adj[a].push_back(b);
    if (adj[b].size() == 0) count++;
    adj[b].push_back(a);
  }

  queue<ll> q;
  for (auto &[x, _]: adj) {
    
    q.push(x);
    distance[x][x] = 1; //remember to shift back when counting

    while (q.size()) {
      ll a = q.front();
      q.pop();
      for (auto u: adj[a]) {
        if (distance[x][u] != 0) continue;
        distance[x][u] = distance[x][a] + 1;
        q.push(u);
      }
    }

  }

  ll s, ttl;
  while(cin >> s >> ttl) {
    if (s + ttl == 0) break;
    ll ans = count;
    for (auto &[_, x]: distance[s]) ans -= (x-1) <= ttl;
    cout << "Case " << casen << ": " << ans << " nodes not reachable from node " << s << " with TTL = " << ttl << ".\n";
    casen++;
  }


}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> n) {
    if (n == 0) return 0;

    solve();
  }
}
