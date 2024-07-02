
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a;
  int min = INT_MAX, max = 0;
  int r = 0;
  for (int i=0;i<n;i++){
    int s;
    cin >> s;
    if (s<min) {
      min = s;
      if (!i == 0) r++;
    }
    if (s>max) {
      max = s;
      if (!i == 0) r++;
    }
  }

  cout << r << endl;
}

