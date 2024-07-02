#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array


// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll INF = 1e18;

ll n;
vector<pair<string,string>> rules;
vector<string> cows = { "Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};

bool check() {

  for (auto rule: rules) {
    for (int i=0;i<8;i++){
      if (cows[i] == rule.first) {
        if(i > 0 && i<7) {
          if (cows[i+1] != rule.second && cows[i-1] != rule.second) return false;
        } else if (i==0) {
          if (cows[i+1] != rule.second) return false;
        } else if (i==7) {
          if (cows[i-1] != rule.second) return false;
        } 
      }
    }
  }
      
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setIO("lineup");
  sort(cows.begin(), cows.end());
  cin >> n;
  rules.resize(n);

  for (auto &el: rules) {
    for (int i=0;i<6;i++) {
      string t;
      if (i==0) cin >> el.first;
      else if (i==5) cin >> el.second;
      else cin >> t;
    }
  }

  do {
    if (check()) {
      for (auto el: cows) cout << el << endl;
      return 0;
    }
  } while (next_permutation(cows.begin(), cows.end()));
}
