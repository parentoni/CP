#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define infi INT_MAX

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setIO("mowing");
  //freopen("mowing.in", "r", stdin);
  int n;
  cin >> n;

  int r = infi;
  int t = 0;
  map<string, int> b;
  pair<int, int> pos(0, 0);
  for (int i=0;i<n;i++) {
    char d;
    int s;
    cin >> d >> s;

    for (int j=0;j<s;j++) {
      if (d == 'N') pos.second--;
      if (d == 'S') pos.second++;
      if (d == 'E') pos.first++;
      if (d == 'W') pos.first--;
      if (b.count(to_string(pos.first) + "-" + to_string(pos.second)) != 0) r = min(r, t + j - b[to_string(pos.first) + "-" + to_string(pos.second)]);
      b[to_string(pos.first) + "-" + to_string(pos.second)] = t + j;

    }
    t += s;
  }


  if (r != infi) cout <<r << endl;
  else cout << -1 << endl;
}
