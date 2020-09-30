#include<bits/stdc++.h>
using namespace std;

string get_key(string enc, string plain) {
  assert(enc.size() == plain.size());
  int n = enc.size();
  for(int i=0; i<n; i++)  enc[i] = enc[i] - 'A' + 'a';
  string key;
  for(int i=0; i<n; i++) {
    int x = (enc[i] - plain[i] - 1);
    if(x < 0) x += 26;
    key.push_back(x + 'A');
  }
  return key;
}

char dec(char key, char t) {
  if (t < 'A' || t > 'Z') return t;
  int shift = key - 'A' + 1;
  int s = t - 'A' - shift;
  if(s < 0) s += 26;
  return (char)('a' + s);
}

int main() {
  string text;
  text += "LAFLUIWOYWPADUFHSNBVSWVNDZQDUF\n";
  text += "RBPLUYQPLWLPHZRLUEDUBSYMIPRDIJ\n";
  text += "HTYQUCUZYLKFRSKHZBUHULUEKPQFOY\n";
  text += "LYSSAMWOCWHZOLGDTDDPPOFDDTGOPY\n";
  text += "UDGWOYOSDRYKVVDVLAULRZYGWPLJZY\n";
  text += "QKYPTWVLJIAFHHSWOMUVDDAPLMJLUE\n";
  text += "PVLRNPDWFXWMQAFHZSEQCFAGQDFLJF\n";
  text += "LHLDSWCLMQLFXUBULBDUBVPVWFQHWY\n";
  text += "UHRHJGSOCUZZXAGFVLILQVAFDARKPQ\n";
  text += "LZCQAGULJBUCZAMPL\n";

  map<string, int> freq;
  string text2;
  for(auto c : text) if(c != '\n') text2.push_back(c);
  int rep = 3;
  for(int i=0; i<text2.size() - rep; i++) freq[text2.substr(i,rep)]++;
  vector<pair<int, string>> freq2;
  for(auto [k,v] : freq) freq2.emplace_back(v, k);
  sort(freq2.begin(), freq2.end());

  map<string, int> freq_key;
  for(auto [v,k] : freq2) if(v > 1) {
    cout << k << " (" << v << "): ";
    for(auto plain : {"the", "ing", "and", "her", "ere", "ent", "tha", "nth", "was", "eth", "for", "dth"}) {
      cout  << " " << get_key(k, plain);
      freq_key[get_key(k, plain)]++;
    }
    cout << endl;
  }

  vector<string> key;
  int mx = 0;
  for(auto [k,v] : freq_key) {
    if(mx < v) {
      key.clear();
      mx = v;
      key.push_back(k);
    }
    else if(mx == v) {
      key.push_back(k);
    }
  }

  for(auto k : key) {
    cout << "==============================" << endl;
    cout << "key: " << k << endl;
    for(int i=0; i<text.size(); i++) cout << dec(k[i % k.size()], text[i]);
    cout << endl;
  }
}
