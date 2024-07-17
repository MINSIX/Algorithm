#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    int now, pre;
       priority_queue<int> pq;
  vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> now;
        now -= i;
        pq.push(now);
        
        if (pq.top() > now) {
           
            pq.pop();
            pq.push(now);
        }
      arr[i]=pq.top();
      
    }
  
  for(int i=N-2;i>-1;i--)
{ 
  if(arr[i]>arr[i+1])
  arr[i]=arr[i+1];
  
}
for (int i = 0; i < N; i++) {
  cout<< arr[i]+i<<"\n";
  
}
return 0;
}
