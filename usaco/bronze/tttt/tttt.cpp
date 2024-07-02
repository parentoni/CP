#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  setIO("tttt");
  //freopen("tttt.in", "r", stdin);
  int t[26*26] = {0};
  int in[26] = {0};

  set<char> row[3];
  set<char> col[3];
  set<char> dia[2];
  for (int i=0;i<3;i++) {
    string l;
    cin >> l;
    for (int c=0;c<3;c++){
      col[c].insert(l[c]); 
      row[i].insert(l[c]); 
      if (i==c) dia[0].insert(l[c]);
      if (2-i==c) dia[1].insert(l[c]);
    }
  }

  int iw=0;
  int tw=0;

  for (int i=0;i<3;i++) {
    if (row[i].size() == 1) {
      int s = int(*row[i].begin())  -65;
      if (in[s] == 0) {
        iw++;
        in[s] = 1;
      }
    } 

    if (row[i].size() == 2) {
      int s = int(*row[i].begin())  -65+ int(*(++row[i].begin())) -65;
      if (t[s] == 0) {
        tw++;
        t[s] = 1;
      }
    }
  }

  for (int i=0;i<3;i++) {
    if (col[i].size() == 1) {
      int s = int(*col[i].begin())-65;
      if (in[s] == 0) {
        iw++;
        in[s] = 1;
      }
    } 

    if (col[i].size() == 2) {
      int s = int(*col[i].begin()) -65 + int(*(++col[i].begin())) -65;
      if (t[s] == 0) {
        tw++;
        t[s] = 1;
      }
    }
  }

  for (int i=0;i<2;i++) {
    if (dia[i].size() == 1) {
      int s = int(*dia[i].begin()) - 65;
      if (in[s] == 0) {
        iw++;
        in[s] = 1;
      }
    } 

    if (dia[i].size() == 2) {
      int s = int(*dia[i].begin()) -65 + int(*(++dia[i].begin())) -65;
      if (t[s] == 0) {
        tw++;
        t[s] = 1;
      }
    }
  }
  cout << iw << endl << tw << endl;
  
}
