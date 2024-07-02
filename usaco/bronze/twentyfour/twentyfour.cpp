#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array


// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll INF = 1e18;

int const n=4;
vector<ll> cards(n);
ll maximum;

ll op(int opt, ll a, ll b) {
  switch(opt){
    case 0:
      return a + b;
    case 1:
      return a-b;
    case 2:
      return a*b;
    case 3: {
      if (b==0) return INT64_MIN;
      if (a%b != 0) return INT64_MIN;
      return a/b;
    }
  }
  return INT64_MIN;
}
void check() {
  
  for (int a = 0;a<n;a++){
    for (int b = 0;b<n;b++){
      for (int c = 0;c<n;c++){
        ll first = op(a, cards[0],cards[1]);
        if (first == INT64_MIN) continue;
        ll second = op(b, first, cards[2]);
        if (second == INT64_MIN) continue;
        ll result = op(c, second, cards[3]);
        if (result == INT64_MIN) continue;
        if (result <= 24) maximum = max(maximum, result);
      }
    }
  }

  for (int a = 0;a<n;a++){
    for (int b = 0;b<n;b++){
      for (int c = 0;c<n;c++){
        ll resulta =op(a, cards[0],cards[1]);
        if (resulta == INT64_MIN) continue;
        ll resultb = op(b, cards[2], cards[3]);
        if (resultb == INT64_MIN) continue;
        ll result = op(c, resulta, resultb);
        if (result == INT64_MIN) continue;
        if (result <= 24) maximum = max(maximum, result);
      }
    }
  }

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while(t--) {
    for (auto &el: cards) cin >> el;

    maximum = 0;
    do{
      for (auto el: cards) cout << el << " ";
      cout << endl;
      check();
    } while (next_permutation(cards.begin(), cards.end()));
    cout << maximum << endl;

  }
}
