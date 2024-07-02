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
vl farm[MAX_N];
bool cows[MAX_N]; // true if H, false if G;
bool visited[MAX_N];
map<ll, ll> comp;

bool selected;
ll curr_comp = 1;
void dfs(ll x) {
  if (visited[x] || cows[x] != selected) return;
  visited[x] = true;
  comp[x] = curr_comp;

  for (auto u: farm[x]) {
    dfs(u);
  }

}

bool ishappy(ll x, ll y, bool mode) {
  if (cows[x] == mode || cows[y] == mode) return true;
  return comp[x] != comp[y];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  setio("milkvisits");

  cin >> n >> m;
  string t; cin >> t;

  for (int i=0;i<n;i++){
    cows[i] = t[i] == 'H';
  }

  for (int i=0;i<n-1;i++){
    ll a, b; cin >> a >> b;
    farm[--a].push_back(--b);
    farm[b].push_back(a);
  }

  selected = true;
  for (int i=0;i<n;i++){
    if (!cows[i] || visited[i]) continue;
    dfs(i);
    curr_comp++;
  }

  selected = false;
  for (int i=0;i<n;i++){
    if (cows[i] || visited[i]) continue;
    dfs(i);
    curr_comp++;
  }

  for (int i=0;i<m;i++){
    ll a, b; char t;
    cin >> a >> b >> t; --a;--b;
    cout << ishappy(a,b, t == 'H');
  }

  cout << endl;

}
