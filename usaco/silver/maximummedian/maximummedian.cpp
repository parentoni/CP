#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setio(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"yes\n"; }
void no() { cout<<"no\n"; }

// values
const ll inf = 1e18;
const ll mod = 1000000007;

ll n, k;
vl numbers;

ll last_true(ll low, ll high, function<bool(ll)>f) {

  while(low <= high){
    ll med = low + (high-low)/2;
    if (f(med)){
      low = med + 1;
    } else {
      high = med - 1;
    }
  }

  return high;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setio("");

  cin >> n >> k;
  numbers.resize(n);
  for (auto &el: numbers) cin >> el;
  sort(all(numbers));


  cout << last_true(0, 2e9, [&](ll x){
    ll sum = 0;
    for (int i=(n-1)/2;i<n;i++){
      sum += max((ll)0, x -numbers[i]);
    }
    
    return sum <= k;
  }) << endl;

}
