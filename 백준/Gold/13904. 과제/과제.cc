#include<bits/stdc++.h>
using namespace std;

int main(){
   
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);
   
   int N;
   cin >> N;
   vector<pair<int,int>> arr;
   int a,b;
   for(int i=0;i<N;i++){
     cin >>a>>b;
     arr.push_back({b,a});
   }
   sort(arr.rbegin(),arr.rend());
   
   vector<int> qq(1001,0);
   for(int i=0;i<N;i++){
    
      if(qq[arr[i].second]==0){
      qq[arr[i].second]=arr[i].first;
        
      }else{
        int now=arr[i].second-1;
        if(qq[now]==0)
        {qq[now]=arr[i].first;
          
        }else{
        while(qq[now]){
          now--;
          if(now<0)
          break;
          if(!qq[now])
            {
              qq[now]=arr[i].first;
             break;
            }
        }
        }
      }
     
   }
    
    int mm=0;
    for(int i=1;i<=1000;i++){
      mm+=qq[i];
    }   
  cout <<mm;
  
}