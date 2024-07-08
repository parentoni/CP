#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define print(x) for (auto el: x) cout << el << " "; cout << '\n'

using ll = long long;
using llb = long double;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// geometry
const double PI = 3.14159265358979323846;
double DEG_to_RAD (double d) {return d*PI/180.0;}
double RAD_to_DEG (double r) {return r*180.0/ PI;}

// values
const ll INF = 1e18;
const ll MOD = 1000000007;
ll dx[8] = {2,2,-2,-2, 1, -1, 1, -1}, dy[8] = {1,-1 ,1,-1, 2, 2, -2, -2};
ll dxk[8] = {1,-1,0,0, 1, 1, -1 ,-1}, dyk[8] = {0,0, -1,1, 1, -1, 1, -1};
ll n, m;

void solve() {
  cin >> n >> m;
  pll a, b; // a is king, b is destination
  vector<vl> distz(n, vl(m,-1));
  queue<pll> qz;

  for (int i=0;i<n;i++) {
    string line; cin >> line;
    for (int j=0;j<m;j++) {
      if (line[j] == 'A') a = {i, j};
      if (line[j] == 'B') b = {i, j};
      if (line[j] == 'Z') {
        qz.push({i,j});
        distz[i][j] = 0;
      }
    }
  }

  while (qz.size()) {
    pll curr = qz.front();
    qz.pop();

    for (int i=0;i<8;i++) {
      ll x = curr.first + dx[i], y = curr.second + dy[i];
      if (x < 0 || x >= n || y < 0 || y >= m) continue;
      if (distz[x][y] != -1) continue;
      distz[x][y] = distz[curr.first][curr.second]+1;
      //qz.push({x,y});
    }
  }

  vector<vl> distk(n, vl(m, -1)); distk[a.first][a.second] = 0;
  queue<pll> qk; qk.push(a);

  while(qk.size()) {
    pll curr = qk.front();
    qk.pop();

    for (int i=0;i<8;i++) {
      ll x = curr.first + dxk[i], y = curr.second + dyk[i];
      if (x < 0 || x >= n || y < 0 || y >= m) continue;
      if (x == b.first && y == b.second) {
        cout << "Minimal possible length of a trip is " << distk[curr.first][curr.second]+1 << endl;
        return;
      }

      ll c = distk[curr.first][curr.second]+1;
      if (distk[x][y] != -1) continue;
      if (distz[x][y] != -1) continue;

      distk[x][y] = c;
      qk.push({x,y});
    }
  }

  cout << "King Peter, you can't go now!" << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll t; cin >> t; while(t--) solve();
}
