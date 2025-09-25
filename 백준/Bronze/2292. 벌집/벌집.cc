#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int N;
  cin >> N;
  
    int layer = 1;  
    int range = 1;  
    
    while (N > range) {
        range += 6 * layer; 
        layer++;
    }
    
  
  cout << layer;
}