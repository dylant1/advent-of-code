#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<string> nums;
string di;

string separate(string s) {
  string res;
  for (int i = 0; i < s.size(); i++) {
      if (s[i] <= '9' && s[i] >= '0') {
        res += s[i];
        //cout << s[i];
        continue;
      }
      for (int j = 0; j < nums.size(); j++) {
        if (s.size() - i >= nums[j].size()) {
          string sub1 = s.substr(i, nums[j].size());
          if (sub1 == nums[j]) {
            //cout << nums[j] << endl;
            res += to_string(j+1);
            break;
          }
        }
      }
  }

  return res;
}

int main() {
  nums.push_back("one");
  nums.push_back("two");
  nums.push_back("three");
  nums.push_back("four");
  nums.push_back("five");
  nums.push_back("six");
  nums.push_back("seven");
  nums.push_back("eight");
  nums.push_back("nine");
  di += '1';
  di += '2';
  di += '3';
  di += '4';
  di += '5';
  di += '6';
  di += '7';
  di += '8';
  di += '9';

  vector<int>res;
  string s;

  while (cin >> s) {

    string new_s;
    new_s = separate(s);
    //cout << new_s << endl;

    string comb;
    for (int i = 0; i < new_s.size(); i++) {
      if (new_s[i] <= '9' && new_s[i] >= '0') {
        comb = new_s[i];
        break;
      }
    }

    for (int i = new_s.size() - 1; i >= 0; i--) {
      if (new_s[i] <= '9' && new_s[i] >= '0') {
        comb += new_s[i];
        break;
      }

    }
    cout << stoi(comb) << endl;
   res.push_back(stoi(comb));
  }
  int sol = 0;
  for (int i = 0; i < res.size(); i++) {
    sol += res[i];
  }
  cout << sol;

  return 0;
}
