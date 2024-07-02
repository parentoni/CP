#include <bits/stdc++.h>
using namespace std;

#define ll long long;
#define ar array;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<string> s;
  string q = "";

  for (int i=0;i<4;i++){
    string p;
    cin >> p;
    q += p;
  }

  for (int r=0;r<3;r++){
    for (int c=0;c<3;c++){
      string t = "";
      t += q.substr(r * 4 + c, 2);
      t += q.substr((r + 1) * 4 + c,2);
      s.push_back(t);
    }
  }

  for (auto el: s) {
    int b = 0;
    for (auto c: el) {
      if (c == '#') {
        b++;
      }
    }

    if (b == 3 || b == 4 || b == 1 || b == 0) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
