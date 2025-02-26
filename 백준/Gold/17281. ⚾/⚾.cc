#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  int T;
  cin >> T;
  vector<vector<int>>arr(T,vector<int>(9));
  
  
  for(int i=0;i<T;i++)
  for(int j=0;j<9;j++)
  cin >>arr[i][j];
  
  int ans=0;
  int player[8]={1,2,3,4,5,6,7,8};
  do{
    deque<int> setting;
    for(int i=0;i<3;i++)setting.push_back(player[i]);
    setting.push_back(0);
    for(int i=3;i<8;i++)setting.push_back(player[i]);
    
    int times=0, cnt=0;
    while(times<T){
      int out=0;
      queue<int> bases;
      for(int i=0;i<3;i++)bases.push(0);
      
      while(out < 3){
        int better = setting.front();
        setting.pop_front();
        setting.push_back(better);
        if(arr[times][better]==0)out ++;
        else{
          if(bases.front()==1)cnt++;
          bases.push(1);bases.pop();
          for(int i=0;i<arr[times][better]-1;i++){
            if(bases.front()==1)cnt++;
            bases.pop();bases.push(0);
          }
        }
        
        
      }
      times++;
    }
      ans=max(ans,cnt);
  }while(next_permutation(player,player+8));
  cout <<ans;
}