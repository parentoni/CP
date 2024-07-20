#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(x) (x).begin(), (x).end()
#define print(x) for (auto el: x) cout << el << " "; cout << '\n'
#define f first
#define s second

using ll = long long;
using llb = long double;
using vl = vector<ll>;
using pll = pair<ll,ll>;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

ll n, m, state[MAXN];
vl adj[MAXN], top;

bool valid = true;
void dfs(ll x) {
  if (state[x] == 2) return;
  if (state[x] == 1) {
    valid = false; return;
  }

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

  for (int i=1;i<=n;i++) {
    if (state[i] != 0) continue;
    dfs(i);
  }

  reverse(all(top));
  if (!valid) cout << "Sandro fails." << endl;
  else print(top);


}
