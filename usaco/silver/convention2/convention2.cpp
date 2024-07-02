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

ll n, current_time=0, y = 0;
multiset<pair<ll, pll>> cows;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("convention2");

  cin >> n;
  for (int i=1;i<=n;i++){
    ll a, b; cin >> a >> b;
    cows.insert({i, {a, b}});
  }


  //for (auto el: cows) cout << el.first << " " << el.second.second << ": " << el.second.first<< endl;
  while(!cows.empty()){
    
  }



}
