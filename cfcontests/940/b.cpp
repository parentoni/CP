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

void solve() {
  ll n ,k;
  cin >> n >> k;

  int t = (int)log2(k)+1;

  unsigned ll b=0;
  vector<ll>y(t);

  for (int i=0;i<t;i++) {
    y[i] = pow(2,i);
    b += pow(2,i);
  }

  y[y.size()-1] -= (b-k);
  
  while(y.size() < n) {
    y.push_back(0);
  }

  while(y.size() > n) {
    y[0] += y[1];
    y.erase(y.begin()+1);
  }

  for (auto el:y) cout << el << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--) {
    solve();
  }
}

