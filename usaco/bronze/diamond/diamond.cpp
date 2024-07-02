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

  setIO("diamond");
  //freopen("diamond.in", "r", stdin);
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (auto &el: a) cin >> el;
  sort(a.begin(), a.end());

  int r = 0;
  for (int i=0;i<n;i++) {
    for (int j=i;j<n;j++) {
      if (a[j] - a[i] <= k) r = max(r, j-i+1);
    }
  }

  cout << r << endl;
}

