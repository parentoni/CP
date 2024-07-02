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

struct Task {
  ll duration, deadline;
};

ll n;
vector<Task> values;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");

  cin >> n;
  values.resize(n);

  for (auto &el: values) cin >> el.duration >> el.deadline;

  sort(all(values), [](Task &a, Task &b){
       return a.duration < b.duration;
  });
  
  ll y = 0;
  ll time = 0;
  for (auto el: values){
    time += el.duration;
    y += el.deadline - time;
  }

  cout << y << endl;
}
