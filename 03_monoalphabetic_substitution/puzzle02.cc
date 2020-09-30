#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<string> q(6);
  q[0] = "LGGK VHZXJ RP VJJCEVO CK ZMX MGEXO C SCLDGEXJXS";
  q[1] = "LGRX IVIXJL CK ZMX IGDQXZ GH ZMX SJXLL UMCDM C MVS";
  q[2] = "ZVQXK HJGR PGBJ OVWGJVZGJP. VZ HCJLZ C MVS";
  q[3] = "KXNOXDZXS ZMXR, WBZ KGU ZMVZ C UVL VWOX ZG SXDCIMXJ";
  q[4] = "ZMX DMVJVDZXJL CK UMCDM ZMXP UXJX UJCZZXK, C";
  q[5] = "WXNVK ZG LZBSP ZMXR UCZM SCOCNXKDX";

  map<char, char> t;
  t['A'] = '_';
  t['B'] = 'u';
  t['C'] = 'i';
  t['D'] = 'c';
  t['E'] = 'v';
  t['F'] = '_';
  t['G'] = 'o';
  t['H'] = 'f';
  t['I'] = 'p';
  t['J'] = 'r';
  t['K'] = 'n';
  t['L'] = 's';
  t['M'] = 'h';
  t['N'] = 'g';
  t['O'] = 'l';
  t['P'] = 'y';
  t['Q'] = 'k';
  t['R'] = 'm';
  t['S'] = 'd';
  t['T'] = '_';
  t['U'] = 'w';
  t['V'] = 'a';
  t['W'] = 'b';
  t['X'] = 'e';
  t['Y'] = '_';
  t['Z'] = 't';
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
