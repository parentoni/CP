#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vl = vector<ll>;
using pll = pair<ll,ll>;

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll inf = 1e18;
const ll MOD = 1000000007;

struct Movie {
  ll start,end;
};

ll n, k, y =0;;
vector<Movie> movies;
multiset<ll> people;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");
  
  cin >> n >> k;

  for (int i=0;i<n;i++) {
    ll a,b;
    cin >> a >> b;
    movies.push_back({a,b});
  }
  for (int i=0;i<k;i++) people.insert(0);

  sort(all(movies), [](Movie a, Movie b){return a.end<b.end;});
  for (auto current: movies) {

    auto it = people.upper_bound(current.start);
    if (it != people.begin()) it--;

    if (*it > current.start) continue;
    people.erase(it);
    people.insert(current.end);
    y++;
  }

  cout << y << endl;


}

