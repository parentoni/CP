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

void solve() {
  ll n; cin >> n;
  vl values; vl sorted;

  for (int i=0;i<n;i++){
    ll t; cin >> t;
    values.push_back(t); sorted.push_back(t);
  }

  sort(all(sorted));

  bool already = true;
  for (int i=0;i<n;i++){
    if (sorted[i] != values[i]) already = false;
  }

  if (already) {
    yes(); return;
  }

  ll p = 1;
  while(p < n) {
    if (values[p] < values[p-1]) {
      if (values[0] < values.back()) {
        no(); return;
      } else {
        for (int i=0;i<p;i++){
          values.push_back(values[i]);
        }

        for (int i=0;i<p;i++){
          values.erase(values.begin());
        }
        p = 1;
      }
    } else {
      p++;
    }
  }

  yes();

}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setio("");

  ll t; cin >> t;
  while(t--) {
    solve();
  }
}

