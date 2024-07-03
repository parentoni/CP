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
const ll MAX_N = 1000;

ll dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
map<int, char> i_to_dir = {{0, 'U'},{1, 'D'},{2, 'L'},{3, 'R'}}; 
map<char, int> dir_to_i = {{'U', 0},{'D', 1},{'L', 2},{'R', 3}}; 

ll n, m;
pll a;
char board[MAX_N+2][MAX_N+2];
ll mdepth[MAX_N+2][MAX_N+2];
ll adepth[MAX_N+2][MAX_N+2];
char came[MAX_N+2][MAX_N+2];

bool inside(ll x, ll y) {
  return (x > 0 && x <= n && y > 0 && y <= m && board[x][y] != '#');
}

void ans(ll x, ll y) {
  yes();
  vector<char> seq;

  pll c = {x, y};
  while((c.first != a.first || c.second != a.second)) {
    //cout << c.first << " " << c.second << " " << came[c.first][c.second]  << endl;
    char d = came[c.first][c.second];
    c = {c.first - dx[dir_to_i[d]], c.second- dy[dir_to_i[d]]};
    seq.push_back(d);
  }

  reverse(all(seq));

  cout << seq.size() << "\n";
  for (auto el: seq) cout << el;
  cout << "\n";
}
queue<pll> q;
void bfs(bool mode) {



  while(q.size()) {
    
    pll c = q.front();
    q.pop();

    for (int i=0;i<4;i++) {

      ll x = c.first + dx[i], y = c.second + dy[i];
      if (!inside(x, y)) continue;

      if (mode == 0 && mdepth[x][y] == -1) {
        mdepth[x][y] = mdepth[c.first][c.second] + 1;
        came[x][y] = i_to_dir[i];
        q.push({x, y});
      } else if (mode == 1 && adepth[x][y] == -1) {
        adepth[x][y] = adepth[c.first][c.second] + 1;
        q.push({x, y});
        came[x][y] = i_to_dir[i];
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  memset(mdepth, -1, sizeof(mdepth));
  memset(adepth, -1, sizeof(adepth));

  for (int i=1;i<=n;i++) {
    string t; cin >> t; 
    for (int j=1;j<=m;j++) {
      board[i][j] = t[j-1];

      if (t[j-1] == 'A') {
        a = {i, j};
      }
      if (t[j-1] == 'M') {
        q.push({i,j});
        mdepth[i][j] = 0;
      }
    }
  }


  bfs(0);

  q.push(a);

  adepth[a.first][a.second] = 0;
  bfs(1);

  for (int i=1;i<=m;i++) {
    if (adepth[1][i] < mdepth[1][i] || (adepth[1][i] != -1 && mdepth[1][i] == -1) ) {

      ans(1,i);
      return 0;
    }
    if (adepth[n][i] < mdepth[n][i] || (adepth[n][i] != -1 && mdepth[n][i] == -1)) {
      ans(n,i);
      return 0;
    }
  }

  for (int i=1;i<=n;i++) {
    if (adepth[i][1] < mdepth[i][1] || (adepth[i][1] != -1 && mdepth[i][1] == -1)) {
      ans(i,1);
      return 0;
    }

    if (adepth[i][m] < mdepth[i][m] || (adepth[i][m] != -1 && mdepth[i][m] == -1)) {

      ans(i,m);
      return 0;
    }
  }
  no();
}
