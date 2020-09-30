#include<bits/stdc++.h>
using namespace std;

char dec(char key, char t) {
  int shift = key - 'A' + 1;
  int s = t - 'A' - shift;
  if(s < 0) s += 26;
  return (char)('a' + s);
}

int main() {
  string key = "PUR";
  string text = "JCWSVLIVLVGSJJFJCWCVL";

  for(int i=0; i<text.size(); i++) cout << dec(key[i % key.size()], text[i]);
  cout << endl;
}
