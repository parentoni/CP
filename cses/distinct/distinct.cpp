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

ll n;
vector<ll> a;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  a.resize(n);

  for (auto &el: a) cin >> el;
  
  sort(all(a));
  a.resize(unique(all(a)) - a.begin());
  cout << a.size() << endl;
}
