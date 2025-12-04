#include<bits/stdc++.h>
using namespace std;

int main(){
  int num;
  cin >> num;
  int prev = num;
  int res = 0;
  while(cin >> num){
    if(prev < num) res++;
    prev = num;
  }

  cout << res << "\n";
  return 0;
}