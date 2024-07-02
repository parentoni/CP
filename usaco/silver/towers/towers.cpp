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

ll n;
multiset<ll> towers;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  cin >> n;

  ll initial;
  cin >> initial;
  towers.insert(-initial);

  for (int i=1;i<n;i++){
    ll block;
    cin >> block;
    block *= -1;

    auto it = towers.lower_bound(block);
    if (it != towers.begin()) it--;

    if (*it < block) {
      towers.erase(it);
      towers.insert(block);
    } else {
      towers.insert(block);
    }
  }

  cout << towers.size() << endl;

}

