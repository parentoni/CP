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

ll dx[4] = {1,-1,0,0};
ll dy[4] = {0,0,1,-1};

void solve() {

  ll n, m; cin >> n >> m;
  vector<vl> matrix(n+2, vl(m+2));

  for (int r=1;r<=n;r++) {
    for (int c=1;c<=m;c++) cin >> matrix[r][c];
  }

  for (int r=1;r<=n;r++) {
    for (int c=1;c<=m;c++) {

      ll great = 0;
      for (int i=0;i<4;i++) {
        great = max(great, matrix[r + dy[i]][c+dx[i]]);
      }

      if (matrix[r][c] > great) matrix[r][c] = great;
    }
  }

  for (int r=1;r<=n;r++) {
    for (int c=1;c<=m;c++) {
      cout << matrix[r][c] << " ";
    }
    cout << endl;
  }
}



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll t; cin >> t; while(t--) solve();
}
