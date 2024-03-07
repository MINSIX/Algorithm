#include<bits/stdc++.h>
using namespace std;

long long solution(int r1, int r2) {
      long long answer = 0;
     long long dd2=pow(r2,2);
     long long dd1=pow(r1,2);
    for(int i=-1*r2;i<=r2;i++){
       long long ii = pow(i,2);
        long long j = sqrt(dd2-ii);
           answer+=j*2+1; 
    }
   
   
    for(int i=-1*r1;i<=r1;i++){
       long long ii = pow(i,2);
        long long j = sqrt(dd1-ii);
           answer-=j*2+1; 

        if(j*j+ii==dd1)
            answer+=2;
    }

   answer-=2;
  
    return answer;
}