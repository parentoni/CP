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
  setIO("blist");
  //freopen("blist.in", "r", stdin);

  int n;
  cin >> n;

  vector<vector<int>> c;
  for (int i=0;i<n;i++){
    vector<int> v;
    int s, t ,b;
    cin >> s >> t >> b;
    v.push_back(s);
    v.push_back(t);
    v.push_back(b);
    c.push_back(v);
  }

  int m = 0;
  for (int i=0;i<1000;i++){
    int s = 0;
    for (auto el: c) {
      if (i >= el[0] && i <= el[1]) {
        s += el[2];
      }
    }

    m = max(m, s);


  }

  cout << m << endl;
}

