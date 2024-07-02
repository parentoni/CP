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
  setIO("mixmilk");
  vector<pair<int, int>> p;
  for (int i=0;i<3;i++) {
    int c, q;
    cin >> c >> q;
    pair<int, int> b;
    b.first = c;
    b.second = q;
    p.push_back(b);
  }

  for (int i=0;i<100;i++){
    int n =(i + 1) % 3;

    int am = min(p[i%3].second, p[n].first - p[n].second);
    p[n].second += am;
    p[i%3].second -= am;
  }

  cout << p[0].second << endl << p[1].second << endl << p[2].second << endl;
}
