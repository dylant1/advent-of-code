#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int get_next(vector<int> n) {

  bool all_zeros = false;
  vector<vector<int> > subs;
  reverse(n.begin(), n.end());

  while (!all_zeros) {
    vector<int> curr;
    vector<int> it;

    if (subs.size() == 0) it = n;
    else {it = subs[subs.size() - 1];}

    for (int i = 1; i < it.size(); ++i){
      curr.push_back(it[i] - it[i-1]);
    }

    subs.push_back(curr);
    bool all_zeros2 = true;
    for (int i = 0; i < curr.size(); ++i) {
      if (curr[i] != 0) all_zeros2 = false;
    }

    if (all_zeros2) {
      all_zeros = true;
      break;
    }
    //for (int i = 0; i < curr.size(); ++i) {
      //cout <<  curr[i] << " ";
    //}
    //cout << endl;

  }


  int last = 0;
  for (int i = subs.size() - 1; i >= 0; i--) {
    //for (int j = 0; j < subs[i].size(); ++j) {
      //cout << " " << subs[i][j];
    //}
    last += subs[i][subs[i].size() - 1];
    //cout << endl;
  }
  //cout << last + n[n.size() - 1] << endl;

  return last + n[n.size() - 1];
}

int main() {

  int res = 0;
  string line;
  while (getline(cin, line)) {
    int n;
    vector<int> nums;
    stringstream ss(line);
    while (ss >> n) {
      nums.push_back(n);
    }

    res += get_next(nums);
    cout << endl << endl;
  }

  cout << res << endl;

  return 0;
}
