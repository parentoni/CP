#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using vl = vector<long long>;

const ll inf = 1e18;
ll n;
vl a;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> n; a.resize(n);
  for (auto &el: a) cin >> el;

  vl d(n+1, inf);
  d[0] = -inf;

  ll r = 0;
  for (int i=0;i<n;i++){
    ll l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
    if (d[l-1] < a[i] && a[i] < d[l]) {
      d[l] = a[i];
      if (l > r ) {
        r = l;
      }
    }
  }
  for (auto el: d) cout << el << " ";
  cout << endl;
  cout << r << endl;
}
