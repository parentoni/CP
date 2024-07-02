#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

// functions
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

vector<bool> erasthotenes(ll n){

  vector<bool> m(n+1);

  for (int i=0;i<n+1;i++) m[i] = 0;
  m[0] = m[1] = 1;
  for (int i=2;i*i<n+1;i++) {
    if (m[i] == false) {
      for (int j=i*2;j<n+1;j += i) {
        m[j] = true;
      }
    }
  }

  return m;
}
void tPrime(ll n, vector<bool> prime) {
  ll nsqrt = floor(sqrt(n));
  if (nsqrt * nsqrt == n && !prime[nsqrt]) yes();
  else no();
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<bool> p = erasthotenes(1000000);
  for (int i=0;i<n;i++){
    ll t;
    cin >> t;
    tPrime(t,p);
  }
}

