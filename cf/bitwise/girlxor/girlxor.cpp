#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using ull = unsigned long long;
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


ull l, r, c = 0; 

bool ison(ull i, ull p) {
  return (i & (1llu << p));
}

ull offmask(ull i) {
  ull a = 0;
  for (int j=63;j>=0;j--) {
    if (j == i) continue;
    a |= (1llu << j);
  }

  return a;
}

void solve() {
  for (int i=63;i>=0;i--) {
    if (ison(l, i) && ison(r,i)) {
      if ((r & offmask(i)) >= l) {
        c |= (1llu << i);
      }
    } else if (!ison(l, i) && !ison(r,i)) {
      if ((l | (1llu << i)) <= r) {
        c |= (1llu << i);
      }
    } else {
      c |= (1llu << i);
    }
  }
  
  cout << c << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> l >> r;

  solve();
}
