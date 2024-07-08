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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll ans = 0, n; cin >> n;
  vl val(n); for (auto &el: val) cin >> el;

  ll a = 0, b = n-1; // 2pointers;
  ll curr_sum_a = val[a], curr_sum_b = val[b];

  while (a < b) {
    if (curr_sum_a == curr_sum_b) {
      a++; b--;
      curr_sum_a = val[a]; curr_sum_b = val[b];
    } else if (curr_sum_a > curr_sum_b) {
      b--; ans++;
      curr_sum_b += val[b];
    } else {
      a++; ans++;
      curr_sum_a += val[a];
    }

  }
  cout << ans << endl;
}
