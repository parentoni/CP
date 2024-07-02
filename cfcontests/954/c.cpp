#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

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


void solve() {
  ll n, m; cin >> n >> m;
  string s; multiset<char> c; cin >> s;
  vl ind; 
  for (int i=0;i<m;i++){
    ll t; cin >> t; t--; ind.push_back(t);
  }

  for (int i=0;i<m;i++) {
    char t; cin >> t; c.insert(t);
  }


  sort(all(ind));

  string ans = s;

  for (int i=0;i<m;i++) {
    if (i != m-1) {
      if (ind[i+1] == ind[i]) {
        ans[ind[i]] = *(prev(c.end()));
        c.erase(prev(c.end()));
      } else {
        ans[ind[i]] = *(c.begin());
        c.erase(c.begin());
      }
    } else {
      ans[ind[i]] = *(c.begin());
      c.erase(c.begin());
    }
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll t; cin >> t; while(t--) solve();
}
