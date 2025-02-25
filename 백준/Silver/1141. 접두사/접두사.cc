#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<string> s(N);
  vector<bool> check(N,true);
  for(int i=0;i<N;i++)
  cin >> s[i];
  
  sort(s.begin(),s.end());
  
  int cnt=0;
  
  for(int i=0;i<N;i++){
  int nowcnt=1;
    for(int j=i+1;j<N;i++){
    if(s[j].substr(0,s[i].length())==s[i])
     check[i]=false;
     break;
    }
  }
  
  
  for(auto i : check)
  if(i)
  cnt++;
  
  cout << cnt;
  
  
}