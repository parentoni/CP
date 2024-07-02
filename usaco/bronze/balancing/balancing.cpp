#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

int n, b;
map<pair<int,int>, bool> c;

int max_m(int x, int y){
  int m[4] = {0};
  for (auto el: c){
    if (el.first.first > x && el.first.second > y) m[0]++;
    else if (el.first.first < x && el.first.second > y) m[1]++;
    else if (el.first.first < x && el.first.second < y) m[2]++;
    else if (el.first.first > x && el.first.second < y) m[3]++;
  }

  return max(m[0], max(m[1], max(m[2], m[3])));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setIO("balancing");
  //freopen("balancing.in", "r", stdin);
  cin >> n >> b;

  vector<int> hf;
  vector<int> vf;
  for (int i=0;i<n;i++) {
    int x,y;
    cin >> x >> y;
    c[make_pair(x,y)] = true;
  }

  for (auto el: c) {
    hf.push_back(el.first.first+1);
    vf.push_back(el.first.second+1);
  }
    
  int s= n;
  for (auto h: hf) {
    for (auto v: vf) {
      s = min(s, max_m(h,v));
    }
  }

  cout << s << endl;
}
