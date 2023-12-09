#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define int long long

using namespace std;
char c[14] = {
  'A', '1', '2', '3', '4', '5', '6', '7', '8',
  '9', 'T', 'J', 'Q', 'K'
};

// '5','4', 'f', '3', 't', 'o', 'h'
// '7', '6', '5', '4', '3', '2', '1'
char hand_val(string h) {
  vector<int> cnt(14, 0);
  

  int j_cnt= 0;
  for (char t : h) {
    if (t == 'J') {
      j_cnt++;
      continue;
    }
    int x = distance(c, find(c, c+14, t));
    cnt[x]++;
  }
  if (j_cnt == 5) return '7';

  for (int i = 4; i >= 1; --i) {
    for (int j = 0; j < cnt.size(); ++j) {
      if (cnt[j] == i) {
        cnt[j] += j_cnt;
        j_cnt = 0;
      }
    }
  }


  for (int v : cnt) {
    cout << v << " ";

  }
  cout << endl;
  cout << h << " is ";
  //check for 5 of a kind or 4
  for (int val : cnt) {
    if (val == 5) {
      cout << "five of a kind" << endl;
      return '7';
    }
    if (val == 4) {

      cout << "four of a kind" << endl;
      return '6';
    }
  }

  //check for full house or 3 of a kind
  for (int val : cnt) {
    if (val == 3) {
      for (int val2: cnt) {
        if (val2 == 2) {
          cout << "Full house" << endl;
          return '5';
        }
      }
      cout << "Three of a kind " << endl;
      return '4';
    }
  }

  //check for two pair or one pair
  //for (int i = 0; i < cnt.size() - 1; ++i) {
    //int val = cnt[i];
    //if (val == 2) {
      //for (int j = i+1; j < cnt.size(); ++j) {
        //if (val == 2 && i!=j) {
          //cout << "Two pair at i: "<< i << " j: " << j << endl;
          //return '3';
        //}
      //}
      //cout << "one pair" << endl;
      //return '2';
    //}
  //}
  bool one_pair = false;
  for (int val : cnt) {
    if (val == 2 && one_pair) {
      cout << "Two pair" << endl;
      return '3';
    }
    if (val == 2) {
      one_pair = true;
    }
  }
  if (one_pair)  {
  cout << "One pair"<< endl;
  return '2';
}
  cout << "high card" << endl;

  return '1';
}
bool check_eq(string h1, string h2) {
  for (int i = 0; i < h1.size(); ++i) {
    switch(h1[i]) {
      case 'A':
        h1[i] = '9' + 5;
        break;
      case 'J':
        h1[i] = '1';
        break;
      case 'K':
        h1[i] = '9' + 4;
        break;
      case 'T':
        h1[i] = '9' + 1;
        break;
      case 'Q':
        h1[i] = '9' + 3;
        break;
    }
  }
  for (int i = 0; i < h2.size(); ++i) {
    switch(h2[i]) {
      case 'A':
        h2[i] = '9' + 5;
        break;
      case 'J':
        h2[i] = '1';
        break;
      case 'K':
        h2[i] = '9' + 4;
        break;
      case 'T':
        h2[i] = '9' + 1;
        break;
      case 'Q':
        h2[i] = '9' + 3;
        break;
    }
  }
  return h1 > h2;
}

bool cmp_hands(string h1, string h2) {
  char h1_val = hand_val(h1);
  char h2_val = hand_val(h2);
  if (h1_val != h2_val) {
    return h1_val > h2_val;
  }
  return check_eq(h1, h2);

}

signed main() {
  string h;
  int b;

  vector<string> hands;
  vector<int> bids;
  while (cin >> h >> b) {
    hands.push_back(h);
    bids.push_back(b);
  }


  for (int i = 0; i < hands.size(); i++) {
    for (int j = 0; j < hands.size(); j++) {
      if (cmp_hands(hands[i], hands[j])) {
        //swap 
        string tmp = hands[i];
        int tmp2 = bids[i];
        hands[i] = hands[j];
        bids[i] = bids[j];
        hands[j] = tmp;
        bids[j] = tmp2;
      }
    }
  }

  int r = 1;
  int res = 0;

  for (int i = bids.size() - 1; i >= 0; i--) {
    cout << "hand: " << hands[i] << " bid: " << bids[i] << " * " << r << endl;
    res += bids[i] * r;
    r++;
  }
  cout << res << endl;
}
