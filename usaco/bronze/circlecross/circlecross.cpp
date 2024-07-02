#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setIO("circlecross");
  //freopen("circlecross.in", "r", stdin);
  string r;
  cin >> r;
  
  pair<int,int> l[26];
  for (int i=0;i<52;i++) {
    if (!l[r[i]-65].first) {
      //cout << i << endl;
      l[r[i]-65].first = i+1;
    } else {
      l[r[i]-65].second = i+1;
    }
  }

  int s = 0;
  for (int i=0;i<26;i++){
    for (int j=0;j<26;j++) {
      if (l[i].first < l[j].first && l[i].second> l[j].first && l[i].second < l[j].second) {
        s++;
      }
    }
  }

  cout << s << endl;
}
