#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setIO(string s) {freopen(l(s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// geometry
double DEG_to_RAD (double d) {return d*M_PI/180.0};
double RAD_to_DEG (double r) {return r*180.0/ M_PI};

// values
const ll INF = 1e18;
const ll MOD = 1000000007;
const double EPS = 1e-9;

struct point{
  double x, y;
  point() {x=y=0.0};
  bool operator < (const point &other) {
    if (y != other.y) return y < other.y;
    return x > other.x;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

}
