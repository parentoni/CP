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
const ll MAXN = 1e5;

ll n, k, db[MAXN+1], da[MAXN+1];
vl adj[MAXN+1];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("atlarge");


  cin >> n >> k;
  for (int i=1;i<=n;i++) da[i] = -1;
  for (int i=1;i<=n;i++) db[i] = -1;

  for (int i=0;i<n-1;i++) {
    ll a, b; cin >> a >> b;
    adj[a].push_back(b); adj[b].push_back(a);
  }

  vl exits;

  queue<ll> q;
  for (int i=1;i<=n;i++) {
    if (adj[i].size() == 1) {
      da[i] = 0; 
      q.push(i);
    }
  }


  while(q.size()) {
    ll a = q.front(); q.pop();
    for (auto u: adj[a]) {
      if (da[u] != -1) continue;
      da[u] = da[a]+1;
      q.push(u);
    }
  }


  q.push(k); db[k] = 0;

  ll ans = 0;
  while(q.size()) {
    ll a = q.front(); q.pop();

    if (da[a] <= db[a]) {
      ans++;
      continue;
    }

    for (auto u: adj[a]) {
      if (db[u] != -1) continue;
      db[u] = db[a]+1;
      q.push(u);
    }
  }

  cout << ans << endl;

}
