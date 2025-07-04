#include<bits/stdc++.h>
using namespace std;




int main(){
  
  int x1,y1;
  cin >>x1>>y1;
  int N;
  cin >> N;
  vector<pair<int,int>>arr(N);
  for(int i=0;i<N;i++){
    cin >>arr[i].second>>arr[i].first;
  }
  sort(arr.begin(),arr.end());
  
  
  int nowx=0;
  int nowy=0;
  int maxx=0;
  int maxy=0;
  
  for(int i=0;i<N;i++){
    if(arr[i].second==1){
      maxx=max(maxx,arr[i].first-nowx);
      nowx=arr[i].first;
      
    }else{
      maxy=max(maxy,arr[i].first-nowy);
      nowy=arr[i].first;
    }
  }
  maxx=max(maxx,x1-nowx);
  maxy=max(maxy,y1-nowy);
  cout << maxx*maxy;
  
  
  
  
  
}