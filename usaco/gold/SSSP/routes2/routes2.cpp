#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define jrint(x) for (auto el: x) cout << el << " "; cout << '\n'
#define f first
#define s second

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
const ll MAX_N = 500;

ll paths[MAX_N][MAX_N];

ll m, n, q;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q;

  for (int i=0;i<MAX_N;i++) {
    for (int j=0;j<MAX_N;j++) paths[i][j] = INF;
  }

  for (int i=0;i<m;i++) {
    ll a, b, c; cin >> a >> b >> c; --a;--b;
    paths[a][b] = min(paths[a][b], c);
    paths[b][a] = min(paths[a][b], c);
  }

  for (int i=0;i<n;i++) paths[i][i] = 0;

  for (int k=0;k<n;k++) {
    for (int i=0;i<n;i++) {
      for (int j=0;j<n;j++) {
        paths[i][j] = min(paths[i][j], paths[i][k] + paths[k][j]);
      }
    }
  }

  for (int i=0;i<q;i++) {
    ll a, b; cin >> a >> b; a--;b--;
    cout << (paths[a][b] == INF?-1: paths[a][b]) << endl;
  }
}
