
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

ll n, k, b, y = INF;
vl broken_sum;
map<ll,bool> broken;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setIO("maxcross");

  cin >> n >> k >> b;
  broken_sum.resize(n+1);

  for (int i=0;i<b;i++) {
    int t;
    cin >> t;
    broken[t] = true;
  }

  for (int i=1;i<=n;i++){
    broken_sum[i] = broken_sum[i-1];
    if (broken[i]) broken_sum[i]++;
  }

  for (int i=1;i<=n-k+1;i++){
    y = min(y, broken_sum[i+k-1] - broken_sum[i-1]);
  }

  cout << y << endl;

}
