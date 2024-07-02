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
double n, x, t, k;



double memo[1100+1][100+1][20+1];
vector<pair<ll, double>> tast;
ll budg;

double dp(ll x, ll j, ll d) {
  if (x > budg || d > 2*(n+1)) return -999999999;
  if (memo[x][j][d] >= 0) return memo[x][j][d];

  if (j == k || d == 2*(n+1)) return 0.0;

  double r = max(dp(x,j+1,d), dp(x+tast[j].first, j+1, d+1) + tast[j].second);
  r = max(r, dp(x+tast[j].first*2, j+1, d+2) + tast[j].second + tast[j].second);

  memo[x][j][d] = r;

  return memo[x][j][d];
}

void solve() {

  tast.resize(k);

  for (int i=0;i<k;i++) {
    ll a; cin >> a; double b = 0;
    for (int j=0;j<=n;j++) {
      double temp = 0; cin >> temp; b+= temp;
    }

    pair<ll,double> temp; temp.first = a; temp.second = b/(n+1);
    tast[i] = temp; 
  }




  vl clean(n+1,-1); 

  budg = floor(((n+1)*x)/1.1 + 1e-5); 
  if (budg <= 0) {
    cout << "0.00" << endl;
    return ;
  }

  for (int i=0;i<=budg;i++) {
    for (int j=0;j<=k;j++) {
      fill(memo[i][j], memo[i][j] + 201, -1);
    }
  }

  cout << fixed << setprecision(2) << max(dp(t*(n+1), 0, 0),0.0) << endl;
    //for (int j=0;j<=k*2;j++) {
    //  for (int i=0;i<=size;i++) {
    //    memo[i][j].print_avg(); cout << " ";
    //  }
    //  cout << endl;
    //}

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(cin >> n >> x >> t >> k) {
    if (n == 0 && x == 0 && t == 0 && k == 0) break;
    solve();
  }
}
