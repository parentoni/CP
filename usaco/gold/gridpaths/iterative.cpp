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
const ll mod = 1000000007;
const ll MAX_N = 1001;
ll n;

bool board[MAX_N][MAX_N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  cin >> n;
  vector<vl> dp(n, vl(n, 0));
  for (int r=0;r<n;r++){
    string t; cin >> t;
    for (int c=0;c<n;c++) board[r][c] = t[c] == '.';
  }

  dp[0][0] = board[0][0];
  for (int r=0;r<n;r++) {
    for (int c=0;c<n;c++) {
      if (board[r+1][c]) {dp[r+1][c] += dp[r][c];dp[r+1][c] = dp[r+1][c] % mod;}
      if (board[r][c+1]) {dp[r][c+1] += dp[r][c]; dp[r][c+1] = dp[r][c+1] % mod;}
    }
  }

  cout << dp[n-1][n-1] << endl;

  
}
