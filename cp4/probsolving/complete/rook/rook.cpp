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

// geometry
double DEG_to_RAD (double d) {return d*M_PI/180.0;}
double RAD_to_DEG (double r) {return r*180.0/ M_PI;}

// values
const ll INF = 1e18;
const ll MOD = 1000000007;
const double EPS = 1e-9;

ll n, rc = 0, ans = 0;
bool board[4][4];
bool rook[4][4];

bool possible_rook(ll r, ll c) {

  if (rook[r][c] || !board[r][c]) return false;
  for (int i=c+1;i<n;i++) {
    if (!board[r][i]) break;
    if (rook[r][i]) return false;
  }

  for (int i=c-1;i>=0;i--) {
    if (!board[r][i]) break;
    if (rook[r][i]) return false;
  }

  for (int i=r+1;i<n;i++) {
    if (!board[i][c]) break;
    if (rook[i][c]) return false;
  }

  for (int i=r-1;i>=0;i--) {
    if (!board[i][c]) break;
    if (rook[i][c]) return false;
  }

  return true;


}
void back(ll r, ll c) {
  ans = max(ans, rc);
  //cout << r << " " << c << " " << n << " " << rc << " "  << endl;
  for (int i=r;i<n;i++) {
    for (int j=0;j<n;j++) {
      if (!possible_rook(i,j)) continue;
      rook[i][j] = true;
      rc++;
      back(i,j);
      rc--;
      rook[i][j] = false;
    }
  }

}
void solve() {
  ans = 0; rc=0;
  for (int i=0;i<n;i++) {
    string l; cin >> l;
    for (int j=0;j<n;j++) board[i][j] = l[j] == '.';
  }

  back(0,0);
  //rook[0][0] = true;
  //rook[0][2] = true;
  //cout << possible_rook(1, 1) << endl;
  cout << ans << endl;

}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  while (cin >> n) {
    if (n == 0) break;
    solve();
  }
}
