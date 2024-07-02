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

  ll n, k; vl r; cin >> n >> k;
  r.resize(n); 

  for (auto &el: r) cin >> el;

  map<ll, vl> d;

  for (int i=0;i<n;i++) {
    ll div = r[i] % k;
    d[div].push_back(r[i]);
  }

  ll ans = 0; bool odd = true;

  for (auto el: d) {
    sort(all(el.second));
    if (el.second.size() % 2 == 1) {

      if (odd == false) {
        cout << -1 << endl;
        return ;
      }

      odd = false;
      ll m = INF;

      for (int i=0;i<el.second.size();i++) {
        ll c = 0;
        for (int j=0;j<i;j+=2) {
          c += abs(el.second[j+1] - el.second[j]) / k;
        }

        for (int j=i+1;j<el.second.size();j+=2) {
          c += abs(el.second[j+1] - el.second[j]) / k;
        }

        //cout << c << " " << i<< endl;
        m = min(m, c);
      }

      ans += m;

    } else {
      for (int i=0;i<el.second.size();i+=2) {
        if (i == el.second.size()-1) {
          cout << -1 << endl;
          return ;
        } else {
          ans += abs(el.second[i+1] - el.second[i]) / k;
        }
      }
    }

  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  ll t; cin >> t; while(t--) solve();
}
