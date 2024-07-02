#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

// functions

void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

ll n;
vector<ll> y;

bool check() {
  for (int i=0;i<n-1;i++) {
    if (abs(y[i] - y[i+1]) == 1) return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //setIO("");
  //freopen("", "r", stdin);
  cin >> n;
  y.resize(n);

  for (int i=1;i<=n/2;i++){
    y[i-1] = i*2;
  }

  for (int i=1;i<=n - n/2;i++){
    y[i-1 + n/2] = i*2-1;
  }

  if (!check()) cout << "NO SOLUTION" << endl;
  else {
    for (auto el: y) cout << el << " ";
    cout << endl;
  }

}
