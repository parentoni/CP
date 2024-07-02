
#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll INF = 1e18;
const ll MOD = 1000000007;

int n;
bitset<16> b;
void solve(int i)  {
  if (i == pow(2,n)) return;
  cout << b << endl;
  b = b.to_ulong() + 1;
  solve(i + 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  solve(0);
}
