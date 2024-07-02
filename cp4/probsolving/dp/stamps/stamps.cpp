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


const ll INF = 1e18;
const ll MOD = 1000000007;
ll s, n;

struct Stamps{

  int s, ans = 0;
  vector<int> items;

  friend bool operator < (const Stamps &a, const Stamps &b) {
    if (a.ans != b.ans) return a.ans < b.ans;
    else if (a.s != b.s) return a.s > b.s;
    else return a.items >= b.items;
  }
};

void solve() {

  cin >> n;
  if (n == 0) {
    cout << "max coverage =   0 :" << endl;
    return;
  }
  vector<Stamps> val;
  for (int i=0;i<n;i++) {
    Stamps a; cin >> a.s; a.items.resize(a.s);
    for (auto &el: a.items) cin >> el;
    val.push_back(a);
  }

  for (auto &el: val) {
    vector<vector<bool>> dp(1005, vector<bool>(s + 1, 0));
    dp[0][0] = true;

    int m = 0;
    for (int i=0;i<=1000;i++) {
      bool found = false;
      for (int j=0;j <=s;j++) {
        found = found || dp[i][j];
        if (j + 1 > s) continue;
        for (auto item: el.items) {
          if (i + item > 1000) continue;
          dp[i + item][j + 1] = dp[i+item][j+1] || dp[i][j];
        }
      }

      if (!found) break;
      m = i;
    }

    el.ans = m;
  }

  sort(all(val));
  printf("max coverage =%4d :", val[n-1].ans);
  for (auto el: val[n-1].items) {
    printf("%3d", el);
  }
  puts("");


  
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> s) {
    if (s == 0) break;
    solve();
  }
}
