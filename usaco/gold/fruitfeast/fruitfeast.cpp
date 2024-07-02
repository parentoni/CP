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

ll t,a,b;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("feast");

  cin >> t >> a >> b;
  vector<vector<bool>> dp(t+1,vector<bool>(2, false));

  dp[0][0] = true;

  for (int m=0;m<2;m++) {
    for (int i=0;i<=t;i++) {
      if (i + a <= t) dp[i+a][m] = dp[i+a][m] || dp[i][m];
      if (i + b <= t) dp[i+b][m] = dp[i+b][m] || dp[i][m];
      dp[i/2][1] = dp[i/2][1] || dp[i][0];
    }
  }

  //for (int i=0;i<=t;i++) cout << dp[i][1] << " ";
  //cout << endl;

  ll r = 0;
  for (int i=t;i>=0;i--) {
    //cout << i << " " << dp[i][0] << " " << dp[i][1] << endl;

    if (dp[i][0] || dp[i][1]) {
      r = i; break;
    }
  }
  cout << r << endl;
}
