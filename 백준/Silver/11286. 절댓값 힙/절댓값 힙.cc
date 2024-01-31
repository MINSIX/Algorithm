#include<bits/stdc++.h>
using namespace std;

int N,M;
struct cmp{
    bool operator()(int n1, int n2) {
        if (abs(n1) > abs(n2))
            return true;
        else if (abs(n1) == abs(n2))
            if (n1 > n2)
                return true;
            else return false;
        return false;
    }

};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N ;
    int s;
    priority_queue<int,vector<int>,cmp> q;
    for (int i = 0; i < N; i++) {
        cin >> s;
        if (s != 0)
            q.push(s);
        else if(!q.empty())
        {
            cout << q.top() << endl;
            q.pop();
        }
        else {
            cout << 0 << endl;
        }

  }
    return 0;
}



