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

string x, y="";
vector<string> perms;
int char_count[26];

void solve(){
  if (x.size() == y.size()) {

    perms.push_back(y);
    return;
  }

  for (int i=0;i<26;i++) {
    if (char_count[i] > 0) {
      y += (char)('a' + i);
      char_count[i]--;
      solve();
      y.pop_back();
      char_count[i]++;
    }
  }

}
       

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> x;
  for (auto el: x) char_count[el-'a']++;

  solve();

  cout << perms.size()<< endl;
  for (auto el:perms) cout << el<< endl;

}

