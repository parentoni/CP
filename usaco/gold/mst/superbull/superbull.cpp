#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define print(x) for (auto el: x) cout << el << " "; cout << '\n'
#define f first
#define s second

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
const ll MAXN = 2000;

ll n,d[MAXN];
bool visited[MAXN];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("superbull");

  cin >> n; vl val(n); for(auto &el: val) cin >> el;
  

  ll ans = 0;
  for (int i=0;i<n;i++) {

    ll node = -1;
    for (int j=0;j<n;j++) {
      if (visited[j]) continue;
      if (node == -1 || d[j] > d[node]) node = j;
    }

    ans += d[node];
    visited[node] = true;
    //cout << node << " " << d[node] << endl;

    for (int j=0;j<n;j++) {

      //cout << node << " " << j << " " << (val[node] ^ val[j]) << endl;
      d[j] = max(d[j], (val[node] ^ val[j]));
    }
  }

  cout << ans << endl;

}
