#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int N;
  cin >> N;
  for(int i=N;i>0;i--){
    for(int j=i;j<N;j++){
      cout << " ";
    }
    for(int j=0;j<i;j++){
      cout << "*";
    }
    cout << "\n";
  }
  
}
