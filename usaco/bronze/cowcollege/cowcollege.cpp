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

unsigned ll n, tuition, local_max = 0,  y=0;
vector<ll> cows;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  cows.resize(n);
  for (auto &el: cows) cin >> el;
  sort(all(cows));

  for (int i=0;i<n;i++) {
    if (cows[i] * (n-i) > local_max) {
      local_max = cows[i] * (n-i);
      tuition = cows[i];
    }
  }

  cout << local_max << " " << tuition << endl;
}

