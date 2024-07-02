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
const ll inf = 1e18;
const ll MOD = 1000000007;

ll n, mi = inf, ma = 0;
bool cows[10e5];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("herding");

  cin >> n;
  for (int i=0;i<n;i++){
    int p;
    cin >> p;
    cows[p]=1;
  }

}
