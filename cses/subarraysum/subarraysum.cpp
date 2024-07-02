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

  ll n, target, y=0;
  cin >> n >> target;

  vl nums(n);
  for (auto &el: nums) cin >> el;

  int left = 0;
  int right = 0;

  ll sum = nums[right];
  while(left != n){
    while(nums[right+1] + sum <= target && right != n){
      right++;
      sum += nums[right];
    }
    if (sum == target) y++;
    sum -= nums[left];
    left++;

  }

  cout << y << endl;
}
