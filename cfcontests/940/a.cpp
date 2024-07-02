#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define all(x) (x).begin(), (x).end()

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll INF = 1e18;

void solve(){
  ll n, y = 0;
  cin >> n;
  map<int,int> sticks;
  for (int i=0;i<n;i++) {
    int t;
    cin >> t;
    sticks[t]++;
  }

  for (auto el: sticks) {
    y += el.second/3;
  }
  cout << y << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}
