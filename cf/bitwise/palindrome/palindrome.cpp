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


ll n;
map<int, ll> state;
set<int> seen;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  cin >> n;
  ll ans = 0;
  for (int i=0;i<n;i++) {
    string s; int t = 0; cin >> s;

    for (auto el: s) {
      t ^= (1 << (el - 'a'));
    }
    ans += state[t];

    for (int i=0;i<26;i++) {
      t ^= (1 << i);

      ans += state[t];

      t ^= (1 << i);
    }

    state[t]++;

  }
  cout << ans << endl;

}
