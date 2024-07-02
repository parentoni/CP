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
const ll MAX_N = 500;

ll dx[4] = {1,-1,0,0}; 
ll dy[4] = {0, 0, 1,-1}; 

ll n, m, stat_c = 0, curr_c = 0, max_allowed;
ll elevations[MAX_N][MAX_N];
bool stations[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

void dfs(ll x, ll y) {
  if (x < 0 || x >= n || y < 0 || y >= m) return;
  if (visited[x][y]) return;
  visited[x][y] = true;
  if (stations[x][y]) curr_c++;

  for (int i=0;i<4;i++){
    if (abs(elevations[x][y] - elevations[x + dx[i]][y+dy[i]]) <= max_allowed) {
      dfs(x + dx[i], y + dy[i]);
    }
  }
}

bool possible(ll x) {
  for (auto &row: visited) fill(row, row + MAX_N, 0);
  max_allowed = x;

  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++){
      if (visited[i][j]) continue;
      curr_c = 0; dfs(i,j);
      if (curr_c == stat_c) return true;
    }
  }
  return false;

}

ll first_true(ll lo, ll hi, function<bool(ll)> f) {
  ll ans = -1;
  while( lo <= hi) {
    ll med = lo + (hi - lo) /2;
    if (f(med)) {
      ans = med;
      hi = med -1;
    } else {
      lo = med + 1;
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setio("ccski");

  cin >> n >> m;

  for (int r=0;r<n;r++){
    for (int c=0;c<m;c++){
       ll t; cin >> t;
       elevations[r][c] = t;
    }
  }

  for (int r=0;r<n;r++){
    for (int c=0;c<m;c++){
      bool t; cin >> t;
      if (t) stat_c++;
      stations[r][c]=t;
    }
  }

  cout << first_true(0, 1e17, possible) << endl;
}
