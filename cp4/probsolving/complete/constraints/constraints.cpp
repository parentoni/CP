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

// geometry
double DEG_to_RAD (double d) {return d*M_PI/180.0;}
double RAD_to_DEG (double r) {return r*180.0/ M_PI;}

// values
const ll INF = 1e18;
const ll MOD = 1000000007;
const double EPS = 1e-9;

ll n, m, ans = 0;
vl teen;
map<ll, vector<pair<ll, ll>>> rules;



void check() {
  for (int i=0;i<n;i++) {


    for (auto el: rules[teen[i]]) {
      ll dist = -1;

      for (int j=0;j<n;j++) {
        if (j == i) continue;
        if (teen[j] == el.first) {
          dist = abs(i-j);
        }
      }

      if (el.second > 0 && dist <= el.second) {
      } else if (el.second < 0 && dist >= -el.second) {
      } else {
        return;
      }

    }
    
  }

  ans++;

}
void solve() {
  ans = 0;
  if (n == 0) return;
  teen.resize(n); rules.clear();

  for (int i=0;i<n;i++) teen[i] = i;
  for (int i=0;i<m;i++) {
    ll a, t, d; cin >> a >> t >> d;
    rules[a].push_back({t,d});
  }

  do {
    check();
  } while (next_permutation(all(teen)));

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  while(cin >> n >> m) {
    solve();
  }
}
