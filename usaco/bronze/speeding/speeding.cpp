#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("speeding");
  //freopen("speeding.in", "r", stdin);
  int n, m;
  cin >> n >> m;
  int r[100];
  int c[100];

  int tr = 0;
  for (int i=0;i<n;i++) {
    pair<int, int> s;
    cin >> s.first >> s.second;
    for (int j=0;j<s.first;j++){
      r[j + tr] = s.second;
    }
    tr += s.first;
  }

  int tc =0;
  for (int i=0;i<m;i++) {
    pair<int, int> s;
    cin >> s.first >> s.second;
    for (int j=0;j<s.first;j++){
      c[j + tc] = s.second;
    }
    tc += s.first;
  }

  int s =0;
  for (int i=0;i<100;i++){
    s = max(s, c[i] - r[i]);
  }

  cout << s << endl;
}
