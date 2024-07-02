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

ll n,q;
vector<ll>v_sum;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> q;
  v_sum.resize(n);

  for (int i=0;i<n;i++) {
    int t;
    cin >> t;
    if (i != 0) v_sum[i] = (v_sum[i-1] + t);
    else v_sum[i] = (t);
  }

  for (int i=0;i<q;i++) {
    int a,b;
    cin >> a >> b;
    if (a == 0) cout << v_sum[b-1] << endl;
    else cout << v_sum[b-1] - v_sum[a-1] << endl;
  }
}

