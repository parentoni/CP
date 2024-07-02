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

  setIO("pails");
  //freopen("pails.in", "r", stdin);
  int x,y,m;
  cin >> x >> y >> m;

  int s = 0;

  while (m >= x || m >= y) {
    if (m % x > m % y) {
      m -= y;
      s += y;
    } else {
      m -= x;
      s += x;
    }

  }

  cout << s << endl;
}
