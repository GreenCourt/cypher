#include<bits/stdc++.h>
using namespace std;

void print_blocks(vector<char> const &text, vector<char> const &key) {
  cout << "==========" << endl;
  int n = text.size();
  for(int i=0; i<n; ++i) {
    cout << bitset<4>(text[i]) << "  " << bitset<4>(key[i]) << endl;
  }
}

void rotate_right(vector<char> &text) {
  int n = text.size();
  for(int i=0; i<n; ++i) {
    for(int t=0; t<i; ++t) {
      char b0 = (text[i] & 0b0001) >> 0;
      char b1 = (text[i] & 0b0010) >> 1;
      char b2 = (text[i] & 0b0100) >> 2;
      char b3 = (text[i] & 0b1000) >> 3;
      text[i] = (b0 << 3) + (b1 << 0) + (b2 << 1) + (b3 << 2);
    }
  }
}

void XOR(vector<char> &text, vector<char> const &key) {
  int n = text.size();
  for(int i=0; i<n; ++i) {
    text[i] ^= key[i];
  }
}

void SWAP(vector<char> &text) {
  for(auto &x : text) {
    char b0 = (x & 0b0001) >> 0;
    char b1 = (x & 0b0010) >> 1;
    char b2 = (x & 0b0100) >> 2;
    char b3 = (x & 0b1000) >> 3;
    x = (b0 << 1) + (b1 << 0) + (b2 << 3) + (b3 << 2);
  }
}

void enc(vector<char> &text, vector<char> &key, bool print=false) {
  if(print) print_blocks(text, key);
  SWAP(text); SWAP(key);
  if(print) print_blocks(text, key);
  XOR(text, key);
  if(print) print_blocks(text, key);
  rotate_right(text);
  if(print) print_blocks(text, key);
}

int main() {
  vector<char> text = {0b1001, 0b0111, 0b1011,0b0101};
  vector<char> key1 = {('Y' & 0b11110000) >> 4, ('Y' & 0b1111), ('S' & 0b11110000) >> 4, ('S' & 0b1111)};
  vector<char> key2 = {('B' & 0b11110000) >> 4, ('B' & 0b1111), ('X' & 0b11110000) >> 4, ('X' & 0b1111)};

  enc(text, key1);
  enc(text, key2);

  char ans1 = (char)((text[0] << 4) + text[1]);
  char ans2 = (char)((text[2] << 4) + text[3]);
  cout << ans1 << ans2 << endl;
}
