#include<bits/stdc++.h>
using namespace std;

int main(){
  string action;
  int x, h, d, aim;
  h = 0;
  d = 0;
  aim = 0;
  while(cin >> action >> x){
    if(action[0] == 'f'){
      h += x;
      d += x * aim;
    } else if(action[0] == 'd'){
      aim += x;
    } else if(action[0] == 'u'){
      aim -= x;
    }
  }
  cout << h * d << "\n";
  return 0;
}