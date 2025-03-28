#include<bits/stdc++.h>
using namespace std;

int main(){

 int N;
 cin >> N;
 int a;
 long long sum=1;
 for(int i=0;i<N;i++){
   cin >>a;
    sum+=a;
    sum--;
   
 }
 cout << sum;
}