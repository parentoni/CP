#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define all(x) (x).begin(), (x).end()

// functions
void setIO(string s) {freopen((s + ".in").c_str(), "r", stdin);freopen((s + ".out").c_str(), "w", stdout);}
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// values
const ll INF = 1e18;
const ll mod = 1000000007;

ll n, y=0;
map<pair<string,string>, int> cities;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //freopen("citystate.in", "r", stdin);
  setIO("citystate");
  cin >> n;

  for (int i=0;i<n;i++){
    string city, state;
    cin >> city >> state;
    city = city.substr(0,2);

    if (city != state) y += cities[make_pair(state,city)];
    cities[make_pair(city,state)]++;
  }

  cout << y << endl;

}
