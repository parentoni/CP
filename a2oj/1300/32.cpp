#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int solve(queue<pair<int,int>> c, int m) {
  if (c.size() == 1) return c.front().first;
  if (c.front().second > m) {
    pair<int,int> cp = c.front();
    cp.second -= m;
    c.pop(); c.push(cp);
    return solve(c, m);
  } else {
    c.pop();
    return solve(c,m);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  queue<pair<int,int>> c;
  for (int i=0;i<n;i++){
    pair<int,int> a;
    a.first = i;
    cin >> a.second;
    c.push(a);
  }

  cout << (solve(c, k) + 1) << endl;
}
