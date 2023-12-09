#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main() {
  string tmp;
  string ins;
  cin >> ins;
  //newline
  unordered_map<string, vector<string> > m;

  string s, e, l, r;
  while (cin >> s >> e >> l >> r) {
    string parsed_1 = l.substr(1, 3);
    string parsed_2 = r.substr(0, 3);
    vector<string> v; 
    v.push_back(parsed_1);
    v.push_back(parsed_2);
    m[s] = v;
  }

  unsigned long long res = 0;

  vector<string> currs;
  vector<bool> hit;
  vector<int> cnts;
  for (auto it : m) {
    if (it.first[2] == 'A') currs.push_back(it.first);
  }
  for (auto b : currs) {
    //cout << "test" << endl;
    hit.push_back(false);
    cnts.push_back(0);
  }

  //cout << "testend";

  while (1) {
    for (int i = 0; i < currs.size(); ++i) {
      if (currs[i][2] == 'Z') {
        hit[i] = true;
      }
    }

    bool n = true;
    for (int k = 0; k < currs.size(); ++k) {
      if (!hit[k]) n = false;
    }
    if (n) break;

    for (int i = 0; i < ins.size(); i++) {
      for (int j = 0; j  < currs.size(); j++) {
        if (ins[i] == 'L') {
          currs[j] = m[currs[j]][0];
        }
        else {
          currs[j] = m[currs[j]][1];
        }
      }
      for (int k = 0; k < cnts.size(); ++k) {
        if (!hit[k]) cnts[k]++;
      }
      //res++;
    }
  }
  //cout << res << endl;
  for (auto s : cnts) {
    cout << s << endl;
  }
  return 0;
}
