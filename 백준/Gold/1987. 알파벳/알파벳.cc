#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int N, K;


char arr[22][22] = {  };


int dx[4] = { -1,0,0,1 };
int dy[4] = { 0 ,-1,1,0 };


int cnt = 1;
int us[27] = { 0 };
void cal(int x, int y,int t) {

   
    if (t > cnt) {
        cnt = t;
    }
    for (int i = 0; i < 4; i++) {
        int xx = dx[i] + x;
        int yy = dy[i] + y;
        int u = t;
        if ((xx >= 0 && yy >= 0) && (xx < N && yy < K))
        {
            if (us[arr[xx][yy] - 'A']==0) {
                us[arr[xx][yy] - 'A'] = 1;
                 u++;
                cal(xx, yy, u);

                us[arr[xx][yy] - 'A'] = 0;
               
            }
  
        }
       
    }


}


int main() {
 
        cin >> N>>K;
        getchar();
        for (int i = 0; i < N; i++) {
            scanf("%s", arr[i]);
        }
        us[arr[0][0] - 'A'] = true;
        cal(0, 0,1);
        cout << cnt << endl;
    return 0;
}



