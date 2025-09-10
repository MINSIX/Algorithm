#include<bits/stdc++.h>
using namespace std;




int main(){

  int n;
  cin >> n;
  stack<int>st;
  vector<char> answer;
  
  int now=1;
  for(int i=0;i<n;i++){
    int a;
    cin >>a;
    
       while (now <= a) {
            st.push(now++);
            answer.push_back('+');
        }
         if (!st.empty() && st.top() == a) {
            st.pop();
            answer.push_back('-');
        } else {
            cout << "NO\n";
            return 0;
        }
    
  }

  for(int i=0;i<answer.size();i++)
  cout << answer[i]<<"\n";

}