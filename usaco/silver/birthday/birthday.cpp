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
const ll MAX_N= 100;
ll n = -1, m =-1;


vl friends[MAX_N];
bool visited[MAX_N];
ll nodes = 0;
pll lost;

void dfs(ll i) {
  if (visited[i]) return;
  nodes++;
  visited[i] = 1;

  for (auto u: friends[i]){
    if (lost.first == u && lost.second == i) continue;
    if (lost.first == i && lost.second == u) continue;
    dfs(u);
  }

}
void solve() {
  for (auto &el: friends) el = {};

  for (int i=0;i<m;i++){
    ll a,b; cin >> a >> b;
    friends[a].push_back(b); 
    friends[b].push_back(a);
  }

  bool valid = true;
  for (int i=0;i<n;i++){
    if (!valid) break;
    for (int j=i;j<n;j++){
      if (!valid) break;
      lost.first = i; lost.second = j;
      fill(visited, visited + MAX_N, 0);
      nodes = 0;

      dfs(0);
      if (nodes != n) valid = false;

    }
  }
  if (!valid) cout << "Yes" << endl;
  else cout << "No" << endl;

}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setio("");


  while(1) {
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    solve();

  }
}
