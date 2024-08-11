#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
vector<pair<int,int>>arr;
int a;
for(int i=0;i<N;i++)
{cin >> a;
arr.push_back({a,i});
  
}
sort(arr.begin(),arr.end());
int maxi=0;
for(int i=0;i<N;i++)
{
  maxi=max(maxi,arr[i].second-i);
  
  
  
}
cout << maxi;










}