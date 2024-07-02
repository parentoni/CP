#include <bits/stdc++.h>
using namespace std;

#define ar array;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;

  cin >> n;
  int a[n];

  for (long i=0;i<n;i++) {
    int v;
    cin >> v;
    a[i] = v;
  }

  cin >> m;
  long q[m];
  for (long i=0;i<m;i++) {
    long v;
    cin >> v;
    q[i] = v;
  }

  long long b = 0;
  long long g = 0;

  map<unsigned long, unsigned long> im;
  for (long i=0;i<n;i++) {
    im[a[i]] = i;
  }
  for (auto qe: q) {
    long i = im[qe];
    g = g + i + 1;
    b = b + (n-i);
  } 

  cout << g << ' ' << b << endl;
}
