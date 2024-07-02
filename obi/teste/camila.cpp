#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  vl a(3); for (auto &el: a) cin >> el;
  sort(a.begin(), a.end());

  cout << a[1] << endl;
}
