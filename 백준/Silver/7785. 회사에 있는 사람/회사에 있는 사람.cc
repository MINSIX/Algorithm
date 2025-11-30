#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int N;
  cin >> N;
  string a,b;

set<string,greater<string>> mm;
  for(int i=0;i<N;i++){
    cin >>a >> b;
    if(b=="enter")mm.insert(a);
    else
    mm.erase(a);
    
  }
  for(auto i=mm.begin();i!=mm.end();i++)
  cout << *i<<"\n";
  
}