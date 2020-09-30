#include<bits/stdc++.h>
using namespace std;

struct Scrambler {
  int shift[26];
  string wire;
  int rot = 0;
  Scrambler(string wire) : wire(wire) {
    for(int i=0; i<26; ++i) {
      int c = wire[i] - 'A';
      shift[c] = i - c;
      if(shift[c] < 0) shift[c] += 26;
    }
  }
  bool rotate(bool f=true) {
    if(!f) return false;
    rot = (rot+1) % 26;
    return rot == 0;
  }
  int forward(int pos) {
    int s = shift[(pos + rot) % 26];
    pos = (pos + s) % 26;
    return pos;
  }
  int backward(int pos) {
    char c = wire[(pos+rot) % 26];
    int s = shift[c-'A'];
    pos -= s;
    if(pos<0) pos+=26;
    return pos;
  }
};

struct Reflector {
  int shift[26];
  Reflector(string wire) {
    for(int i=0; i<26; ++i) {
      int c = wire[i] - 'A';
      shift[c] = i - c;
      if(shift[c] < 0) shift[c] += 26;
    }
  }
  int reflect(int pos) {
    pos = (pos + shift[pos]) % 26;
    return pos ;
  }
};

struct PlugBoard {
  map<int, int> patch;
  void add_patch(char a, char b) {
    int x = a - 'A';
    int y = b - 'A';
    assert(patch.count(x)==0);
    assert(patch.count(y)==0);
    patch[x] = y;
    patch[y] = x;
  }
  int convert(int pos) {
    if(patch.count(pos)) return patch[pos];
    return pos;
  }
};
