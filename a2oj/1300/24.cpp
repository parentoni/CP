#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string g, n, l;
  cin >> g >> n >> l;

  sort(l.begin(), l.end());
  string r = g + n;

  sort (r.begin(), r.end());

  if (r == l) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

