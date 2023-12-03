#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {

  vector<string> v;
  unordered_map<int, vector<int> >m;

  string r;
  while (cin >> r) {
    v.push_back(r);
  }

  for (int i = 0; i < v.size(); ++i) { 

    for (int j = 0; j < v[0].size(); ++j) {
      string n;
      if (v[i][j] <= '9' && v[i][j] >= '0') {
        int start = j;
        while (v[i][j] <= '9' && v[i][j] >= '0') {

          n += v[i][j];
          j++;
        }
        int ncols = v[0].size();
        for (int k = i - 1; k <= i+1; ++k){
          for (int l = start - 1; l < j+1; ++l) {
            if ((k >= 0) && (k < v.size() && (l >= 0) && (l < v[0].size()))) {
              if (v[k][l] == '*') {
                m[k * ncols + l].push_back(stoi(n));
              }
            }
          }
        }
      }
    }
  }
  int gear = 0;
  for (auto i : m) {
    if (i.second.size() == 2) {
      cout << "gear: " << i.first << " has values: ";
      cout << i.second[0] * i.second[1] << endl;
      gear += (i.second[0] * i.second[1]);
    }
  }
  cout << "sum of gear ratios: " << gear << endl;
}
