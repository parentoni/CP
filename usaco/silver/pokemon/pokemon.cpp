#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pii = pair<int,int>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll INF = 1e18;
const ll MOD = 1000000007;

ll n, y;
set<int> pokemons_unique;
vector<int> pokemons;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  y = n;

  for (int i=0;i<n;i++){
    char t;
    cin >> t;
    pokemons_unique.insert(int(t));
    pokemons.push_back(int(t));
  }
  
  int a = 0;
  int b = 0;

  set<int> current;
  map<int,int> count;
  while (a < n && b < n){


    current.insert(pokemons[a]);
    if (current.size() == pokemons_unique.size()){
      y = min(y, (ll)(a-b+1));

      count[pokemons[b]]--;
      if (count[pokemons[b]] == 0) current.erase(pokemons[b]);
      if (a == b) a++;
      b++;
    } else {
      count[pokemons[a]]++;
      a++;
    }
  }

  cout << y << endl;
}
