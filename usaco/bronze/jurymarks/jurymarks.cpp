#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define all(x) (x).begin(), (x).end()

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll INF = 1e18;
const ll mod = 1000000007;

ll n, k, y=0;

vector<ll> jury;
vector<ll> polycarp;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> k >> n;

  jury.resize(k);
  polycarp.resize(n);

  for (auto el: jury) cin >> el;
  for (auto el: polycarp) cin >> polycarp;

  solve(0);

  cout << y << endl;
}
