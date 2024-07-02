#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using vl = vector<long long>;

bitset<(int)(1e5+1)> b;
vl val; ll n, q;
string r;

void flip(ll r, ll l) {

}

void solve() {

  cin >> n; val.resize(n);
  for (auto &el: val ) cin >> el;
  cin >> r;


  for (int i=0;i<n;i++){
    b[i] = r[i] == '1'; 
  }

  cin >> q;
  for (int i=0;i<q;i++) {
    ll t, r, l; cin >> t;
    if (t == 1) {
      cin >> r >> l;r--;l--;
      flip(r,l);
    } else {
      ll ans = 0, m; cin >> m;
      for (int i=0;i<n;i++) {
        if (b[i] == m) ans ^= val[i];
      }
      cout << ans << " ";
    }
    
  }

  cout << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  
  ll t; cin >> t;
  while(t--) solve();


}
