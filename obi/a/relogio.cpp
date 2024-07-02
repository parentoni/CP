#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll,ll>;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  ll h, m, s, t; cin >> h >> m >> s >> t;

  s += t;

  m += s/60;
  s %= 60;

  h += m/60;
  m %= 60;

  h %= 24;

  cout << h << endl << m << endl << s << endl;

}
