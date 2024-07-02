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
const ll MAX_N = 2*1e5;

ll n;
vl employee[MAX_N];
ll sub[MAX_N];

void dfs(ll x, ll e) {
  sub[x] = 1;
  for (auto u: employee[x]) {
    if (u == e) continue;
    dfs(u, x);
    sub[x] += sub[u];
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> n;
  for (int i=1;i<n;i++){
    ll t; cin >> t;
    employee[--t].push_back(i);
    employee[i].push_back(t);
  }

  dfs(0, 0);
  for (int i=0;i<n;i++) cout << sub[i] - 1 << " ";
  cout << endl;
}
