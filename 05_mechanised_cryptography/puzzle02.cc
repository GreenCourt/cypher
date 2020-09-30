#include"enigma.hpp"
#include<bits/stdc++.h>
using namespace std;

int main() {
  Scrambler sc("UWYGADFPVZBECKMTHXSLRINQOJ");
  Reflector ref("YRUHQSLDPXNGOKMIEBFZCWVJAT");
  string text = "QHSGUWIG";

  int start;
  for(int i=0; i<26; ++i) {
    sc.rot = i;
    sc.rotate();
    if(sc.backward(ref.reflect(sc.forward('Q'-'A'))) == 'X'-'A') {
      start = i;
      break; 
    }
  }

  sc.rot = start;
  for(auto c : text) {
    int p = c - 'A';
    sc.rotate();
    p = sc.forward(p);
    p = ref.reflect(p);
    p = sc.backward(p);
    cout << (char)('A' + p);
  }
  cout << endl;
}
