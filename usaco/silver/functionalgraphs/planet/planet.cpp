#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using vl = vector<long long>;

const ll MAX_N = 2*1e5;

ll n;
ll succ[MAX_N+1], ans[MAX_N+1];
vl process, adj[MAX_N+1];
bool visited[MAX_N+1];

void floyd(ll x) {

  ll a = succ[x];
  ll b = succ[succ[x]];
  while(a!=b) {
    a = succ[a];
    b = succ[succ[b]];
  }

  ll lambda = 1;
  b = succ[a];
  while(a!=b) {
    b = succ[b]; lambda++;
  }


  b = succ[a];
  ans[a] = lambda;
  while(a!=b) {
    ans[b] = lambda;
    b = succ[b];
  }

}

void dfs(ll x) {
  if (visited[x]) return;
  visited[x] = true;

  for (auto u: adj[x]) {
    dfs(u);
  }
}

int main() {
  ios::sync_with_stdio();
  cin.tie(NULL);
  
  cin >> n; 
  for (int i=1;i<=n;i++) {
    ll t; cin >> t;
    succ[i] = t;
    adj[i].push_back(t); adj[t].push_back(i);
  }


  vl comp;

  for (int i=1;i<=n;i++) {
    if (visited[i]) continue;
    comp.push_back(i);
    dfs(i);
  }

  for (auto el: comp) floyd(el);

  for (int i=1;i<=n;i++) {
    if (ans[i]) continue;

    vl process = {i};
    ll a = succ[i], l = 1;
    while (!ans[a] && succ[a] != a) {
      process.push_back(a);
      a = succ[a];
      l++;
    }

    for (int i=1;i<=l;i++) {
      ans[process[l-i]] = i + ans[a];
    }
  }

  for (int i=1;i<=n;i++) cout << ans[i] << " ";
  cout << endl;
}
