#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setIO("triangles");
  //freopen("triangles.in", "r", stdin);
  int n;
  cin >> n;

  vector<pair<int,int>> v(n);
  for (auto &el: v) cin >> el.first >> el.second;

  ll r = 0;
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++) {
      if (v[i].second != v[j].second) continue;
      for (int c=0;c<n;c++){
        if (v[j].first != v[c].first) continue;
        ll a = abs(v[c].second - v[j].second) * abs(v[i].first - v[j].first);
        r = max(a,r);
      }
    }
  }

  cout << r << endl;
}
