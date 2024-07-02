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
const ll MAX_N = 5000;

ll n, q, min_k, s = 0;
vector<pll> videos[MAX_N]; //p.first -> adj, p.second -> weight;

void dfs(ll x, ll e) {
  s++;
  for (auto u: videos[x]){
  
    if (u.first == e || u.second < min_k) continue;
    dfs(u.first, x);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  setio("mootube");

  cin >> n >> q;

  for (int i=0;i<n-1;i++){
    ll a,b,w; cin >> a >> b >> w; --a;--b;
    videos[a].push_back({b,w});
    videos[b].push_back({a,w});
  }

  for (int i=0;i<q;i++){
    ll k, v; cin >> k >> v; v--;
    s = 0; min_k = k;
    dfs(v,v);
    cout << s-1 << endl;

  }
}
