#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array;

bool isPrime(int n) {
  if (n <= 1) return false;

  for (int i=2;i<=sqrt(n);i++){
    if (n % i == 0) return false;
  }

  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  cin >> n >> m;

  if (!isPrime(m)) {
    cout << "NO" << endl;
    return 0;
  }
  
  for (int i = n + 1; i < m;i++){
    if (isPrime(i)) {
       cout << "NO" << endl;
       return 0;
    }
  }

  cout << "YES" << endl;

}
