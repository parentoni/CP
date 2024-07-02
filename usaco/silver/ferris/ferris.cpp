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

// values
const ll inf = 1e18;
const ll MOD = 1000000007;

int n, k, y = 0;
multiset<ll> children;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  cin >> n >> k;
  for (int i=0;i<n;i++) {
    int t;
    cin >> t;
    children.insert(t);
  }

  while (!children.empty()){
    auto a = children.begin();
    auto b = children.upper_bound(k - *a);

    if (b!=children.begin()) --b;
    if (b == a){
      y++;
      children.erase(a);
    } else {
      if (*b <= k-*a){
        y++;
        children.erase(a);
        children.erase(b);
      } else {
        y++;
        children.erase(a);
      }
    }
  }

  cout << y << endl;
}
