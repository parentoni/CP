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
const ll INF = 1e18;
const ll MOD = 1000000007;

int n, q;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int garland[n];

  string t; cin >> t;
  for (int i=0;i<n;i++) garland[i] = (int)t[i];

  cin >> q;
  pair<int,int> queries[q];
  for (int i=0;i<q;i++) {
    int a; char b;
    cin >> a >> b;
    queries[i] = {a, (int)b};
  }

  // check already full garlands
  for (auto qe: queries) {

    int l=0,r=0,u=0,y=0;
    for (;r < n;r++){
      if (garland[r] != qe.second) u++;
      if (u <= qe.first) y = max(y, r-l+1);
      while(u > qe.first && l < n){
        if (garland[l] != qe.second) u--;
        l++;
      }

    }
    cout << y << endl;

    
  }

}
