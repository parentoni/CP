#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define print(x) for (auto el: x) cout << el << " "; cout << '\n'

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

ll n, p, k;
ll dp[(ll)1e5+5][(1<<7)];

struct Person {
  ll a;
  ll p[7]; 

  friend bool operator<(const Person &a, const Person &b) {
    return a.a > b.a;
  }
};

Person people[(ll)1e5+5];
/**
 * dp[i][S] - I, best score so far. S: filling this positions
 * transition: {
 *  dp[i][S] = max over all possible masks in I-1 without ending position + value of this position, and I-1 with complete;
 *  dp[i][S] = max(dp[i-1][S/x] + people.value, dp[i-1][S]);
 * }
 * */
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> p >> k; 
  for (int i=0;i<n;i++) cin >> people[i].a;
  for (int i=0;i<n;i++) {
    for (int j=0;j<p;j++) cin >> people[i].p[j];
  }

  sort(people, people + (ll)1e5+5);

  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;

  for (int i=1;i<=n;i++) {
    for (int s=0;s<(1 << p);s++) {
      ll c = i-1- __builtin_popcount(s);

      if (c < k) {
        if (dp[i-1][s] != -1) {
          dp[i][s] = dp[i-1][s] + people[i-1].a;
        }
      } else {
        if (dp[i-1][s] != -1) {
          dp[i][s] = dp[i-1][s];
        }
      }

      for (int j=0;j<p;j++) {
        if (!(s & (1 << j)) || dp[i-1][s ^ (1 << j)] == -1) continue;
        dp[i][s] = max(dp[i-1][s ^ (1 << j)] + people[i-1].p[j], dp[i][s]);
      }

    }
  }

  //for (int i=1;i<=n;i++) {
  //  cout << i << "(" << people[i-1].a << "): ";
  //  for (int j=0;j<(1 << p);j++) {
  //    cout << dp[i][j] << " ";
  //  }
  //  cout << endl;
  //}

  cout << dp[n][(1 << p)-1] << "\n";
}
