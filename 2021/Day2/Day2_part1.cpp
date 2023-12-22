#include<bits/stdc++.h>
using namespace std;

int main(){
  string action;
  int x, h, d;
  h = 0;
  d = 0;
  while(cin >> action >> x){
    if(action[0] == 'f'){
      h += x;
    } else if(action[0] == 'd'){
      d += x;
    } else if(action[0] == 'u'){
      d -= x;
    }
  }
  cout << h * d << "\n";
  return 0;
}
