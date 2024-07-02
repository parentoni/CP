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


ll n, m, w_c = 0;
vector<pll> wormhole[MAX_N]; // p.first -> edge, p.second -> size of wormhole
vl cows;
bool wrong[MAX_N];
bool visited[MAX_N];


ll test_w = 0, curr_c;
map<ll, vl> components;

void dfs(ll x) {
  if (visited[x]) return;
  visited[x] = true;
  components[curr_c].push_back(x);

  for (auto u: wormhole[x]) {
    if (u.second >= test_w) dfs(u.first);
  }
}

bool possible(ll x) {

  test_w = x;
  components = {};
  fill(visited, visited + MAX_N, 0);

  for (int i=0;i<n;i++){
    curr_c = i;
    if (!visited[i]) dfs(i);
  }
  
  for (auto el: components) {
    ll f_count = 0;
    for (auto comp: el.second) {
      if (wrong[comp]) f_count++;
    }

    if (f_count == w_c) return true;

  }

  return false;
}

ll last_true(ll lo, ll hi, function<bool(ll)> f) {
  ll ans = -1;
  while(lo <= hi) {
    ll med = lo + (hi - lo) /2;
    if (f(med)) {
      ans = med;
      lo = med + 1;
    } else {
      hi = med - 1;
    }
  }

  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  setio("wormsort");

  cin >> n >> m;
  cows.resize(n); for (auto &el: cows) cin >> el;

  ll max_w = 0;
  for (int i=0;i<m;i++){
    ll a,b,w; cin >> a >> b >> w;
    max_w = max(max_w, w);
    a--;b--;
    wormhole[a].push_back({b,w});
    wormhole[b].push_back({a,w});
  }

  for (int i=0;i<n;i++){
    if (cows[i] != i+1) {
      wrong[i] = true; w_c++;
    }
  }

  if (w_c == 0) {
    cout << -1 << endl; return 0;
  }

  cout << last_true(0, max_w, possible) << endl;

}
