#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define print(x) for (auto el: x) cout << el << " "; cout << '\n'

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
const ll MAX_N = 1000;

bool possible[2001];
ll na, nb, ma, mb, statea[MAX_N+1], stateb[MAX_N+1];
vl adja[MAX_N+1], adjb[MAX_N+1];
vl topa, topb;

void dfsa(ll x) {
  if (statea[x] != 0) return;
  statea[x] = 1;
  for (auto u: adja[x]){
    dfsa(u);
  }
  topa.push_back(x);
  statea[x] = 2;
}

void dfsb(ll x) {
  if (stateb[x] != 0) return;
  stateb[x] = 1;
  for (auto u: adjb[x]){
    dfsb(u);
  }
  topb.push_back(x);
  stateb[x] = 2;
}

set<ll> dpa[MAX_N+1], dpb[MAX_N+1];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> na >> nb >> ma >> mb;
  for (int i=0;i<ma;i++) {
    ll a, b; cin >> a >> b; adja[a].push_back(b);
  }

  for (int i=0;i<mb;i++) {
    ll a, b; cin >> a >> b; adjb[a].push_back(b);
  }

  dfsa(1);
  dfsb(1);
  reverse(all(topa));
  reverse(all(topb));

  dpa[1] = {0};
  dpb[1] = {0};
  for (int i=0;i<topa.size();i++) {
    for (auto u: adja[topa[i]]){
      for (auto el: dpa[topa[i]]) {
        dpa[u].insert(el+1);
      }
    }
  }

  for (int i=0;i<topb.size();i++) {
    for (auto u: adjb[topb[i]]){
      for (auto el: dpb[topb[i]]) {
        dpb[u].insert(el+1);
      }
    }
  }

  for (auto a: dpa[na]) {
    for (auto b: dpb[nb]) {
      possible[a+b] = true;
    }
  }
  
  ll q; cin >> q;
  for (int i=0;i<q;i++) {
    ll t; cin >> t;
    cout << (possible[t]? "Yes": "No") << endl;
  }
}
