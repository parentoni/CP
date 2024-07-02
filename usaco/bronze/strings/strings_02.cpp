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

string x;
vector<string>perms;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> x;
  sort(x.begin(),x.end());

  do {
    perms.push_back(x);
  } while(next_permutation(x.begin(), x.end()));

  cout << perms.size() << endl;
  for (auto el: perms) cout << el << endl;
}
