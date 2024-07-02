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

ll n, m, k, y = 0;
vector<ll> applicants;
vector<ll> apartaments;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  cin >> n >> m >> k;
  applicants.resize(n);
  apartaments.resize(m);

  for (auto &el :applicants) cin >> el;
  for (auto &el: apartaments) cin >> el;

  sort(all(apartaments));
  sort(all(applicants));

  int appli_num = 0, apart_num = 0;
  while( appli_num< n && apart_num < m ){
    ll sum = abs(apartaments[apart_num] - applicants[appli_num]);
    if (sum <= k) {
      apart_num++; appli_num++; y++;
    } else if (apartaments[apart_num] < applicants[appli_num]) apart_num++;
    else appli_num++;
  }

  cout << y << endl;
}
