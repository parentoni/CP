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
const ll MAX_N = 5000;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  string n, m; cin >> n >> m;
  vector<vl> dp(n.size() + 1, vl(m.size() + 1, 0));

  for (int i=1;i<=m.size();i++) dp[0][i] = dp[0][i-1]+1;
  for (int i=1;i<=n.size();i++) dp[i][0] = dp[i-1][0]+1;

  for (int i=1;i<=n.size();i++) {
    for (int j=1;j<=m.size();j++){
      ll subs = 0;

      subs += n[i-1] != m[j-1];
      dp[i][j] = min({dp[i][j-1]+1, dp[i-1][j]+1, dp[i-1][j-1]+subs});
      
    }
  }

  //for (int i=0;i<=n.size();i++) {
  //  for (int j=0;j<=m.size();j++) cout << dp[i][j] << " ";
  //  cout << endl;
  //}

  cout << dp[n.size()][m.size()] << endl;

  
}
