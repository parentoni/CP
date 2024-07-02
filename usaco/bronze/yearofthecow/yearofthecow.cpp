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
map<string, pair<int,int>> pos;
map<string,int> years = {{"Ox",1}, {"Tiger",2}, {"Rabbit",3}, {"Dragon",4}, {"Snake",5}, {"Horse",6}, {"Goat",7}, {"Monkey",8}, {"Rooster",9}, {"Dog",10}, {"Pig",11}, {"Rat",12}};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  pos["Bessie"] = make_pair(0,1);

  cin >> n;
  for (int i=0;i<n;i++){
    string a, mode, year, b;
    for (int j=0;j<8;j++){
      string _;
      if (j==0) cin >> a; 
      else if (j==3) cin >> mode;
      else if (j==4) cin >> year;
      else if (j==7) cin >> b;
      else cin >> _;
    }

    if (mode == "previous") {
      if (years[year] < pos[b].second) {
        pos[a] = make_pair(pos[b].first,years[year]);
      } else {
        pos[a] = make_pair(pos[b].first-1,years[year]);
      }
    } else {
      if (years[year] > pos[b].second){
        pos[a] = make_pair(pos[b].first,years[year]);
      } else {
        pos[a] = make_pair(pos[b].first+1,years[year]);
      }
      
    }
  }

  cout << abs(pos["Elsie"].first * 12 + pos["Elsie"].second-1) << endl;
}

