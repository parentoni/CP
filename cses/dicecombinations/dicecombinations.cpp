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
const ll MAX_N = 1e7;

ll coin[MAX_N + 1];
bool ready[MAX_N + 1];
ll dice[6] = {1,2,3,4,5,6};

ll solve(ll n) {
  if (ready[n]) return coin[n];

  for (auto el: dice) {
    if (n - el >= 0) {
      coin[n] += solve(n - el);
      coin[n] %= mod;
    }
  }

  ready[n] = true;
  return coin[n];
}
int main() {
  coin[0] = 1; ready[0] = true;
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;

  cin >> n;
  cout << solve(n) << endl;

}
