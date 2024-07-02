#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setio(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"yes\n"; }
void no() { cout<<"no\n"; }

// values
const ll inf = 1e18;
const ll mod = 1000000007;
const ll MAX_N = 1000;

struct Cow {
  int x,y;
};


ll distance (Cow a, Cow b) {
  return abs(a.x - b.x) * abs(a.x - b.x) +  abs(a.y - b.y) * abs(a.y - b.y);
}

ll n, global_max = 0;
vector<Cow> cows;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setio("moocast");
  
  cin >> n;
  cows.resize(n);

  for (auto &el: cows) cin >> el.x >> el.y;

  for (int i=0;i<n;i++){
    ll local_min = inf;
    for (int j=0;j<n;j++){
      if (i == j) continue;
      local_min = min(local_min, distance(cows[i], cows[j]));
    }

    if (local_min != inf) global_max = max(global_max, local_min);
  }

  cout << global_max << endl;
}
