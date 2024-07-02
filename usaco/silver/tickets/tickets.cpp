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

ll m, n;
multiset<ll> tickets;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i=0;i<n;i++){
    int t;
    cin >> t;
    tickets.insert(t);
  }

  ll customers[m];
  for (auto &el: customers) cin >> el;

  for (auto cus: customers){
    auto it = tickets.upper_bound(cus);
    if (it == tickets.begin()){
      cout << -1 << endl;
    } else {
      cout <<*(--it) << endl;
      tickets.erase(it);
    }
  }
}
