#include<bits/stdc++.h>

using namespace std;
int N;
vector<int> inorder,postorder;
map<int,int> idx;

void getresult(int in_s, int in_e, int po_s,int po_e){
  if(in_s>in_e||po_s>po_e) return;
  
  
  int root = postorder[po_e];  
    cout << root << " ";  

  int root_idx = idx[root]; 
  int left_size = root_idx - in_s;  
  
  getresult(in_s,root_idx-1,po_s,po_s+left_size-1);
  getresult(root_idx+1,in_e,po_s+left_size,po_e-1);
  
}





int main(){
  
  cin >> N;
  int a;
  for(int i=0;i<N;i++)
  {cin >> a;
  inorder.push_back(a);
    
  }
  
  for(int i=0;i<N;i++)
  {cin >> a;
  postorder.push_back(a);
    
  }
  for (int i = 0; i < N; i++) 
       idx[inorder[i]] = i;
  
  getresult(0,N-1,0,N-1);
  
  
  
}