#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {

  string s;
  int id = 1;
  int res = 0;
  while(getline(cin, s)) {
    //vector<int> col;
    //vector<int> num;
    string end = s.substr(s.find(':') + 2);

    string game;

    stringstream ss(end);

    int max_r = 0, max_g = 0, max_b = 0;
    while (getline(ss, game, ';')) {
      for (int i = 0; i < game.size(); i++) {
        if (game[i] == ',') {
          game[i] = ' ';
        }
      }

      //cout << game << endl;
      int n;
      string color;
      stringstream ss2(game);
      while (ss2 >> n >> color) {
        switch(color[0]) {
          case 'r':
            max_r = max(max_r, n);
            break;
          case 'g':
            max_g = max(max_g, n);
            break;
          case 'b':
            max_b = max(max_b, n);
            break;
        }
        //cout << n << " " << color << endl;
      }

    }
    //if (!(max_r > 12 || max_g > 13 || max_b > 14)) {
      //cout << "game id: " << id << endl;
      res += max_r * max_g * max_b;
    //}
    max_r = 0;
    max_g = 0;
    max_b = 0;
    id++;
  }
  cout << res << endl;
}
