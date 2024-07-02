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

  setIO("gymnastics");
  //freopen("gymnastics.in", "r", stdin);
  int n, k;
  cin >> k >> n;

  vector<vector<int>> t;
  for (int i=0;i<k;i++){
    vector<int> it(n);
    for (auto &el: it) cin >> el;
    t.push_back(it);
  }
  vector<vector<pair<int,int>>> p;
  map<pair<int,int>, int> m;
  for (int r=0;r<k;r++) {
    vector<pair<int,int>> tp;
    for (int i=0;i<n;i++){
      for (int j=i;j<n;j++) {
        if (i == j) continue;
        m[make_pair(t[r][i], t[r][j])]++;
      }
    }
  }

  int r = 0;

  for (auto el: m) {
    if (el.second == k) r++;
  }

  cout << r << endl;
}

