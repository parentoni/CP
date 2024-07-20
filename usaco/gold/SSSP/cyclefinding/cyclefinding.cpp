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
const ll MAXN = 2500;

ll n, m, d[MAXN+1], came[MAXN+1];
vector<pll> adj[MAXN+1];
bool incycle[MAXN+1];

/**
 * Run bellman ford and after n-1 iter start recording all modfied nodes;
 * */

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i=1;i<=n;i++) {
    d[i] = INF;
  }

  for (int i=0;i<m;i++){
    ll a,b,c; cin >> a >> b >> c;
    adj[a].push_back({b,c});
  }

  for (int i=1;i<=n;i++) {
    adj[0].push_back({i, 0});
  }

  ll i = 0; d[0] = 0;
  ll last_mod;
  for (;;i++) {
    bool mod = false;
    for (int j=1;j<=n;j++) {
      for (auto u: adj[j]) {
        if (d[u.f] < d[j]+u.s) continue;

        if (i > n) {
          last_mod = j;
          mod = true;
        } else {
          mod = true;
        }

        came[u.f] = j;
        d[u.f] = d[j]+u.s;
      }
    }

    if (!mod) break;
    if (i>n) break;
  }

  if (i <= n) {
    no();
  } else {

    map<ll, bool> cycle;
    vl ans; ans.push_back(last_mod);
    last_mod = came[last_mod];

    while(!cycle[last_mod]) {
      ans.push_back(last_mod);
      cycle[last_mod] = true;
      last_mod = came[last_mod];
    }

    ans.push_back(last_mod);

    ll s;
    for (int i=0;;i++) {
      if (ans[i] != ans[ans.size()-1]) continue;
      s = i; break;
    }

    yes();
    for (int j=s;j<ans.size();j++) cout << ans[j] << " ";
    cout << endl;
    
  }
}
