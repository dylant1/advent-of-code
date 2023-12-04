#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

int main() {
  string s;
  int res = 0;
  int arr[100001];
  int curr = 1;
  //memset(arr, 0, sizeof(arr));
  for (int i =0; i < 100001; ++i) {
    arr[i] = 1;
  }
  while (getline(cin, s)) {
    string n = s.substr(s.find(':') + 2);
    string winning = n.substr(0, n.find('|'));
    string ours = n.substr(n.find('|') + 1);
    //cout << winning << endl;
    //cout << ours << endl;
    unordered_set<int> w;
    stringstream ss(winning);

    int i;
    while (ss >> i) {
      //w.insert(stoi(i));
      w.insert(i);
    }
    int cnt = 0;
    stringstream ss2(ours);
    while (ss2 >> i) {
      if (w.find(i) != w.end()) {
        cnt++;
      }
    }

    for (int k = 0; k < arr[curr]; ++k) {
      for (int j = 1; j < cnt + 1; j++) {
        //cout << "added one to " << curr + j << " card\n";
        //arr[curr+j]*=2;
        arr[curr+j]++;
      }
    }



    //cout << "card " << curr << " won "<< arr[curr] << " cards" << endl;
    //res += cnt * arr[curr];
    res += arr[curr];

    curr++;
  }
  cout << res << endl;
}
