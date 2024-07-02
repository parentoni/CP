#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

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



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vl a, b;
  ll n; cin >> n; a.resize(n); b.resize(n);

  for (auto &el: a) cin >> el;
  for (auto &el: b) cin >> el;

  vl da, db;

  for (int i=0;i<n;i++) {
    ll pa = lower_bound(da.begin(), da.end(), a[i]) - da.begin();
    ll pb = lower_bound(db.begin(), db.end(), b[i]) - db.begin();

    if (pa == da.size()) {
      da.push_back(a[i]);
    } else {
      da[pa] = a[i];
    }

    if (pb == db.size()) {
      db.push_back(b[i]);
    } else {
      db[pb] = b[i];
    }
  }

  ll ans = 0;

  if (da.size() > db.size()) {
    for (auto el: da) {
      ll p = lower_bound(db.begin(), db.end(), el) - db.begin();
      if (db[p] == el) ans++;
    }
  } else {
    for (auto el: db) {
      ll p = lower_bound(da.begin(), da.end(), el) - da.begin();
      if (da[p] == el) ans++;
    }
  }
  cout << ans << endl;
}
