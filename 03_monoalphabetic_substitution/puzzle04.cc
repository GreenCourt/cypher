#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<string> q;
  q.push_back("AJLP NYRJZJF LZ Y AS GSK QGSM ME");
  q.push_back("JKEJP FSV LPJ LK KEJ ELNN SP ZKY");
  q.push_back("NN YG NSGASG Y ZJGA KEYZ YG ASVW");
  q.push_back("NJ KS WSKE CNLUJZ KEJ ZEYC YZ WS");
  q.push_back("VOEK LGA HYKKJA ZEJ NYJZ LK LGU");
  q.push_back("ESP PJLAF HSP ZJL FSV GJRJP YTL");
  q.push_back("OYGJA L ZMJJKJP ZUESSHJPL UEY");
  q.push_back("NA TYOEK ZLYN EJP KMS EVGAPJA K");
  q.push_back("SGZ GLTJ EYZCLGYSNL");

  map<char, char> t;
  t['A'] = 'd';
  t['B'] = '_';
  t['C'] = 'p';
  t['D'] = '_';
  t['E'] = 'h';
  t['F'] = 'y';
  t['G'] = 'n';
  t['H'] = 'f';
  t['I'] = '_';
  t['J'] = 'e';
  t['K'] = 't';
  t['L'] = 'a';
  t['M'] = 'w';
  t['N'] = 'l';
  t['O'] = 'g';
  t['P'] = 'r';
  t['Q'] = 'k';
  t['R'] = 'v';
  t['S'] = 'o';
  t['T'] = 'm';
  t['U'] = 'c';
  t['V'] = 'u';
  t['W'] = 'b';
  t['X'] = '_';
  t['Y'] = 'i';
  t['Z'] = 's';
  t[','] = ',';
  t[';'] = ';';
  t[' '] = ' ';
  t['.'] = '.';

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
