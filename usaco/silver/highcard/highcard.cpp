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

ll n, y = 0;

vl elsie;
bool elsie_cards[100000 + 1];

set<ll> bessie;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("highcard");

  cin >> n;
  for (int i=0;i<n;i++) {
    int t;
    cin >> t;
    elsie_cards[t] = true;
    elsie.push_back(t);
  }

  for (int i=1;i<=n*2;i++){
    if (!elsie_cards[i]) bessie.insert(i);
  }

  for (int i=0;i<n;i++){
    auto it = bessie.upper_bound(elsie[i]);
    if (it == bessie.end()) bessie.erase(bessie.begin());
    else {
      y++;
      bessie.erase(it);
    }
  }
  cout << y << endl;
}
