#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<string> q(6);
  q[0] = "THSWQD THZ RBXP GWXP HG XL ZWRNBRHK UTPQ WQ KBQZBQ,";
  q[1] = "W THZ SWRWGPZ GTP IOWGWRT XMRPMX, HQZ XHZP RPHOFT";
  q[2] = "HXBQD GTP IBBVR HQZ XHNR WQ GTP KWIOHOL OPDHOZWQD";
  q[3] = "GOHQRLKSHQWH; WG THZ RGOMFV XP GTHG RBXP ABOPVQBUKPZDP";
  q[4] = "BA GTP FBMQGOL FBMKZ THOZKL AHWK GB THSP RBXP";
  q[5] = "WXNBOGHQFP WQ ZPHKWQD UWGT H QBIKPXHQ BA GTHG FBMQGOL.";

  map<char, char> t;
  t['A'] = 'f';
  t['B'] = 'o'; //
  t['C'] = '_';
  t['D'] = 'g'; //
  t['E'] = '_';
  t['F'] = 'c';
  t['G'] = 't'; //
  t['H'] = 'a';
  t['I'] = 'b';
  t['J'] = '_';
  t['K'] = 'l';
  t['L'] = 'y';
  t['M'] = 'u';
  t['N'] = 'p';
  t['O'] = 'r';
  t['P'] = 'e'; //
  t['Q'] = 'n';
  t['R'] = 's'; //
  t['S'] = 'v';
  t['T'] = 'h';
  t['U'] = 'w';
  t['V'] = 'k';
  t['W'] = 'i';
  t['X'] = 'm';
  t['Y'] = '_';
  t['Z'] = 'd'; //
  t[','] = ',';
  t[';'] = ';';
  t[' '] = ' ';

  set<int> x;
  for(auto [k,v] : t) {
    if(v == '_') continue;
    if(x.count(v)!=0){
      cerr << "dups " << v << endl;
      return 1;
    }
    x.insert(v);
  }

  map<char, int> freq;
  for(auto s : q) for(auto c : s) if(c >= 'A' && c <= 'Z') freq[c]++;

  for(auto i : freq) 
    printf("%c: %2d (%c)\n", i.first, i.second, t[i.first]);

  cout << "=========" <<endl;


  for(auto s : q) {
    for(auto c : s) cout << c;
    cout << endl;
    for(auto c : s) cout << t[c];
    cout << endl;
  }
}
