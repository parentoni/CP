#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array;

ll solve(vector<long int> &a) {
  ll s = 0;
  sort(a.begin(), a.end());
  for (int i=0;i<a.size();i++){
    s = s + abs((i + 1)- a[i]);
  }

  return s;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  long int n;
  cin >> n;
  vector<long int> a;

  for (int i=0;i<n;i++){
    long int c;
    cin >> c;
    a.push_back(c);
  }

  cout <<solve(a) << endl;
}

