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

  int n, b,c,d;
  cin >> n >> b >> c >> d;

  set<int> a;
  a.insert(b);
  a.insert(c);
  a.insert(d);

  int r = 0;
  for (auto el: a) {
    if (el < n) {
      int t = n / el;
      n -= t * el;
      r += t;
    }
  }
  cout << r << endl;

}

