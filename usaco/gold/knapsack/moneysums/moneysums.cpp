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
const ll MAX_N = 100 * 1000;

ll n;
vl weights;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n; weights.resize(n); 
  for (auto &el: weights) cin >> el;

  vector<vector<bool>> dp(n + 1, vector<bool>(MAX_N + 1, 0)); 

  dp[0][0] = 1;
  for (int w=1;w<=n;w++) {
    for (int x=0;x<=MAX_N;x++) {
      if (x - weights[w-1] >= 0) dp[w][x] = dp[w][x] || dp[w-1][x-weights[w-1]]; 
      dp[w][x] = dp[w][x] || dp[w-1][x];
    }
  }


  set<ll> ans;
  for (int i=1;i<=MAX_N;i++) {
    if (dp[n][i]) ans.insert(i);
  }
  cout << ans.size() << endl;
  for (auto el: ans) cout << el << " ";
  cout << endl;
}
