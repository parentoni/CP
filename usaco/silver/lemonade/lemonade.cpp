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

ll n, y=0;
vl cows;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("lemonade");

  cin >> n;
  cows.resize(n);

  for (auto &el: cows) cin >> el;
  sort(cows.rbegin(), cows.rend());

  for (int i=0;i<n;i++){
    if (cows[i] >= i) y++;
    else break;
  }

  cout << y << endl;


}
