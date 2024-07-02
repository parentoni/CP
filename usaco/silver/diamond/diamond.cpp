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

ll n, k, y = 0;
vl diamonds;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setIO("diamond");
  cin >> n >> k;

  diamonds.resize(n);
  for (auto &el: diamonds) cin >> el;
  sort(all(diamonds));
  
  int cantake[n];
  int r = 0, l = 0;
  for (;l < n;l++){
    while(r < n && diamonds[r] - diamonds[l] <= k) r++;
    cantake[l] = r - l;
  }

  int maxafter[n+1];
  maxafter[n] = 0;
  for (int i=n-1;i>=0;i--) maxafter[i] = max(cantake[i],maxafter[i+1]);

  for (int i=0;i<n;i++){
    y = max(y, (ll)(cantake[i] + maxafter[i + cantake[i]]));
  }

  cout << y << endl;

}
