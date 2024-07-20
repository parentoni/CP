#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(x) (x).begin(), (x).end()
#define print(x) for (auto el: x) cout << el << " "; cout << '\n'
#define f first
#define s second

using ll = long long;
using llb = long double;
using vl = vector<ll>;
using pll = pair<ll,ll>;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
const ll MAXN = 1e5;

ll n, ans[MAXN+1];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("haircut");

  cin >> n;
  Tree<pair<ll, ll>> a;
  

  for (int i=0;i<n;i++) {
    ll t; cin >> t;
    ans[t] += (i - a.order_of_key({t, MOD}));
    a.insert({t,i});
  }

  ll tot = 0;
  for (int i=0;i<n;i++) {
    cout << tot << endl; 
    tot += ans[i];
  }

}
