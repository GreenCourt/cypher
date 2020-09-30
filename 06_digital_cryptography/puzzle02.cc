#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<char> hello = {'h', 'e', 'l', 'l', 'o'};
  vector<char> text = {0b00111111, 0b00101010, 0b00111110, 0b00100000, 0b00101011};
  int n = text.size();
  for(int i=0; i<n; ++i) {
    cout << (char)((int)hello[i]^(int)text[i]);
  }
  cout << endl;
}
