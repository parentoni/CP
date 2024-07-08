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
const ll MAX_N = 2500;

vl adj[MAX_N+1];

ll n, m;
ll ans = INF;

ll girth_at_x(ll x) {

  ll ans = INF;

  queue<ll> q; vl distance(n+1, -1);
  q.push(x); distance[x] = 0;

  while(q.size()){

    ll a = q.front();

    for (auto u: adj[a]) {
      if (distance[u] == -1) {
        distance[u] = distance[a]+1;
        q.push(u);
      } else if (distance[u] >= distance[a]) {
        ans = min(ans, distance[u] + distance[a] + 1);
      }
    }
    q.pop();
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i=0;i<m;i++) {
    ll a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }


  ll ans = INF;
  for (int i=1;i<=n;i++) ans = min(ans, girth_at_x(i));

  cout << (ans == INF? -1: ans) << endl;
}
