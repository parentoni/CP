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



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vl a;
  ll n; cin >> n; a.resize(n); 
  for (auto &el: a) cin >> el;

  map<ll, ll> m;

  vl dp;
  dp.push_back(a[0]);
  m[a[0]] = 1;

  ll ma = 1; ll in = 0;
  for (int i=1;i<n;i++) {

    m[a[i]] = m[a[i]-1]+1;

    //if (m[a[i]-1].first + 1 > ma) {
    // m[a[i]] = {m[a[i]-1].first+1, i+1};
    //} else {
    //  if (m[a[i]].second == 0) {
    //    m[a[i]].second = i+1;
    //  }
    //  m[a[i]] = {m[a[i]-1].first+1, m[a[i]].second};
    //}

    if (m[a[i]] > ma) {
      ma = m[a[i]]; in = i;
    }


  }

  vl v;
  for (int i=0;i<=in;i++) {
    if (a[i] == a[in] - ma + 1 + v.size()) v.push_back(i);
  }

  cout << ma << endl;

  for (auto el: v) cout << el+1 << " ";
  cout << endl;
}
