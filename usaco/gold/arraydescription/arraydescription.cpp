#include <vector>
#include <iostream>

using namespace std;

using ll = long long;
using vl = vector<long>;

const ll mod = 1e9 + 7;
ll n, m;

vl values;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  
  cin >> n >> m; values.resize(n);
  for (auto &el: values) cin >> el;

  vector<vl> dp(n+1, vl(m+1, 0));

  
  if (values[0] == 0) {
    for (int i=0;i<=m;i++) dp[0][i] = 1;
  } else {
    dp[0][values[0]] = 1;
  }

  for (int x=1;x<n;x++) {
      if (values[x] == 0) {

        for (int i=1;i<=m;i++) {
          if (i + 1 <= m) dp[x][i] += dp[x-1][i+1];
          if (i - 1 > 0) dp[x][i] += dp[x-1][i-1];
          dp[x][i] += dp[x-1][i];
          dp[x][i] %= mod;
        }

      } else {

          if (values[x] + 1 <= m) dp[x][values[x]] += dp[x-1][values[x]+1];
          if (values[x] - 1 > 0) dp[x][values[x]] += dp[x-1][values[x]-1];
          dp[x][values[x]] += dp[x-1][values[x]];
          dp[x][values[x]] %= mod;
      }
    }

  ll r = 0;
  for (int i=1;i<=m;i++) {
    r += dp[n-1][i];
    r %= mod;
  }
  cout << r << endl;
}
