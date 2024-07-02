#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array


// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll INF = 1e18;


const ll n = 10;
set<ll> y;


void search(int i, vector<ll> buckets_a, ll tank_a, vector<ll> buckets_b, ll tank_b) {
  if (i == 4) {
    y.insert(tank_a);
    return;
  }

  for (int j=0;j<buckets_a.size();j++) {
    ll t = buckets_a[j];

    vector<ll> buckets_a_cp = buckets_a;
    vector<ll> buckets_b_cp = buckets_b;

    buckets_a_cp.erase(buckets_a_cp.begin()+j);
    buckets_b_cp.push_back(t);

    search(i+1, buckets_b_cp, tank_b + t, buckets_a_cp, tank_a -t);
  }


}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //freopen("backforth.in", "r", stdin);
  setIO("backforth");

  vector<ll> a(n);
  vector<ll> b(n);

  for (auto &el: a) cin >> el;
  for (auto &el: b) cin >> el;



  search(0,a,1000,b,1000);
  cout << y.size() << endl;

}
