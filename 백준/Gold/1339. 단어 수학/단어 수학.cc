#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int N;
  cin >> N;
  vector<int> mm(26,0);
  for(int i=0;i<N;i++){
    string s;
    cin >> s;
    int cnt=0;
    for(int j=s.size()-1;j>=0;j--){
      mm[s[j]-'A']+=pow(10,cnt);
      cnt++;
    
 
      
    }
    
    
  }
  sort(mm.begin(),mm.end(),greater<int>());
  
  long long ssum=0;
  int now=9;
  for(int i=0;i<26;i++){
  ssum+=mm[i]*now;
  now--;
  }
  cout << ssum;
  
}