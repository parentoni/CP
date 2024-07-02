#include <iostream>
#include <string>

using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  unsigned int n = 0;
  string b; 

  cin >> b;

  for (int i=b.size()-1;i>=0;i--) {
    n = n | (b[i] - '0') << (i);
  }

  cout << n << endl;
}
