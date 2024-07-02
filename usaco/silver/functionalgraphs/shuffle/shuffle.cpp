#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using vl = vector<long long>;

const ll MAX_N = 100000;
ll n, succ[MAX_N+1], rfg[MAX_N+1], cycle[MAX_N+1];
bool visited[MAX_N+1];

void floyd(ll x) {
  ll a = succ[x];
  ll b = succ[succ[x]];

  while (a!=b) {
    a = succ[a];
    b = succ[succ[b]];
  }


  cycle[a] = true;
  b = succ[a];
  while(a!=b) {
    cycle[b] = true;
    b = succ[b];
  }
}

void dfs(ll x) {
  if (visited[x]) return;
  visited[x] = true;

  dfs(succ[x]);
  dfs(rfg[x]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  freopen("shuffle.in", "r", stdin);

  cin >> n;
  for (int i=1;i<=n;i++) {
    ll t; cin >>t;
    succ[i] = t;
    rfg[t] = i;
  }

  vl comp;
  for (int i=1;i<=n;i++){
    if (visited[i]) continue;
    comp.push_back(i);
    dfs(i);
  }

  for (auto el: comp) {
    floyd(el);
  }

  ll r =0;
  for (auto el: cycle) if (el) r++;


  freopen("shuffle.out", "w", stdout);
  cout << r << endl;
}
