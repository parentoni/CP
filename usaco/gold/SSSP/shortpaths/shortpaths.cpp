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
const ll MAX_N = 2 * 1e5;

vector<pll> adj[MAX_N+1];
ll n, m, depth[MAX_N+1];
bool processed[MAX_N+1];

priority_queue<pll, vector<pll>, greater<pll>> q;

void djikstra() {

  q.push({0,1});
  while(q.size()) {

    pll a = q.top();
    q.pop();
    if (depth[a.second] != a.first) continue; // distance has already been modified by better one;
    for (auto u: adj[a.second]) {
      ll l = a.first + u.second;
      if (l < depth[u.first]) {
        depth[u.first] = l;
        q.push({l, u.first});
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
    adj[a].push_back({b,c});
  }

  for (auto &el: depth) el = INF;
  depth[1] = 0;

  djikstra();
  for (int i=1;i<=n;i++) {
    cout << depth[i] << " ";
  }
  cout << endl;
}
