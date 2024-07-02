#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setio(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"yes\n"; }
void no() { cout<<"no\n"; }

// values
const ll inf = 1e18;
const ll mod = 1000000007;
const double eps = 1e-7;
ll n;
vector<pll> friends;

bool possible(long double x) {

  pair<long double, long double> bound = {-1e10, 1e10};
  for (auto el: friends) {
    bound.first = max(el.first - el.second * x, bound.first);
    bound.second = min(el.first + el.second * x, bound.second);
  }

  return bound.first <= bound.second;
}

double first_possible(double lo, double hi, function<bool(ll)> f) {


  double ans = -1;
  while(hi - lo > eps) {
    double long med = lo + (hi - lo) /2;
    if (possible(med)) {
      ans = med;
      hi = med;
    } else {
      lo = med;
    }
  }

  return ans;

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setio("");

  cin >> n; friends.resize(n);
  for (int i=0;i<n;i++) cin >> friends[i].first;
  for (int i=0;i<n;i++) cin >> friends[i].second;

  sort(all(friends));

  cout << fixed << first_possible(0, friends.back().first, possible) << endl;
}
