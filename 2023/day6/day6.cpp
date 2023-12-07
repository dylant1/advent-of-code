#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
  string s;
  vector<long> times;
  vector<long> distances;

  getline(cin, s);
  stringstream ss(s);
  string trash;
  ss >> trash;
  string val;
  string t;
  while (ss >> val) {
    t += val;
  }



  getline(cin, s);
  stringstream ss2(s);
  ss2 >> trash;
  string d;
  while (ss2 >> val) {
    d += val;
    //cout << val << endl;
  }
  int res =1 ;
  times.push_back(stol(t));
  distances.push_back(stol(d));

  for (int j = 0; j < times.size(); j++) {
    long t = times[j];
    long cnt = 0;
    for (long i =0; i < t + 1; i++) {
      long d = i * (t - i);
      if (d > distances[j]) {
        cnt++;
      }
    }
    res *= cnt;
  }


  cout << res << endl;

  return 0;
}
