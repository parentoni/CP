#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  ll a,b,c; cin >> a >> b >> c;

  ll s = a + b * 2 + c * 3;
  if (s >= 150) cout << "B" << endl;
  else if (s >= 120) cout << "D" << endl;
  else if (s>=100) cout << "P" << endl;
  else cout << "N" << endl;
}
