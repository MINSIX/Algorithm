#include<bits/stdc++.h>
using namespace std;




int main(){
  int N;
  cin >> N;
  
  vector<long long> devil;
  
  int cnt=0;
  int now=665;
  while(cnt<N){
    
    now ++;
    if(to_string(now).find("666")!=string::npos)
    {cnt++;
    
        devil.push_back(now);
    }
  }
  
  cout << devil[N-1];
}