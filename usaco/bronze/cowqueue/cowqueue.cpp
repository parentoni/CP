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

ll n, y=0;
vector<pair<ll,ll>> cow;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("cowqueue");

  cin >> n;
  cow.resize(n);

  for (auto &el: cow) cin >> el.first >> el.second;
  sort(all(cow));
  
  for (int i=0;i<n;i++) {
    
    if (y < cow[i].first) {
      y += cow[i].first - y + cow[i].second;
    } else {
      y += cow[i].second;
    }
  }

  cout << y << endl;
}

