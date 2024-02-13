#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
int N,M;

int arr[100001] = {0, };
int cal() {
    queue<int> q;
    q.push(N);
    int now = N;
    if (N == M) {
        
        return 0 ;
    }

    while (!q.empty())
    {
        now = q.front();
        q.pop();
        for (int cnt : {now +1, now *2 , now-1}) {
            if (cnt < 0 || cnt>100000) 
                continue;
                if (arr[cnt] != 0 && arr[cnt] <= arr[now] + 1)
                    continue;
                
                
                arr[cnt] = arr[now] + 1;
                
                
                q.push(cnt);
         }

       
    }
    return arr[M];

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N>>M;
    arr[N] = 0;
    
   
    cout <<cal()<<endl;

    return 0;
}