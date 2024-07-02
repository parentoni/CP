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
const ll inf = 1e18;
const ll MOD = 1000000007;

//struct Guest {
//  int arrival, departure, id;
//};
//
//bool cmp (const Guest &a, const Guest &b){
//  if (a.departure != b.departure) return b.departure > a.departure; 
//  else return b.arrival > a.arrival;
//}
//
//ll n;
//multiset<Guest, bool (*)(const Guest &a, const Guest &b)> guests(cmp);

ll n;
vector<pair<pair<ll, ll>, int>> guests;
vl ans;
ll max_size = 0;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //setIO("");
  
  cin >> n;
  ans.resize(n);


  for (int i=0;i<n;i++){
    int a, b;
    cin >> a >> b;
    guests.push_back({{a,b}, i});
  }

  sort(all(guests));

  priority_queue<pair<ll, ll>> pq;
  
  int room = 0;
  for (auto el: guests){
    if (pq.empty()){
      room++;
      pq.push({-el.first.second, room});
      ans[el.second] = room;
    } else {
      if (-el.first.first < pq.top().first){
        pair<ll, ll> top = pq.top(); pq.pop();
        pq.push({-el.first.second ,top.second});

        ans[el.second] = top.second;
      } else {
        room++;
        pq.push({-el.first.second, room});
        ans[el.second] = room;

      }
    }

    max_size = max(max_size, (ll)pq.size());
  }

  cout << max_size << endl;
  for (auto el: ans) cout << el << " ";
  cout << endl;
}
