#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using llb = long double;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// geometry
const double PI = 3.14159265358979323846;
double DEG_to_RAD (double d) {return d*PI/180.0;}
double RAD_to_DEG (double r) {return r*180.0/ PI;}

// values
const ll INF = 1e18;
const ll MOD = 1000000007;
const ll MAX_N = 1120;
const ll MAX_K = 14;

ll dp[MAX_N + 1][MAX_K + 1] = {0};
bitset<1121> isprime;
vl primes;

void erastothenes(ll m) {
  isprime[0] = isprime[1] = 1;
  for (int i=2;i<=m;i++) {
    if (isprime[i]) continue;
    primes.push_back(i);
    if (i > sqrt(m)) continue;
    for (int j=i+i;j<=m;j+=i) {
      isprime[j] = 1;
    }
  }
}

void solve() {

  //for (int k=0;k<=MAX_K;k++) dp[0][k] = 1;

  dp[0][0] = 1;

  for (int p=0;p<primes.size();p++) {

    for (int k=MAX_K;k>=1;k--) {
      for (int n=MAX_N;n>=p;n--) {
        if (n - primes[p] >= 0) {
          dp[n][k] += dp[n-primes[p]][k-1];
        }
      }
    }

    //cout << "p: " << primes[p] << endl;
    //for (int i=0;i<=5;i++) {
    //  for (int j=0;j<=100;j++) {
    //    cout << dp[j][i] << " ";
    //  }
    //  cout << endl;
    //}
    //cout << endl;
  }

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  erastothenes(1120);
  solve();

  ll n, k;


  while(cin >> n >> k) {
    if (n == 0 && k == 0) break;
    cout << dp[n][k] << endl;

  }


}

