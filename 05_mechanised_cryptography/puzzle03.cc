#include"enigma.hpp"
#include<bits/stdc++.h>
using namespace std;

int main() {
  PlugBoard pb;
  pb.add_patch('A','B');
  pb.add_patch('S','Z');
  pb.add_patch('U','Y');
  pb.add_patch('G','H');
  pb.add_patch('L','Q');
  pb.add_patch('E','N');
  Scrambler sc1("UWYGADFPVZBECKMTHXSLRINQOJ");
  Scrambler sc2("AJPCZWRLFBDKOTYUQGENHXMIVS");
  Scrambler sc3("TAGBPCSDQEUFVNZHYIXJWLRKOM");
  Reflector ref("YRUHQSLDPXNGOKMIEBFZCWVJAT");

  sc2.rot = 'A' - 'A';
  sc1.rot = 'E' - 'A';
  sc3.rot = 'B' - 'A';

  string text = "GYHRVFLRXY";

  for(auto c : text) {
    int p = c - 'A';
    sc3.rotate(sc1.rotate(sc2.rotate()));
    p = pb.convert(p);
    p = sc2.forward(p);
    p = sc1.forward(p);
    p = sc3.forward(p);
    p = ref.reflect(p);
    p = sc3.backward(p);
    p = sc1.backward(p);
    p = sc2.backward(p);
    p = pb.convert(p);
    cout << (char)('A' + p);
  }
  cout << endl;
}
