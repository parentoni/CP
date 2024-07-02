#include <bits/stdc++.h>
using namespace std;

#define ll long long;
#define ar array;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;

  int l = 0;
  int u = 0;

  for (auto e: s) {
    if (e < 97) {
      u++;
    } else {
      l++;
    }
  }

  if (l > u || l == u) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
  } else {
    transform(s.begin(), s.end(), s.begin(), ::toupper);
  }

  cout << s << endl;
  return 0;
}
