#include<bits/stdc++.h>


using namespace std;

int solution(vector<vector<int>> sizes) {
    int a=0;
    for(int i=0;i<sizes.size();i++){
        
        if(sizes[i][0]<sizes[i][1])
            swap(sizes[i][0],sizes[i][1]);
        
      
    }
    
    for(int i=0;i<sizes.size();i++){
     a=max(a,sizes[i][0]);   
}
        int b=0;
    for(int i=0;i<sizes.size();i++){

     b=max(b,sizes[i][1]);   
    }
    return a*b;
}