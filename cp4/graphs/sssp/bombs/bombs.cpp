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
ll dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
ll r, c;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(cin >> r >> c) {
    if (r + c == 0) break;
    vector<vector<bool>> board(r, vector<bool>(c, 0)); // 1 if bomb
    vector<vector<int>> distance(r, vector<int>(c, -1));

    ll bombs; cin >> bombs;
    pair<int,int> a, b;
    for (int i=0;i<bombs;i++) {
      ll rown, amount; cin >> rown >> amount;
      for (int j=0;j<amount;j++) {
        ll y; cin >> y; board[rown][y] = 1;
      }
    }

    cin >> a.first >> a.second >> b.first >> b.second;

    distance[a.first][a.second] = 0;
    queue<pair<int,int>> q; q.push(a);

    while (q.size()) {
      pair<int,int> curr = q.front();
      q.pop();

      if (curr == b) {
        cout << distance[b.first][b.second] << endl;
        break;
      }

      for (int i=0;i<4;i++) {
        int x = curr.first + dx[i], y = curr.second + dy[i];
        if (x < 0 || x >= r || y < 0 || y >= c) continue;
        if (board[x][y]) continue;
        if (distance[x][y] == -1) {
          distance[x][y] = distance[curr.first][curr.second] + 1;
          q.push({x, y});
        }
      }
    }



  }
}
