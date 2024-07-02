#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll inf = 1e18;
const ll MOD = 1000000007;
const ll MAX_N = 3000;

ll n, m;
vl barn[MAX_N + 1];
bool visited[MAX_N + 1];
bool closed[MAX_N + 1];
set<ll> open;

ll c =0;

void dfs(ll i) {
  if (visited[i] || closed[i]) return;
  c++;
  visited[i] = true;

  for (auto u: barn[i]){
    dfs(u);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("closing");
  
  cin >> n >> m;
  for (int i=1;i<=n;i++) open.insert(i);

  for (int i=0;i<m;i++){
    ll a,b;
    cin >> a >> b;
    barn[a].push_back(b); barn[b].push_back(a);
  }

  dfs(*open.begin());
  if (c==n) yes();
  else no();

  for (int i=1;i<=n-1;i++){
    ll e; cin >> e;

    closed[e]=1;
    open.erase(e);

    c = 0;
    for (auto &el: visited) el=0;

    dfs(*open.begin());

    if (c==n-i ) yes();
    else no();
  }


}
