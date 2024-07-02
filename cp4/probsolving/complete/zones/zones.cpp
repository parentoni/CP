#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll,ll>;
using pii = pair<int,int>;

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

ll n, k, case_n = 0, ans = 0, ansi = 0;
vl towers; 
//map<int, int> common;
vector<pii> common;

bool ison(int i, int p) {
  return (i & (1<<p));
}
void check(int i) {
  int t=0;

  for (int j=0;j<n;j++) if (ison(i, j)) t+=towers[j];

  for (auto el: common) {
    //cout << (i & el.first) << " " << i << " " << el.first << " " << __builtin_popcount(i& el.first) << endl;
    if (__builtin_popcount(i & el.first) >=2) {
      int found =  __builtin_popcount(i & el.first );
      if (found % 2 == 0) {
        t -= el.second; 
      } else {
        t += el.second;
      }
    }
  }
  

  //cout << i << " " << t << endl;
  //cout << endl;
  if (t > ans) {
    ans = t; ansi = i;
  } else if (t == ans && t > 0) {
    for (int j=0;j<n;j++) {
      if (ison(ansi, j) && !ison(i, j)) break;
      if (!ison(ansi, j) && ison(i,j)) {
        ansi = i; break;
      }
    }
  }
}

void solve() {

  case_n++; ansi = 0; ans = 0;
  towers.resize(n); for (auto &el: towers) cin >> el;
  common.clear();

  int ca; cin >> ca;

  // set common map
  for (int i=0;i<ca;i++) {
    int c; cin >> c;
    int ind = 0;
    for (int j=0;j<c;j++) {
      int t; cin >> t;
      ind |= (1<<(t-1));
    }

    int amount; cin >> amount; 
    common.push_back({ind, amount});
    //common[ind] = amount;
  }
  //for (auto el: common) cout << el.first << " " << el.second << endl;

  for (int i=(1<<k)-1;i<(1<<n);i++){
    if (__builtin_popcount(i) == k) {
      check(i);
    }
  }

  //cout << ans << " " << ansi << endl;
  cout << "Case Number  " << case_n << endl;
  cout << "Number of Customers: " << ans << endl;
  cout << "Locations recommended:";
  for (int j=0;j<log2(ansi)+1;j++) if (ison(ansi, j)) cout << " " << j+1;
  cout << endl;
  cout << endl;

}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  while (cin >> n >> k) {
    if (n == 0 && k == 0) break;
    solve();
  }
  
  return 0;
}
