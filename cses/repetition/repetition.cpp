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

  string s;
  cin >> s;

  int r = 0;
  char c = s[0];
  int cs = 0; 
  for (auto el: s) {
    if (c == el) cs++;
    else {
      cs = 1;
      c = el;
    }
    r = max(r,cs);
  }

  cout << r << endl;
}

