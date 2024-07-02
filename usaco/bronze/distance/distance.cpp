#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

// functions
//void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll m = 0;
  int n;
  cin >> n;

  vector<ll> x;
  vector<ll> y;
  for (int i=0;i<n;i++){
    ll a;
    cin >> a;
    x.push_back(a);
  }

  for (int i=0;i<n;i++){
    ll a;
    cin >> a;
    y.push_back(a);
  }

  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      ll d = pow(x[j] - x[i], 2) + pow(y[j] - y[i], 2);
      m = max(m, d);
    }
  }

  cout << m << endl;
}
