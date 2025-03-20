#include<bits/stdc++.h>
using namespace std;

vector<int>arr;

vector<int>arrB;


int main(){
  int A,B;
  cin >> A>>B;
  int copyB=B;
  
  int aMin=9;
  int bMax=0;
  while(A){
    arr.push_back(A%10);
    aMin=min(aMin,A%10);
    A/=10;
  }
  while(B){
    arrB.push_back(B%10);
    
    bMax=max(bMax,B%10);
    B/=10;
  }
  B=copyB;
  
  if(arr.size()>arrB.size())
  {
    cout << -1;
    return 0;
  }
  if(aMin>bMax){
    cout << -1;
    return 0;
  }
  vector<int>sv;
  sort(arr.begin(),arr.end());
  do{
    if(*arr.begin()==0)
    continue;
    
    int name=0;
    for(auto it=arr.begin();it!=arr.end();it++)
      {
             name*=10;
            name+=*it;
       
        
      }
    
    sv.push_back(name);
  }while(next_permutation(arr.begin(),arr.end()));
  
  sort(sv.rbegin(),sv.rend());
  
 for(int i=0;i<sv.size();i++){
   if(sv[i]>B)
   continue;
   cout << sv[i];
   return 0;
 }
  cout << -1;
  
}