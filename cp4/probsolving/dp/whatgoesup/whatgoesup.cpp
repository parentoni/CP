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

/**
 * Create a basic LIS dp array.
 * Store for each N, the prev element that created largest sequence.
 * To achieve this, store a vector with the current indexes in dp sequence.
 * */

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


  vl val; ll t; while (cin >> t) val.push_back(t);
  vl dp, p(val.size(), -1), ind;

  dp.push_back(val[0]); ind.push_back(0); p[0] = 0;

  ll ma_ind = 0;
  for (int i=1;i<val.size();i++) {
    ll pos = lower_bound(all(dp), val[i]) - dp.begin();

    if (pos == dp.size()) {
      dp.push_back(val[i]);
      ind.push_back(i);

      ma_ind = i;
    } else {
      dp[pos] = val[i];
      ind[pos] = i;
      if (pos == dp.size()-1) ma_ind = i; 
    }

    p[i] = pos == 0? i: ind[pos-1];
  }


  vl ans; ans.push_back(val[ma_ind]);
  while (p[ma_ind] != ma_ind) {
    ma_ind = p[ma_ind];
    ans.push_back(val[ma_ind]);
  }

  reverse(all(ans));
  cout << dp.size() << "\n-\n";
  for (auto el: ans) cout << el << "\n";
}
