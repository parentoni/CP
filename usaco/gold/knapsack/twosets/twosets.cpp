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

ll n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  if ((n * (n + 1) / 2) % 2 == 1) {
    cout << 0 << endl;
    return 0;
  }

  ll size = n * (n+1)/4;
  vector<vl> dp(size+1, vl(n,0));

  dp[0][0] = 1;
  for (int w=1;w<n;w++) {
    for (int x=0;x<=size;x++) {
      if (x - w >= 0) dp[x][w] += dp[x-w][w-1];
      dp[x][w] += dp[x][w-1];
      dp[x][w] = dp[x][w] % mod;
    }
  }

  cout << dp[size][n-1] << endl;
}
