#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define print(x) for (auto el: x) cout << el << " "; cout << '\n'
#define f first
#define s second

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

void solve() {
  ll n, m, k; cin >> n >> m >> k;
  vl d(n+1, INF); string river; cin >> river;

  deque<pll> q;

  for (int i=0;i<m;i++) {
    if (i > n) continue;
    if (river[i] == 'C') continue;
    d[i] = 0;
    q.push_front({i, 0});
  }

  while(q.size()) {
    pll a = q.front(); q.pop_front();

    if (d[a.f] != a.s) continue;
    if (a.f == n) {
      if (d[a.f] <= k) yes();
      else no();
      return;
    }

    if (river[a.f] == 'L') {
      for (int i=m;i>=1;i--) {
        if (a.f + i > n) continue;
        if (river[i+a.f] == 'C') continue;
        if (d[a.f+i] < d[a.f]) continue;

        d[a.f+i] = d[a.f];
        q.push_front({a.f+i, d[a.f]});
        if (river[i+a.f] == 'L') break;
      }
    } else {
      if (river[a.f+1] == 'C') continue;
      if (d[a.f+1] < d[a.f]+1) continue;
      d[a.f+1] = d[a.f]+1;
      q.push_back({a.f+1, d[a.f+1]});
    }
  }

  no();
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  ll t; cin >> t; while(t--) solve();
}
