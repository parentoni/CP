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
const int MAX_N = 52;

ll n,m;
bool maze[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
bool good[MAX_N][MAX_N];
bool bad[MAX_N][MAX_N];
ll c_good = 0, c_bad = 0;
ll pa_good = 0, pa_bad = 0;

bool trap_b(ll x, ll y) {
  if (!bad[x][y]) return true;
  if (good[x-1][y] ||good[x+1][y] || good[x][y-1] || good[x][y+1]) return false; 

  if (!bad[x-1][y]) maze[x-1][y] = 1;
  if (!bad[x+1][y]) maze[x+1][y] = 1;
  if (!bad[x][y-1]) maze[x][y-1] = 1;
  if (!bad[x][y+1]) maze[x][y+1] = 1;

  return true;
}

void flood(ll x, ll y) {
  if (x < 1 || y < 1 || x > n || y > m) return;
  if (visited[x][y] || maze[x][y]) return;
  visited[x][y] = true;

  //cout << x << " " << y << " " << maze[x][y]<< endl;
  if (bad[x][y]) pa_bad++;
  if (good[x][y]) pa_good++;

  flood(x+1, y);
  flood(x-1, y);
  flood(x, y+1);
  flood(x, y-1);
}
void solve(){
  for (auto &r: maze) fill(r, r+ MAX_N, 0);
  for (auto &r: visited) fill(r, r+ MAX_N, 0);
  for (auto &r: good) fill(r, r+ MAX_N, 0);
  for (auto &r: bad) fill(r, r+ MAX_N, 0);
  c_good = c_bad = 0;
  pa_good = 0; pa_bad = 0;

  cin >> n >> m;
  for (int r=1;r<=n;r++) {
    string l; cin >> l;
    for (int c=1;c<=m;c++){
      if (l[c-1] == 'G') {good[r][c] = 1;c_good++;}
      if (l[c-1] == 'B') {bad[r][c] = 1;c_bad++;}
      maze[r][c] = l[c-1] == '#'? 1:0;
    }
  }

  for (int r=1;r<=n;r++){
    for (int c=1;c<=m;c++){
      if (!trap_b(r,c)) {
        no();
        return;
      }
    }
  }

  flood(n,m);
  if (pa_good == c_good && pa_bad == 0) yes();
  else no();

}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setio("");

  int t; cin >> t;
  while(t--){
    solve();
  }
}
