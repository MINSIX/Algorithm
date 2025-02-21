#include <bits/stdc++.h>
using namespace std;

bool check[10001];

void isPrime(){
    for (int i = 2; i < 10000; i++){
        if (!check[i]){
            for (int j = i * 2; j < 10000; j += i)
                check[j] = true;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    isPrime();
    
    while(T--){
        int a, b;
        cin >> a >> b;
        
        vector<bool> visited(10000, false);
        queue<pair<int,int>> q;
        visited[a] = true;
        q.push({a, 0});
        bool found = false;
        
        while(!q.empty()){
            int cur = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(cur == b){
                cout << steps << "\n";
                found = true;
                break;
            }
            
            string curStr = to_string(cur);
            while(curStr.size() < 4)
                curStr = "0" + curStr;
            for(int i = 0; i < 4; i++){
                char original = curStr[i];
                for(char d = '0'; d <= '9'; d++){
                    if(d == original)
                        continue;
                    curStr[i] = d;
                    int num = stoi(curStr);
                    if(num < 1000) 
                        continue;
                    if(check[num]) 
                        continue;
                    if(visited[num])
                        continue;
                    
                    visited[num] = true;
                    q.push({num, steps + 1});
                }
                curStr[i] = original; 
            }
        }
        
        if(!found)
            cout << "Impossible" << "\n";
    }
    
}
