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

  //setIO("");
  //freopen("", "r", stdin);
  ll r =0;
  int n;
  cin >> n;
  vector<ll> v(n);
  for (auto &el: v) cin >> el;

  for (int i=0;i<n-1;i++) {
    if (v[i+1] < v[i]) {
      r += v[i] - v[i+1];
      v[i+1] = v[i];
    }
  }

  cout << r << endl;
}

