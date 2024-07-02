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
const ll MAX_N = 1e5;


ll n, cost[MAX_N];
vl values;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n; values.resize(n);
  for (auto &el: values) cin >> el;

  fill(cost, cost + n, inf);
  cost[0] = 0;

  for(int i=1; i<n;i++) {
    
    cost[i] = min(cost[i], cost[i - 1] + abs(values[i - 1] - values[i]));
    if (i - 2 >= 0) {
      cost[i] = min(cost[i], cost[i - 2] + abs(value[i - 2] - value[i]));
    }
  }
  
  cout << cost[n-1] << endl;

}
