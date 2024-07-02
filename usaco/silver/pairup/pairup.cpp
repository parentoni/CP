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

ll n, y=0;
vector<pair<ll,ll>> cows;
vl used;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setIO("pairup");

  cin >> n;
  cows.resize(n);
  used.resize(n);

  for(auto &el: cows) cin >> el.second >> el.first;
  sort(all(cows));

  ll r=n-1,l=0, i=0;

  while(r >= l && i < 300){

    ll pairs = min(cows[l].second - used[l], cows[r].second - used[r]);
    r == l? pairs /=2: pairs = pairs;
    used[l] += pairs;
    used[r] += pairs;


    //for (auto el: used) cout << el << " ";
    //cout << endl;

    y = max(y, cows[r].first + cows[l].first);
    if (used[l] >= cows[l].second)l++;
    if (used[r] >= cows[r].second)r--;
    i++;
  }

  cout << y << endl;
}
