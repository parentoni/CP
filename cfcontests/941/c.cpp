#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll INF = 1e18;
const ll MOD = 1000000007;

void solve() {

  ll smallest = INF, turn = 0;
  int n;
  cin >> n;

  vl values, diff(n+1);

  for (int i=0;i<n;i++){
    ll t;
    cin >> t;
    smallest = min(t,smallest);
    values.push_back(t);
  }

  sort(all(values));
  ll diff_int = 0;
  for (int i=1;i<n;i++){
  }
  
  for (auto el: diff) cout << el << " ";
  cout << endl;

  if (turn % 2 == 0) cout << "Bob" << endl;
  else cout << "Alice" << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while(t--){
    solve();
  }
}
