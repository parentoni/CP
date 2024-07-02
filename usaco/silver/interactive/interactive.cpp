#include <iostream>
#include <string>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll lo =1, hi = 1000000;

  while (lo <= hi) {
    ll med = lo + (hi - lo) / 2;

    cout << med << endl; 

    string s; cin >> s;
    if (s == "<") {
      hi = med -1;
    } else {
      lo = med + 1;
    }
  }

  cout << "! " << hi << endl;
}
