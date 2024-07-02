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


ll n; vector<string> a;
bool compare(ll i, ll j) {
  ll si = a[i].size(), sj = a[j].size();
  if (a[i] == a[j]) return true;
  if (si > sj) return false;

  for (int c=0;c<sj-si+1;c++) {
    string y;
    for (int d=0;d<si;d++) y += a[j][c+d];

    if (y == a[i]) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  cin >> n; a.resize(n);
  for (auto &el: a) cin >> el;

  ll ans = 0;
  for (int i=0;i<n;i++) {
    for (int j=i+1;j<n;j++) {
      ans += compare(i, j);
      ans += compare(j, i);
    }
  }

  cout << ans << endl;
}
