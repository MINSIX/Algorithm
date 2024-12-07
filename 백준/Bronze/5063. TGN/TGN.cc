#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int N;
  cin >> N;
  while(N--)
    {
      int a,b,c;
      cin >> a>>b>>c;
      int total = b-c-a;
      
      if(total>0)
      cout << "advertise\n";
      else if(total==0)
      cout << "does not matter\n";
      else
      cout << "do not advertise\n";
      
    }
}