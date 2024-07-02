#include <bits/stdc++.h>
using namespace std;

#define ar array

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

ar<int, 26> necessary_char(string a, string b) {
  ar<int,26> tl = {0};
  for (auto el: a) {
    tl[el-97]++;
  }

  for (auto el: b) {
    tl[el-97]++;
  }

  return tl;
}

int n;
vector<string> p;
vector<pair<string, string>> w;
int l[26] = {0};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("blocks");
  //freopen("blocks.in", "r", stdin);
  cin >> n;

  for (int i=0;i<n;i++){
    pair<string, string> b;
    cin >> b.first >> b.second;
    w.push_back(b);
  }

  for (int i=0;i<n;i++) {
    int sr[26] = {0};
    int sl[26] = {0};
    for (auto el: w[i].first) {
      sr[el - 97]++;
    }

    for (auto el: w[i].second) {
      sl[el - 97]++;
    }

    for (int i=0;i<26;i++) {
      int mn = min(sl[i], sr[i]); 
      l[i] += mn + sl[i] - mn + sr[i] - mn;
    }
  }

  for (auto el: l) {
    cout << el << endl;
  }
}

