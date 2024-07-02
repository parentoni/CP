#include <bits/stdc++.h>
using namespace std;

//#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll INF = 1e18;
const ll MOD = 1000000007;

int n, k;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> k;
  vector<int> diff(n+1);
  for (int i=0;i<k;i++){
    int a, b;
    cin >> a >> b;
    diff[a]++;
    diff[b+1]--;
  }

  vector<int> values(n);
  values[0] = diff[1];
  for (int i=0;i<=n;i++){
    if (i==0) values[i] = diff[i+1];
    else values[i] = values[i-1] + diff[i+1];
  }

  sort(values.begin(), values.end());
  cout << values[n/2] << endl;
}
