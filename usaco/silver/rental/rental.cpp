#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll INF = 1e18;
const ll MOD = 1000000007;

ll n,m,r, y = 0;
vector<int> cows, rent;
vector<pair<int,int>> milk;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setIO("rental");
  cin >> n >> m >> r;

  cows.resize(n); milk.resize(m); rent.resize(r);

  for (auto &el: cows) cin >> el;
  for (auto &el: milk){
    int a, b;
    cin >> a >> b;
    el = {b,a};
  }

  for (auto &el: rent) cin >> el;
  sort(all(cows)); sort(all(milk)); sort(all(rent));
  
  int pointer_cow = n-1;
  int pointer_milk = m-1;
  int pointer_rent = r-1;

  int skip = 0;
  while(pointer_cow >= skip) {

    ll money_rent = -INF;
    ll money_milk = -INF;

    int last = 0;
    int milkable = cows[pointer_cow];
    
    int milk_stores = pointer_milk;
    int milk_sold_at_last = 0;

    if (pointer_rent > 0) money_rent = rent[pointer_rent];
    if (pointer_milk > 0) money_milk = 0;

    while(milk_stores >= 0){
      int sell = min(milkable, milk[milk_stores].second);
      money_milk += sell * milk[milk_stores].first;
      milkable -= sell;
      if (milkable == 0) {
        last = milk[milk_stores].second - sell;
        break;
      } else {
        milk_stores--;
      }
    }

    if (money_milk > money_rent || pointer_rent <= 0) {
      y += money_milk;

      pointer_milk = milk_stores;
      if (pointer_milk >= 0) milk[pointer_milk].second = last;
      pointer_cow--;

    } else {
      y += money_rent;
      pointer_rent--;
      skip++;
    }


  }
  cout << y << endl;
}
