#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll INF = 1e18;
const ll MOD = 1000000007;

void solve() {
  int n, k;
  cin >> n >> k;

  map<int,int> cards;
  for (int i=0;i<n;i++){
    int t;
    cin >> t;
    cards[t]++;
  }

  for (int i=0;i<n;i++){
    
    for (auto el: cards) {

      if (el.second >= k) {
        //cout << el.first << endl;
        cards[el.first] = el.second - k;
        int new_cards = el.second-1;
        for (auto sel: cards) {
          int necessary = k - sel.second;
          if (necessary <= new_cards) {
            cards[sel.first] = sel.second += necessary;
            new_cards -= necessary;
          }
        }
      }
    }
  }

  int y=0;
  for (auto el: cards) {
    //cout << el.first << " " << el.second << endl;
    y += el.second;
  }

  if (y == 0) y+= k-1;
  cout << y << endl;

}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--){
   solve();
  }
}
