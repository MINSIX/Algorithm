#include<bits/stdc++.h>
using namespace std;
int main(){
  
  vector<int>arr(26,0);
 int ccnt=0;
 int now=3;
  for(int i=0;i<26;i++){
    arr[i]=now;
    ccnt++;
    if(ccnt>=3)
    {
      if(now==8||now==10)
     {
       if(ccnt==4)
      {
      ccnt=0;
        now++;

      }
    } else{
  
    ccnt=0;
      now++;
    }
      
    }
   
    
  }

  string s;
  cin >> s;
  int cnt=0;
  for(int i=0;i<s.length();i++){
    cnt+=arr[s[i]-'A'];
    
  }
  cout << cnt;
  
  
}