#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
#define int long long

signed main() {

  vector<int> seeds;
  string first;
  getline(cin, first);
  string end = first.substr(7);
  int seed;
  int seed2;
  stringstream ss(end);
  while (ss >> seed >> seed2) {
    seeds.push_back(seed);
    for (int i = seed+1; i < seed + seed2 - 1; i++) {
      seeds.push_back(i);
    }
  }

  //for (auto i: seeds) {
  //cout << i << endl;
  //}

  for (int i = 0; i < 8; ++i) {
    string s;
    vector<bool> changed_this_iteration;
    for (int j = 0; j < seeds.size(); j++) {
      changed_this_iteration.push_back(false);
    }

    vector<vector<int> > vec;
    while (getline(cin, s)) {
      if (s.size() == 0) {
        getline(cin, s);
        break;
      }

      int n1, n2, n3;
      stringstream ss2(s);
      //cout << s << endl;
      ss2 >> n1 >> n2 >> n3;
      vector<int> v1;
      v1.push_back(n1);
      v1.push_back(n2);
      v1.push_back(n3);
      vec.push_back(v1);


      for (int j = 0; j < seeds.size(); j++) {
        //cout << "checking seed: " << seeds[j] << endl;
        for (vector<int> r : vec) {
          if (seeds[j] >= r[1] && seeds[j] < r[1] + r[2] && !changed_this_iteration[j]) {
            seeds[j] = (r[0] + (seeds[j] - r[1]));
            changed_this_iteration[j] = true;
            break;
          }
        }
      }


    }
    //cout << endl << endl;
  }
  int m = seeds[0];
  for (int s : seeds) {
    if (s < m) {
      m = s;
    }
  }
  cout << m << endl;


  return 0;
}
