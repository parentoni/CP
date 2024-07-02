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
const ll MAX_N = 5;

ll n, k;
vl values;

/**
 * f(x) = TRUE if its possible to create a subarry with maximum value up to X. FALSE otherwise.
 * */
bool possible(ll x) {
  
  ll s = 0, count = 0;

  for (auto el: values){
    //cout << count << " " <<  s << " " << el << endl;
    if (el > x) return false;
    if (s + el > x) {
      s = el; 
      count++;
    } else {
      s += el;
    }

    if (s == x) {
      count++;
      s = 0;
    }
  }

  if (s!=0) count++;

  if (count > k) return false;
  return true;
}

ll first_true(ll lo, ll hi, function<bool(ll)> f) {

  ll ans = -1;
  while (lo <= hi) {
    ll med = lo + (hi - lo) / 2;
    if (f(med)){
      ans = med;
      hi = med - 1;
    } else {
      lo = med + 1;
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll sum = 0;
  cin >> n >> k;
  values.resize(n);
  for (int i=0;i<n;i++){
    ll t; cin >> t;
    sum += t;
    values[i] = t;
  }


  cout << first_true(0, sum, possible) << endl;
  //cout << possible(7) << endl;
  //cout << possible(8) << endl;
}
