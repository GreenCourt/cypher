#include"enigma.hpp"
#include<bits/stdc++.h>
using namespace std;

int main() {
  Scrambler sc("UWYGADFPVZBECKMTHXSLRINQOJ");
  Reflector ref("YRUHQSLDPXNGOKMIEBFZCWVJAT");

  string text = "ZYDNI";

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
