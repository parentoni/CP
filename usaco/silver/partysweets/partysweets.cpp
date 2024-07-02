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

// values
const ll inf = 1e18;
const ll MOD = 1000000007;

ll n, m, y =0;
vl boys, girls;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");
  
  cin >> n >> m;
  boys.resize(n); girls.resize(m);

  for (auto &el: boys) cin >> el;
  for (auto &el: girls) cin >> el;

  sort(boys.rbegin(), boys.rend()); sort(girls.rbegin(), girls.rend());

  ll left = 0;

  for (int i=0;i<n;i++){

    bool used_min = false;
    y += left * boys[i];
    if (left > 0) used_min = true;

    for (int j=left;j<m;j++){
      if (boys[i] > girls[j]) {
        cout << -1 << endl;
        return 0;
      }
      if (girls[j] == boys[i]) used_min = true;
      if (!used_min && j == m-1) {y += boys[i];}
      else {
        y+= girls[j];left++;
      }
    }

    //cout << y << " " << left << endl;
  }
  cout << y << endl;
}
