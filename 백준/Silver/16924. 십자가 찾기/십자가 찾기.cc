#include<bits/stdc++.h>
using namespace std;
int N, M;

char cross1x[5] = { -1,0,0,0,1 };
char cross1y[5] = { 0,-1,0,1,0 };

vector<vector<int>> sv;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    vector<vector<char>> collectBoard(N, vector<char>(M));

    vector<vector<char>> compareBoard(N, vector<char>(M, '.'));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> collectBoard[i][j];

        }
 
    int q = min(N/2,M/2);
    while(q>0){
  
    for (int i = q; i < N - q; i++) {
        for (int j = q; j < M - q; j++) {
            int flag = 0;
            for (int k = 0; k < sizeof(cross1x); k++)
            {
                if (collectBoard[i + q*cross1x[k]][j + q*cross1y[k]] == '.')
                {

                    flag = 1;
                    break;
                }

                if (flag == 1)
                    break;
            }

            if (flag == 0)
            {
                int check = q;
                while (check-- > 0) {
                    for (int dx = 0; dx < sizeof(cross1x); dx++)
                    {
                        for (int k = 0; k < sizeof(cross1x); k++)
                        {
                            if (collectBoard[i + check * cross1x[k]][j + check * cross1y[k]] == '.')
                            {
                                flag = 1;
                                break;
                            }
                        }
                        if (flag == 1)
                            break;
                    }
                }
                if (flag == 0) {
                    for (int dx = 0; dx < sizeof(cross1x); dx++)
                    {
                        compareBoard[i + q * cross1x[dx]][j + q * cross1y[dx]] = collectBoard[i + q * cross1x[dx]][j + q * cross1y[dx]];
                    }
                    sv.push_back({ i,j,q });
                }
            }
            flag = 0;
        }
    }
    q--;
    }
 
    sort(sv.begin(), sv.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0] && a[1] == b[1])
            return a[2] > b[2];
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
        });

    auto it = unique(sv.begin(), sv.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] == b[0] && a[1] == b[1];
        });
    sv.erase(it, sv.end());
    int flag = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {

            if (compareBoard[i][j] != collectBoard[i][j])
            {

                flag = 1;
                break;
            }
        }
        if (flag == 1)
            break;
    }

    if (flag == 1)
        cout << -1;
    else {
        cout << sv.size() << endl;
        for (auto& i : sv) {
            cout << i[0] + 1 << " " << i[1] + 1 << " " << i[2] << endl;
        }
       
    }

    return 0;
}
