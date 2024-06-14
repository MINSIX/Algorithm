#include<bits/stdc++.h>
using namespace std;

int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int dy[8] = { -1,-1,-1,0,0,1,1,1 };



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	int x, y;
	vector<vector<char>>arr(20, vector<char>(20));
	int sv=-1;
	int flag = 0;
	int now = 1;
	int realsv = -1;
	for(int i=0;i<T;i++)
	{
		cin >> x >> y;
		if (now == 1)
		{
			arr[x][y] = 'B';
			now = 0;
		}
		else {
			arr[x][y] = 'W';
			now = 1;
		}
		
		for (int t = 0; t <8; t++) {
			int cnt = 0;
			for (int j = -4; j < 5; j++) {
				if (j == 0)
					continue;
				int xx = x + j * dx[t];
				int yy = y + j * dy[t];
				if (xx > 19 || yy > 19 || xx < 1 || yy < 1)
					break;

				if (arr[x][y] != arr[xx][yy])
					if (cnt == 0)
						continue;
					else
						break;


				cnt++;
				
			}
			if (cnt == 4&&flag==0) {

				sv = i + 1;
				flag = 1;

			}
			if (flag == 1) {
				if (cnt == 5)
				{
					sv = -1;
					flag = 0;
				}
				else {
					realsv = sv;
					flag = 2;
				}
		}
		
		}

	}
	cout << realsv << endl;

}