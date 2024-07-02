#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pii = pair<int,int>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll INF = 1e18;
const ll MOD = 1000000007;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, t, y=0;
  cin >> n >> t;

  ll books[n];
  for (auto &el: books) cin >> el;

  ll r=0, l =0, sum = 0;
  for (;r<n;r++){
    sum += books[r];
    if (sum <= t) y = max(y, r-l+1);
    while(l < n && sum > t){
      sum -= books[l];
      l++;
    }
  }

  cout << y << endl;
}
