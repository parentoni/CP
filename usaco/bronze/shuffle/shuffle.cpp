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
  setIO("shuffle");
  //freopen("shuffle.in", "r", stdin);
  
  int n;
  cin >> n;
  vector<int> v;
  vector<int> s;
  for (int i=0;i<n;i++) {
    int q;
    cin >> q;
    v.push_back(q);
  }

  for (int i=0;i<n;i++) {
    int q;
    cin >> q;
    s.push_back(q);
  }

  
  for (int i=0;i<3;i++){
    vector<int> c;
    for (int j=0;j<n;j++) {
      c.push_back(s[v[j] - 1]);
    }
    s = c;
  }

  for (auto el: s) {
    cout << el << endl;
  }
}
