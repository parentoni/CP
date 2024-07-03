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
const ll MAX_N = 4000;
ll h, w;

ll dx[4] = {1,-1,0,0};
ll dy[4] = {0,0,1,-1};

string board[4000];
ll depth[4000][4000];


deque<pll> q;

bool inside(ll x, ll y) {
  return (x >= 0 && x < h && y >=0 && y < w && board[x][y] != '.');
}
ll bfs() {

  ll ans = 1;
  depth[0][0] = 1;

  q.push_back({0,0});
  while(q.size()) {

    pll a = q.front();
    q.pop_front();
    ans = max(ans, depth[a.first][a.second]);
    for (int i=0;i<4;i++) {
      ll x = a.first + dx[i], y = a.second +dy[i];
      if (!depth[x][y] && inside(x, y)) {
        if (board[a.first][a.second] != board[x][y]) {
          q.push_back({x,y});
          depth[x][y] = depth[a.first][a.second] + 1;
        } else {
          q.push_front({x,y});
          depth[x][y] = depth[a.first][a.second];
        }
      }
    }
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> h >> w; 
 

  for (int i=0;i<h;i++) {
    cin >> board[i];
  }

  cout << bfs() << "\n";
}
