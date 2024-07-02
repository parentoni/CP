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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, target;
  cin >> n >> target;
  vector<pair<ll,int>> values(n);

  for (int i=0;i<n;i++) {
    int t;
    cin >> t;
    values[i] = {t, i};
  };

  sort(all(values));

  int left=0;
  int right=n-1;

  ll sum = values[left].first + values[right].first;
  while(right>= n/2 || left <= n/2) {
    if (right == left) break;

    if (sum > target) {
      right--;
      sum = values[left].first + values[right].first;
    } else if (sum < target) {
      left++;
      sum = values[left].first + values[right].first;
    } else {
      cout << values[left].second + 1 << " " << values[right].second + 1 << endl;
      return 0;
    }
  }

  cout << "IMPOSSIBLE" << endl;
}
