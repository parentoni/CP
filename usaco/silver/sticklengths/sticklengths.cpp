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

ll n, y =0;
vector<ll> sticks;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");


  cin >> n;
  sticks.resize(n);

  for (auto &el: sticks) cin >> el;
  sort(all(sticks));

  ll new_l = sticks[n/2];
  for (auto el: sticks){
    y += abs(el - new_l);
  }
  
  cout << y << endl;

}
