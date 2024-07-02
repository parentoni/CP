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
  //setIO("shell");
  int n;
  cin >> n;
  vector<pair<int,int>> v;
  int mx = 0, my =0;
  for (int i=0;i<n;i++){
    pair<int, int> c;
    cin >> c.first >> c.second;
    if (abs(c.first) > mx) mx = abs(c.first);
    if (abs(c.second) > my) my = abs(c.second);
    v.push_back(c);
  }


}

