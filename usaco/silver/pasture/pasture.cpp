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

ll twoton(int n){
  ll r = 1;
  for (int i=1;i<=n;i++){
    r = r*2;
  }
  return r;
}
ll n, m;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

}