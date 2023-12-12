#include <iostream>
#include <vector>

using namespace std;


int main() {
  vector<string> v;

  string l;

  while (cin >> l)  {
    v.push_back(l);
  }

  vector<vector<int> > p;

  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[0].size(); j++) {
      cout << v[i][j];
    }
    cout << endl;
  }

  int x = 0;
  int y = 0;
  for (int i = 0; i < v.size(); i++) {
    x = 0;
    for (int j = 0; j < v[0].size(); j++) {
      if (v[i][j] == '|') {
        x++;
      }
      if (v[i][j] == '-') {
        y++;
        break;
      }
      if (v[i][j] == '#') {
        vector<int> tmp; 
        tmp.push_back(i);
        tmp.push_back(j);
        tmp.push_back(x);
        tmp.push_back(y);
        p.push_back(tmp);
      }
    }
  }
  long long res = 0;

  for (int i = 0; i < p.size()-1; i++) {
    for (int j = i+1; j < p.size(); j++) {
      int diff_i = abs(p[i][0] - p[j][0]);
      int diff_j = abs(p[j][1] - p[j][1]);
      int diff_x = abs(p[i][2] - p[j][2]);
      int diff_y = abs(p[i][3] - p[j][3]);
      int dist = diff_i;
      dist += diff_j;
      dist += (diff_x * 2) - diff_x;
      dist += (diff_y * 2) - diff_y;
      res += dist;
      //res += ((diff_i + diff_j) + (((diff_x * 2) + (2 * diff_y))) - (diff_x + diff_y));
    }
  }

  cout << res << endl;
  return 0;
}
