#include<bits/stdc++.h>
using namespace std;

void add(string &number, vector< int > &values){
  for(int i = 0; i < number.length(); i++){
    values[i] += number[i] - '0';
  }
}

int main(){
  int quant = 1;
  string number;
  cin >> number;
  vector< int > values(number.length(), 0);
  add(number, values);
  while(cin >> number){
    quant++;
    add(number, values);
  }

  long long pow_2 = 1;
  long long gamma = 0;
  long long epsilon = 0;
  for(int i = values.size() - 1; i >= 0; i--){
    if(values[i] > quant / 2){
      gamma += pow_2;
    }
    if(values[i] < quant / 2){
      epsilon += pow_2;
    }
    pow_2 *= 2;
  }

  cout << gamma * epsilon << "\n";
  return 0;
}
