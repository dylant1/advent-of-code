#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;
//int res = 0;


int seen[1000][1000];
char loop[1000][1000];
char tmp[1000][1000];

bool compatible(int r, int c, int prev_r, int prev_c, vector<string> m) {
  char curr = m[r][c];
  char prev = m[prev_r][prev_c];
  if (prev == 'S') {
    return true;
  }
  //need case for 'S'
  //down
  if (r - prev_r > 0) {
    if ((prev == '|' || prev == '7' || prev == 'F') && (curr == '|' || curr == 'J' || curr == 'L')) {
      return true;
    }
    return false;
  }
  //up
  else if (r - prev_r < 0) {
    if ((prev == '|' || prev == 'L' || prev == 'J') && (curr == '|' || curr == 'F' || curr == '7')) {
      return true;
    }
    return false;
  }
  //right
  else if (c - prev_c > 0) {
    if ((prev == 'L' || prev == 'F' || prev == '-') && (curr == '7' || curr == '-' || curr == 'J')) {
      return true;
    }
    return false;
  }
  //left
  else if (c - prev_c < 0) {
    if ((prev == '7' || prev == 'J' || prev == '-') && (curr == 'L' || curr == '-' || curr == 'F')) {
      return true;
    }
    return false;

  }
  else {
    return false;
  }
}

int dfs(int r, int c, vector<string> m, int prev_r, int prev_c, char prev) {
  if (r < 0 || r > m.size() - 1) return 0;
  if (c < 0 || c > m[0].size() - 1) return 0;
  if (seen[r][c] != -1) return 0;
  if (m[r][c] == '.') return 0;
  if (!compatible(r, c, prev_r,  prev_c, m)) return 0;
  seen[r][c] = 1;
  loop[r][c] = m[r][c];
  char curr = m[r][c];

  int left = dfs(r, c-1, m, r, c, 'S');
  int down = dfs(r+1, c, m, r, c, 'S');
  int up = dfs(r-1, c, m, r, c, 'S');
  int right = dfs(r, c+1, m, r, c, 'S');

  return 1 + left + down + up + right;
}
void trim(int r, int c, vector<string> m) {
  if (r < 0 || r > m.size() - 1) return;
  if (c < 0 || c > m[0].size() - 1) return;
  if (loop[r][c] == ' ') return;
  if (loop[r][c] == '.') loop[r][c] = ' ';
  else {return;}

  trim(r+1, c, m);
  trim(r-1, c, m);
  trim(r, c+1, m);
  trim(r, c-1, m);
  return;
}

int main() {
  vector<string> m;
  string s;


  while (getline(cin, s)) {
    m.push_back(s);
  }

  memset(seen, -1, sizeof(seen));
  memset(loop, '.',sizeof(loop));

  //for(int i = 0; i < m.size(); ++i){
    //for (int j = 0; j < m[0].size(); ++j) {
      //loop[i][j] = m[i][j];
    //}
  //}

  int r, c;
  for(int i = 0; i < m.size(); ++i){
    for (int j = 0; j < m[0].size(); ++j) {

      if (m[i][j] == 'S') {
        r = i;
        c = j;
      }
    }
  }
  //cout << "s is located at " << r << ", " << c << endl;

  loop[r][c] = 'S';
  int left = dfs(r, c-1, m, r, c, 'S');
  int down = dfs(r+1, c, m, r, c, 'S');
  int up = dfs(r-1, c, m, r, c, 'S');
  int right = dfs(r, c+1, m, r, c, 'S');

  //cout << (1 + left + down + up + right) / 2 << endl;

  //for(int i = 0; i < m.size(); ++i){
    //for (int j = 0; j < m[0].size(); ++j) {
      //if (m[i][j] != '.' && loop[i][j] == '.') loop[i][j] = ' ';
    //}
  //}

  trim(0, 0, m);
  //for(int i = 0; i < m.size(); ++i){
    //for (int j = 0; j < m[0].size(); ++j) {
      //cout << loop[i][j];
      //if (m[i][j] == 'S') {cout << "┌"; continue;}

      //if (loop[i][j] == '7') cout <<"┐";
      //else if (loop[i][j] == 'J') cout << "┘";
      //else if (loop[i][j] == '-') cout << "─";
      //else if (loop[i][j] == 'L') cout << "└";
      //else if (loop[i][j] == 'F')  cout <<"┌";
      //else if (loop[i][j] == '|') cout << "|";
      //else if (loop[i][j]==' ') cout << ".";
      //else {cout << " ";}
      //if (loop[i][j] == 'J') 
      //cout << loop[i][j];
    //}
    //cout << endl;
  //}
  int res2 = 0;

  for(int i = 0; i < m.size(); ++i){
    bool inside = false;
    for (int j = 0; j < m[0].size(); ++j) {
      cout << loop[i][j];
      if (loop[i][j] == '.') {
        if (inside) {
          res2++;
        }
      }
      else {
        inside = !inside;
      }
    }
    cout << endl;
  }
  //for ()

cout << res2 << endl;
  return 0;
}
