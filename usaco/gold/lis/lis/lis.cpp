#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = int;
using vl = vector<int>;
const ll inf = 1e9;

vl seq;
ll n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> n; seq.resize(n);
  for (auto &el: seq) cin >> el;
  
  vl d(n+1, inf), p(n+1, -1);
  d[0] = -inf;

  ll r = 0, pos = 0;
  for (int i=0;i<n;i++) {
    ll l = upper_bound(d.begin(), d.end(), seq[i]) - d.begin();
    if (d[l-1] < seq[i] && seq[i] < d[l]) {
      d[l] = seq[i];
      p[i] = l;
      if (l > r) {
        pos = i;
      }
    }
  }

  cout << r << endl;
}
