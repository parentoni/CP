#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll inf = 1e18;
const ll MOD = 1000000007;

ll usb, ps2, both, m, y, amount; 
vector<pair<ll, bool>> mouses; // true if usb
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  cin >> usb >> ps2 >> both >> m;

  for (int i=0;i<m;i++) {
    ll a; string t;
    cin >> a >> t;
    mouses.push_back({a, t == "USB"?1:0});
  }

  sort(all(mouses));


  for (auto el: mouses){
    if (usb == 0 && ps2 == 0 && both == 0) break;

    // usb
    if (el.second) {
      if (usb > 0) {
        usb--;
        y++; amount += el.first;
      } else if (both > 0) {
        both--;
        y++; amount += el.first;
      }
    } else {
      if (ps2 > 0){
        ps2--;
        y++; amount += el.first;
      } else if (both > 0){
        both--;
        y++; amount += el.first;
      }
    }
  }

  cout << y << " " << amount << endl;


}
