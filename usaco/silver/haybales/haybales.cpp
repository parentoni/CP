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

ll n,q;
vector<ll> numbers; 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setio("haybales");

  cin >> n >> q;
  numbers.resize(n);

  for (auto &el: numbers) cin >> el;
  sort(all(numbers));

  for (int i=0;i<q;i++){
    ll a,b;
    cin >> a >> b;
    cout << upper_bound(numbers.begin(), numbers.end(), b) - lower_bound(numbers.begin(), numbers.end(), a)<< endl;
  }


}
