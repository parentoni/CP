#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <cmath>

using namespace std;

using ll = long long;
using pii = pair<int,int>;

ll const MAX_N=1000;

ll n, m;
vector<pii> farm_at_t, bess_at_t;
string fa, be;

map<char, ll> dx = {{'E', 1}, {'W', -1}, {'N',0}, {'S',0}};
map<char, ll> dy = {{'E', 0}, {'W', 0}, {'N',1}, {'S',-1}};

ll pow_distance(pii a, pii b) {
  if (a.first < 0 || a.second < 0) return 1e16; 
  if (b.first < 0 || b.second < 0) return 1e16;
  return abs(a.first - b.first) * abs(a.first - b.first) + abs(a.second - b.second) * abs(a.second - b.second);
}

int main() {
      ios::sync_with_stdio(0);
      cin.tie(NULL);

      freopen("radio.in", "r", stdin);

      cin >> n >> m; farm_at_t.resize(n+1); bess_at_t.resize(m+1);

      cin >> farm_at_t[0].first >> farm_at_t[0].second;
      cin >> bess_at_t[0].first >> bess_at_t[0].second;
      cin >> fa >> be;

      vector<vector<ll>> dp(n+1, vector<ll>(m+1, 1e18));

      for (int i=1;i<=n;i++) {
      farm_at_t[i] = {farm_at_t[i-1].first + dx[fa[i-1]], farm_at_t[i-1].second + dy[fa[i-1]]};
      }

      for (int i=1;i<=m;i++) {
      bess_at_t[i] = {bess_at_t[i-1].first + dx[be[i-1]], bess_at_t[i-1].second + dy[be[i-1]]};
      }


      dp[0][0] = 0;
      for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {

          dp[i+1][j] = min(dp[i+1][j], dp[i][j] + pow_distance(farm_at_t[i+1], bess_at_t[j]));
          dp[i][j+1] = min(dp[i][j+1], dp[i][j] + pow_distance(farm_at_t[i], bess_at_t[j+1]));
          dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + pow_distance(farm_at_t[i+1], bess_at_t[j+1]));

        }
      }
    
      freopen("radio.out", "w", stdout);
      cout << dp[n][m] << endl;
}
