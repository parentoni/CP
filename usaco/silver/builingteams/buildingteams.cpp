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
const ll MAX_N = 10e5;
ll n, m;
vl friendships[2*MAX_N];
int teams[MAX_N];
bool visited[MAX_N];
bool valid = true;
void dfs(ll initial){
  if (visited[initial]) return;
  visited[initial] = true;

  for (auto u: friendships[initial]) {
    if (teams[initial] == teams[u]){valid = false;}
    if (teams[u] == 0) teams[u] = teams[initial] == 1? 2: 1;
    dfs(u);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  cin >> n >> m;
  for (int i=0;i<m;i++){
    ll a,b;
    cin >> a >> b;
    friendships[a-1].push_back(b-1); friendships[b-1].push_back(a-1);
  }

  teams[0] = 1;
  for (int i=0;i<n;i++){
    if (teams[i] == 0) teams[i] = 1;
    dfs(i);
  }

  if (!valid) cout << "IMPOSSIBLE" << endl;
  else {
    for (int i=0;i<n;i++) cout << teams[i] << " ";
    cout << endl;
  }
}
