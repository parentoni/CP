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
const ll MAX_N = 1e5;


ll n, m, state[MAX_N+1], dp[MAX_N+1], came[MAX_N+1];
vl adj[MAX_N+1];

vl top;
void dfs(ll x) {
  if (state[x] != 0) return;
  state[x] = 1;
  for (auto u: adj[x]) {
    dfs(u);
  }
  state[x] = 2;
  top.push_back(x);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i=0;i<m;i++) {
    ll a, b; cin >> a >> b;
    adj[a].push_back(b);
  }

  dfs(1);
  reverse(all(top));
  //print(top);

  dp[1] = 1; came[1] = 1;
  for (int i=0;i<top.size();i++) {
    for (auto u: adj[top[i]]) {
      if (dp[top[i]] + 1 > dp[u]) {
        came[u] = top[i];
        dp[u] = dp[top[i]]+1;
      }
    }
  }
  
  if (dp[n] == 0) cout << "IMPOSSIBLE" << endl;
  else {
    vl ans;
    ans.push_back(n);
    ll a = n;
    while(came[a] != a) {
      a = came[a];
      ans.push_back(a);
    }
    
    cout << dp[n] << endl;
    reverse(all(ans));
    print(ans);
  }
}
