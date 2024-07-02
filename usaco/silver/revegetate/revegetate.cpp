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
const ll MAX_N = 1e5;

ll n, m;
vector<pair<ll, bool>> pasture[MAX_N]; // p.first -> adj list, p.second -> true if S, false otherwise.
bool visited[MAX_N];
bool color[MAX_N];
bool has_been_viewed[MAX_N];

bool valid = true;
set<ll> linked;

void dfs(ll x) {
  if (visited[x]) return;
  visited[x] = true;

  for (auto u: pasture[x]) {

    if (!has_been_viewed[u.first]){
      if (u.second) color[u.first] = color[x];
      else color[u.first] = !color[x];
      has_been_viewed[u.first] = true;
    } else {
      if (u.second && color[u.first] != color[x]) valid = false;
      if (!u.second && color[u.first] == color[x]) valid = false;
    }
    dfs(u.first);
  }

}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setio("revegetate");

  cin >> n >> m;
  for (int i=0;i<m;i++){
    char mode; ll a,b;
    cin >> mode >> a >> b;--a;--b;
    linked.insert(a); linked.insert(b);
    pasture[a].push_back({b, mode == 'S'?1:0});
    pasture[b].push_back({a, mode == 'S'?1:0});
  }

  ll c_num = 0;
  for (int i=0;i<n;i++){
    if (!visited[i]) {
      c_num++;
      color[i] = 1;
      dfs(i);
    }
  }

  if (!valid) {
    cout << 0 << endl;
  } else {
    cout << 1;
    for (ll i=0;i<c_num;i++) cout << 0;
    cout << endl;
  }
}
