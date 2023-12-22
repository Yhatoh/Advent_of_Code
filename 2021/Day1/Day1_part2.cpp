#include<bits/stdc++.h>
using namespace std;

int main(){
  int first, second, third, num;
  cin >> first >> second >> third;
  int prev = first + second + third;
  int res = 0;
  while(cin >> num){
    if(prev < second + third + num) res++;
    prev -= first;
    first = second;
    second = third;
    third = num;
    prev += third;
  }

  cout << res << "\n";
  return 0;
}