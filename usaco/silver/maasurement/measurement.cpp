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

ll n, g, y=0;
map<ll, ll> output;
map<ll, vector<pll>> logs;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("measurement");

  cin >> n >> g;

  for (int i=0;i<n;i++){
    ll day, id, change;
    cin >> day >> id >> change;
    output[id] = g;
    logs[day].push_back({id, change});
  }

  set<ll> global_max_cow;
  for (auto log: logs){
    if (log.first == 0) continue;
    ll local_max = g;
    set<ll> local_max_cow{-1};

    for (auto changes: log.second) {
      output[changes.first] += changes.second;
      if (output[changes.first] > local_max){
        local_max = output[changes.first];
        local_max_cow = {changes.first};
      } else if (output[changes.first] == local_max){
        local_max_cow.insert(changes.first);
      }
    }

    if (global_max_cow.size() == local_max_cow.size()) {
      bool diffenrent = false;
      for (auto el: local_max_cow) {
        if (global_max_cow.count(el) == 0) {
          diffenrent = true;
          break;
        }
      }

      if (diffenrent) y++;
      global_max_cow = local_max_cow;
    } else {
      //cout << global_max_cow.size() << " " << local_max_cow.size() << endl;
      y++;
      global_max_cow = local_max_cow;
    }

  }
  cout << y << endl;


}
