#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setio(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"yes\n"; }
void no() { cout<<"no\n"; }

// values
const ll inf = 1e18;
const ll mod = 1000000007;
const ll MAX_N = 2 * 1e5;

ll n, max_distance = 0, max_distance_el;
vl tree[MAX_N];

void dfs(ll x, ll e, ll distance) {
  if (distance > max_distance) {
    max_distance = distance;
    max_distance_el = x;
  }

  for (auto u: tree[x]) {
    if (u == e) continue;
    dfs(u, x, distance+1);
  }

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setio("");

  cin >> n;
  for (int i=1;i<n;i++) {
    ll a,b; cin >> a >> b; --a; --b;
    tree[a].push_back(b); tree[b].push_back(a);
  }
  
  dfs(0, 0, 0);
  ll b = max_distance_el;
  max_distance_el = -1; max_distance = 0;
  
  dfs(b, b, 0);
  cout << max_distance << endl;

}
