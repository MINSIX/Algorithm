#include<bits/stdc++.h>
using namespace std;

int main(){
  
  string a,c;
  double b;
  double sum=0;
  int realsum=0;
  for(int i=0;i<20;i++){
    cin >> a>>b>>c;
    if(c=="P")
    continue;
    
    if(c=="A+"){
    sum+=b*4.5;
      realsum+=b;
    continue;
      
    }
    
    if(c=="A0")
   { sum+=b*4.0;
    
      realsum+=b;
  continue;
    
     
   }
    if(c=="B+")
    {sum+=b*3.5;
     realsum+=b;
  continue;
    
      }  if(c=="B0")
    {sum+=b*3.0;
      realsum+=b;
  continue;
    
    }if(c=="C+")
    {sum+=b*2.5;
      realsum+=b;
  continue;
    
    }if(c=="C0")
    {sum+=b*2.0;
      realsum+=b;
  continue;
    
    }
    if(c=="D+")
    {sum+=b*1.5;
      realsum+=b;
  continue;
    
    }if(c=="D0")
    {sum+=b*1.0;
      realsum+=b;
  continue;

    
    }
    if(c=="F")
    {sum+=b*0.0;
      realsum+=b;
  continue;

    
    }
  }
  cout << sum/(double)realsum;
}