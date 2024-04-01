#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, m;


vector<int> group;

int getGroup(int n) {
    if (group[n] == n)
        return n;
    return group[n] = getGroup(group[n]);
}

void joinGroup(int a, int b) {
    a = getGroup(a);
    b = getGroup(b);
    if (a > b)
        swap(a, b);
    group[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    group.resize(n + 1);
    for (int i = 1; i <= n; i++)
        group[i] = i;
    int a, b;

    int sv = 0;
    int flag = 0;
  for(int i=1;i<=m;i++)
    {
        cin >> a >> b;

        if (getGroup(a) == getGroup(b)&&flag==0)
        {
           
            sv = i;
            flag = 1;
        }joinGroup(a, b);
   }
 
    cout << sv << endl;



}



