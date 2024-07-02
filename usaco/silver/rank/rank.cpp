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
const ll MAX_N = 20;
const ll MAX_K = 30;

ll n,k, y=0;
vl games[MAX_N];
bool visited[MAX_N], cycle[MAX_N];
ll original;

void dfs(ll i){
  visited[i] = true;

  if (i == original) {
    cycle[i]= true;
    return;
  }

  for (auto u: games[i]) {
    if (!visited[u]) dfs(u);
  }

}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setio("");

  cin >> n >> k;
  for (int i=0;i<k;i++) {
    ll a,b, sa, sb;
    cin >> a >> b >> sa >> sb;

    if (sa > sb) games[--a].push_back(--b);
    else games[--b].push_back(--a);
  }

  for (int i=0;i<n;i++){
    original = i;
    fill(visited, visited + MAX_N, 0);
    for (auto u: games[i]) dfs(u);
  }

  for (auto el: cycle) {if (el) y++;}
  cout << y << endl;


}
