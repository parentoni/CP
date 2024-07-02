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
ll i = 0;

string line;
void solve() {
  stringstream ss(line);
  ll n; ss >> n;
  vl values(n); for (auto &el: values) ss >> el;

  if (n == 0) return;
  if (i>0)cout << endl;

  for (int a=0;a<n;a++) {
    for (int b=a+1;b<n;b++) {
      for (int c=b+1;c<n;c++) {
        for (int d=c+1;d<n;d++) {
          for (int e=d+1;e<n;e++) {
            for (int f=e+1;f<n;f++) {
            cout << values[a] << " " << values[b] << " " << values[c] << " " << values[d] << " " << values[e] << " " << values[f] << endl;
            }
          }
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(getline(cin, line)){
    solve();
    i++;
  }
}
