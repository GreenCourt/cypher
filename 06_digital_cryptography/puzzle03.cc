#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<char> text = {0b01100010, 0b01110101, 0b01111001, 0b01100011, 0b01110101, 0b01100110, 0b01101001};
  vector<char> ans(text.size());
  vector<int> transpose = {2, 1, 3, 1, 2, 5, 7, 2};

  int n = text.size();
  for(int i = 0; i < 8; ++i) {
    int ti = transpose[i];
    int bit = 1 << (7-i);
    for(int from = 0; from < n; from++) {
      int to = (from + ti) % n;
      ans[to] += text[from] & bit;
    }
  }

  for(auto c : ans) cout << c;
  cout << endl;
}
