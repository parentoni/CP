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

// geometry
double DEG_to_RAD (double d) {return d*M_PI/180.0;}
double RAD_to_DEG (double r) {return r*180.0/ M_PI;}

// values
const ll INF = 1e18;
const ll MOD = 1000000007;
const double EPS = 1e-9;

string s;

void int_to_bit(ll b) {
  for (int i=log2(b);i>=0;i--) {
    if (b & (1 << i)) cout<<1;
    else cout << 0;
  }
  cout << endl;

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


  int curr = 0;
  map<int,ll> states;
  states[curr]++;

  cin >> s;
  for (const char digit: s) {
    curr ^= 1 << (digit - '0');
    //int_to_bit(curr);
    states[curr]++;
  }

  ll ans = 0;
  for (auto el: states) {ans += (el.second * (el.second-1))/2;}
  cout << ans << endl;

}
