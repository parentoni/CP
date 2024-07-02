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

ll n, x, y=0;
vl numbers;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  cin >> n >> x;
  numbers.resize(n);
  for (auto &el: numbers) cin >> el;
  sort(all(numbers));

  ll sum = 0;
  while(y < n && sum + numbers[y] <= x){
    sum += numbers[y];
    y++;
  }
  cout << y << endl;
}
