#include <bits/stdc++.h>
using namespace std;

#define N_INF INT_MIN
#define INF INT_MAX
#define ll long long
#define ar array

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("traffic");
  //freopen("traffic.in", "r", stdin);

  int n;
  cin >> n;
  vector<pair<string, pair<int, int>>> road;
  for (int i=0;i<n;i++){
    pair<string, pair<int, int>> a;
    cin >> a.first >> a.second.first >> a.second.second;
    road.push_back(a);
  }

  int lb = 0, ub = INF;
  for (int i=n-1;i>=0;i--){
    if (road[i].first == "none") {
      for (int j=i;j>=0;j--) {
        if (road[j].first == "none") {
          if (road[j].second.first > lb) {
            lb = road[j].second.first;
          }

          if (road[j].second.second < ub) {
            ub = road[j].second.second;
          }

        } else if (road[j].first == "on") {
          lb -= max(road[j].second.first, road[j].second.second);
          ub -= min(road[j].second.first, road[j].second.second);
          lb = max(0, lb);
          ub = max(0, ub);
        } else {
          lb += min(road[j].second.first, road[j].second.second);
          ub += max(road[j].second.first, road[j].second.second);
        }
      } 
      i = 0;
    } 
  }

  int zlb = 0, zub = INF;
  for (int i=0;i<n;i++){
    if (road[i].first == "none") {
      for (int j=i;j<n;j++) {
        if (road[j].first == "none") {
          if (road[j].second.first > zlb) {
            zlb = road[j].second.first;
          }

          if (road[j].second.second < zub) {
            zub = road[j].second.second;
          }

        } else if (road[j].first == "on") {
          zlb += min(road[j].second.first, road[j].second.second);
          zub += max(road[j].second.first, road[j].second.second);
        } else {
          zlb -= max(road[j].second.first, road[j].second.second);
          zub -= min(road[j].second.first, road[j].second.second);
          zlb = max(0, zlb);
          zub = max(0, zub);
        }
      } 
      i = n;
    } 
  }

  cout << lb << " " << ub << endl;
  cout << zlb << " " << zub << endl;
}

