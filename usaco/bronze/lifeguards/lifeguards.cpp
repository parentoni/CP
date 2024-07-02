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

  setIO("lifeguards");
  //freopen("lifeguards.in", "r", stdin);
  int n;
  cin >> n;

  int s[1000] = {0};
  int coverage = 0;
  vector<pair<int,int>> l(n);
  for (auto &el: l) cin >> el.first >> el.second;

  for (auto el: l) {
    for (int i=el.first+1;i<=el.second;i++) {
      if (s[i] == 0) coverage++;
      s[i]++;
    }
  }

  int r = 0;
  for (int i=0;i<n;i++){
    int ccoverage = coverage;
    for (int j=l[i].first+1;j<=l[i].second;j++){
      if (s[j] - 1 == 0) ccoverage--;
    }

    r = max(r,ccoverage);
  }

  cout << r << endl;
  
}
