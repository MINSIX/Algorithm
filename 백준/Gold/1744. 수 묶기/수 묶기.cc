#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  vector<int> nega;
  vector<int> posi;
  int a;
  int zerocnt = 0;
  cin >> N;
  for(int i = 0; i < N; i++)
  {
    cin >> a;
    if(a < 0)
      nega.push_back(a);
    else if(a > 0)
      posi.push_back(a);
    else
      zerocnt++;
  }
  sort(nega.begin(), nega.end());
  sort(posi.begin(), posi.end(), greater<int>());
  
  int result = 0;
  if(nega.size() % 2 == 0)
  {
    for(int i = 0; i < nega.size(); i += 2){
      result += nega[i] * nega[i+1];
    }
  }
  else {
    for(int i = 0; i < nega.size() - 1; i += 2){
      result += nega[i] * nega[i+1];
    }
    if(zerocnt == 0)
      result += nega[nega.size()-1];
  }
  
  if(posi.size() % 2 == 0)
  {
    for(int i = 0; i < posi.size(); i += 2){
      if(posi[i] != 1 && posi[i+1] != 1)
        result += posi[i] * posi[i+1];
      else
        result += posi[i] + posi[i+1];
    }
  }
  else {
    for(int i = 0; i < posi.size() - 1; i += 2){
      if(posi[i] != 1 && posi[i+1] != 1)
        result += posi[i] * posi[i+1];
      else
        result += posi[i] + posi[i+1];
    }
    result += posi[posi.size()-1];
  }
  
  cout << result;
}
