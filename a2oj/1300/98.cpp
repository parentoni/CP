#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  
  vector<int> v;
  for (int i=0;i<n;i++){
    int in;
    cin >> in;
    v.push_back(in);
  }

  vector<int> c = v;
  sort(v.begin(), v.end());

  int max = -1, min = INT_MAX;
  int s = 0;
  for (int i=0;i<n;i++){
    if (c[i] != v[i]) {
      if (i > max) max =i;
      if (i < min) min=i;
    } else {
      s++;
    }
  }

  if (s == n) {
    cout << "yes" << endl;
    cout << "1 1" << endl;
    return 0;
  }
  for (int i=0;i<=max - min;i++){
    if (c[max -i] != v[min+i]) {

      cout << "no" << endl;
      return 0;
    }
  }

  cout << "yes" << endl;
  cout << min + 1<< " " << max +1<< endl;

}
