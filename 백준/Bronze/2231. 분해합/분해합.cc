#include <iostream>
using namespace std;

int main() {

    int N;
    cin >> N;
    
    for(int i=1;i<=1000000;i++){
      int t=i,sum=0;
      while(t>0){
        sum+=t%10;
        t/=10;
      }
      sum+=i;
      if(sum==N){
        cout << i;
        return 0;
      }
    }
    cout<< 0;


}
