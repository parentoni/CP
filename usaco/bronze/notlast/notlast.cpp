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

ll n;
map<string,int> cows = {{"Bessie",0}, {"Elsie",0}, {"Daisy",0}, {"Gertie",0}, {"Annabelle",0}, {"Maggie", 0}, {"Henrietta",0}};
set<int> prod;
vector<string> sl;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setIO("notlast");
  //freopen("notlast.in","r", stdin);
  cin >> n;

  for (int i=0;i<n;i++) {
    string name;
    int v;
    cin >> name >> v;
    cows[name] += v;
  }

  for (auto el: cows) prod.insert(el.second);

  if (prod.size() == 1) {
    cout << "Tie" << endl;
    return 0;
  }

  for (auto el: cows) {
    if (el.second == *(++prod.begin())) sl.push_back(el.first);
  }

  if (sl.size() > 1) cout << "Tie" << endl;
  else cout << sl[0] << endl;

}
