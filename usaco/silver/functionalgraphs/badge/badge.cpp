#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using vl = vector<long long>;

const ll MAX_N = 1000;
ll n, succ[MAX_N+1], ans[MAX_N+1];
bool cycle[MAX_N+1], visited[MAX_N+1];
vl adj[MAX_N+1];

void floyd(ll x){
  ll a = succ[x];
  ll b = succ[succ[x]];

  while (a!=b) {
    a = succ[a];
    b = succ[succ[b]];
  }

  b = succ[a];
  ans[a] = a;

  while(a!=b) {
    ans[b] = b;
    b = succ[b];
  }
}

void dfs(ll x) {
  if (visited[x]) return;
  visited[x] = true;
  for (auto u: adj[x]) dfs(u);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> n;

  for (int i=1;i<=n;i++) {
    ll t; cin >> t;
    succ[i] = t;
    adj[i].push_back(t);
    adj[t].push_back(i);
  }

  for (int i=1;i<=n;i++) {
    if (visited[i]) continue;
    floyd(i);
  }

  for (int i=1;i<=n;i++) {
    if (ans[i]) continue;

    vl proc;
    ll a = i;

    while(!ans[a] && succ[a] != a) {
      proc.push_back(a); a = succ[a];
    }

    for (auto el: proc) ans[el] = ans[a];

  }
  
  for (int i=1;i<=n;i++) cout << ans[i] << " ";
  cout << endl;
}
