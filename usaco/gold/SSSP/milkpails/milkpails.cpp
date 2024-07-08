#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define print(x) for (auto el: x) cout << el << " "; cout << '\n'

using ll = long long;
using llb = long double;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// geometry
const double PI = 3.14159265358979323846;
double DEG_to_RAD (double d) {return d*PI/180.0;}
double RAD_to_DEG (double r) {return r*180.0/ PI;}

// values
const ll INF = 1e18;
const ll MOD = 1000000007;
const ll MAX_N = 100;

ll x, y, k, m;
ll dist[MAX_N+1][MAX_N+1];

pll ops(pll a, ll mode, ll pos) {
  if (mode == 0) {
    if (pos == 0) return {x, a.second};
    return {a.first, y};
  } else if (mode == 1) {
    if (pos == 0) return {0, a.second};
    return {a.first, 0};
  } else {
    if (pos == 0) {
      ll pour = min(a.first, y - a.second);
      return {a.first - pour, a.second + pour};
    } else {
      ll pour = min(a.second, x - a.first);
      return {a.first + pour, a.second - pour};
    }

  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("pails");

  cin >> x >> y >> k >> m;

  memset(dist, -1, sizeof(dist));
  dist[0][0] = 0;
  queue<pll> q; q.push({0,0}); // initial state;
  while(q.size()) {
    pll a = q.front();
    q.pop();


    for (int i=0;i<3;i++) {
      for (int j=0;j<2;j++) {
        pll r = ops(a, i, j);
        if (dist[r.first][r.second] != -1) continue;
        dist[r.first][r.second] = dist[a.first][a.second] + 1;
        q.push(r);
      }
    }
  }


  ll ans = INF;
  for (int i=0;i<=x;i++) {
    for (int j=0;j<=y;j++) {
      if (dist[i][j] == -1 || dist[i][j] > k) continue;
      ans = min(ans, abs(m - i - j));
    }
  }
  cout << ans << endl;
}
