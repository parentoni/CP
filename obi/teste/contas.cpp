#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  ll n, r=0; vl contas(3);
  cin >> n; for (auto &el: contas) cin >> el;

  sort(contas.begin(), contas.end());

  for (int i=0;i<3;i++) {
    if (contas[i] > n) continue;
    r++; n -= contas[i];
  }

  cout << r << endl;
}

