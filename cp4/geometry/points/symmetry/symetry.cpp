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

struct point {
  double x, y;
  point() {x=y=0;}
  bool operator < (const point &other) const {
    if (x != other.x) return x < other.x;
    return y < other.y;
  }

};
ll n; 

void solve() {
  cin >> n;
  set<point> a;
  ll mx= INF, mmx = -INF;
  for (int i=0;i<n;i++) {
    point p; cin >> p.x >> p.y;
    mx = min(mx, (ll)p.x); mmx = max(mmx, (ll)p.x);
    a.insert(p);
  }

  double pos = ((mmx - mx) / 2.0) + mx;
  bool valid = true;

  for (auto el: a) {
    if (valid == false) break;
    if (el.x == pos) continue;

    point target; target.y = el.y; target.x = pos;
    target.x += pos - el.x;

    auto r = a.find(target);
    if (r == a.end()) valid = false;

  }
  //for (int j=0;j<n;j++) {
    //point cmp = *(next(a.begin(), j));
      
    //if (cmp.x == pivot.x) continue;

    //point target; target.y = cmp.y;
    //target.x = pivot.x;

    //if (pivot.x > cmp.x) target.x += abs(cmp.x - pivot.x);
    //else target.x -= abs(cmp.x - pivot.x);

    //auto re = a.find(target);
    //if (re == a.end()) {
    //  //cout << i << " " << j << " " << target.x << " " << target.y << endl;
    //  valid = false; break;
    //}

  //}

  //}
  
  valid? yes(): no();

}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll t;
  cin >> t;
  while(t--) solve();



}

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

struct point {
  double x, y;
  point() {x=y=0;}
  bool operator < (const point &other) const {
    if (x != other.x) return x < other.x;
    return y < other.y;
  }

};
ll n; 

void solve() {
  cin >> n;
  set<point> a;
  ll mx= INF, mmx = -INF;
  for (int i=0;i<n;i++) {
    point p; cin >> p.x >> p.y;
    mx = min(mx, (ll)p.x); mmx = max(mmx, (ll)p.x);
    a.insert(p);
  }

  double pos = ((mmx - mx) / 2.0) + mx;
  bool valid = true;

  for (auto el: a) {
    if (valid == false) break;
    if (el.x == pos) continue;

    point target; target.y = el.y; target.x = pos;
    target.x += pos - el.x;

    auto r = a.find(target);
    if (r == a.end()) valid = false;

  }
  //for (int j=0;j<n;j++) {
    //point cmp = *(next(a.begin(), j));
      
    //if (cmp.x == pivot.x) continue;

    //point target; target.y = cmp.y;
    //target.x = pivot.x;

    //if (pivot.x > cmp.x) target.x += abs(cmp.x - pivot.x);
    //else target.x -= abs(cmp.x - pivot.x);

    //auto re = a.find(target);
    //if (re == a.end()) {
    //  //cout << i << " " << j << " " << target.x << " " << target.y << endl;
    //  valid = false; break;
    //}

  //}

  //}
  
  valid? yes(): no();

}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll t;
  cin >> t;
  while(t--) solve();



}
