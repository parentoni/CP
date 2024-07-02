#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setio(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"yes\n"; }
void no() { cout<<"no\n"; }

// values
const ll inf = 1e18;
const ll mod = 1000000007;

ll n;
vl songs;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setio("");

  cin >> n;
  songs.resize(n);

  for (auto &el: songs) cin >> el;

  ll right = 0, left = 0, best = 0;
  map<ll,bool> seen;
  while (right < n && left < n){
    if (!seen[songs[right]]){
      seen[songs[right]] = true;
      best = max(best, right - left + 1);
      right++;
    } else {
      seen[songs[left]] = false;
      left++;
    }
  }
  cout << best << endl;
}
