#include<bits/stdc++.h>
using namespace std;




int main(){
  int N;
  cin >> N;
  
  vector<int> arr(N);
  int rangemin=9999,rangemax=-9999;
  for(int i=0;i<N;i++)
  {cin >>arr[i];
    rangemin=min(arr[i],rangemin);
    rangemax=max(arr[i],rangemax);
    
  }
  
    double sum=0;
  for(int i=0;i<N;i++)
  {
    sum+=arr[i];
  }
  double avg = (double)sum / (double)N;
  cout << (long long)round(avg) << "\n";
  sort(arr.begin(),arr.end());
  cout << arr[N/2]<<endl;
  
  vector<int> freq(8002,0);
  for(int i=0;i<N;i++)
  {
    freq[arr[i]+4000]++;
  }
  
  int flag=1;
  int nowfreq=0;
  int times=0;
  for(int i=0;i<8002;i++){
  if(freq[i]==0)
  continue;
    if(times>freq[i])
    continue;
    if(flag==1&&(times==freq[i])){
      flag=2;
      nowfreq=i;
       
      continue;
      
    }
    if(times<freq[i])
    {times=freq[i];
    flag=1;
    nowfreq=i;
    }
  }
  cout << nowfreq-4000<<endl;
  
  cout << rangemax-rangemin;


}