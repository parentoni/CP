#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

using ll = long long;
vector<ll> values; ll n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    cin >> n; values.resize(n);
    for (auto &el:values) cin >> el;

    ll max_c = 0;

    for (int i=1;i<n;i++) {
      if (values[i] < values[i-1]) {

        max_c = max(max_c, (ll)floor(log2(values[i-1] - values[i]))+1 );
        values[i] = values[i-1];
      }


    }
  
    //for (auto el: values) cout << el << " ";
    //cout << endl;
  
    cout << max_c << endl;

  }
}
