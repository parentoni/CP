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

ll n, x;
vl weights;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> x;weights.resize(n);
  for (auto &el: weights) cin >> el;

  vector<vector<bool>> dp(x + 1, vector<bool>(n+1, 0));

  dp[0][0] = 1;
  for (int i=0;i<=x;i++) {
    for (int w=1;w<=n;w++) {
      if (i - weights[w-1] >= 0) dp[i][w] = dp[i][w] || dp[i-weights[w-1]][w-1];
      dp[i][w] = dp[i][w] || dp[i][w-1];
    }
  }

  vl res;
  for (int i=0;i<=x;i++) if (dp[i][n]) res.push_back(i);

  cout << res.size() << endl;
  for (auto &el: res) cout << el << " ";
  cout << endl;


  for (int w=0;w<=n;w++) {
    for (int i=0;i<=x;i++)  cout << dp[i][w] << " ";
    cout << endl;
  }
}
