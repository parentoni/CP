#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

// functions
//void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //setIO("");
  //freopen("", "r", stdin);
  int n;
  cin >> n;

  vector<pair<int, char>> v(n);
  map<int, int> liars;
  for (auto &el: v) cin>> el.second >> el.first;

  int c = INT_MAX;
  for (int i=0;i<n;i++){
    int r = 0;
    for (int j=0;j<n;j++){
        if (v[j].second == 'G' && v[j].first > v[i].first) r++;
        if (v[j].second == 'L' && v[j].first < v[i].first) r++;
    }

    c = min(r,c);
  }

  cout << c << endl;
}

