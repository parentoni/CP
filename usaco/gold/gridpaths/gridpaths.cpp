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
ll dp[MAX_N][MAX_N];
bool ready[MAX_N][MAX_N];

ll solve(ll r, ll c) {
  if (ready[r][c]) return dp[r][c];
  if (r < 0 || c < 0) return 0;
  if (!board[r][c]) return 0;
  if (r == 0 && c == 0) return 1;

  ll s = (solve(r-1, c) % mod + solve(r, c-1) % mod) % mod;
  dp[r][c] = s;
  ready[r][c] = true;
  return s;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  cin >> n;
  for (int r=0;r<n;r++) {
    string t; cin >> t;
    for (int c=0;c<n;c++) board[r][c] = t[c] == '.';
  }

  cout << solve(n-1,n-1) << endl;
}
