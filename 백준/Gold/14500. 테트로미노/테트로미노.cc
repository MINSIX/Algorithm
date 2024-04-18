#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int N, M;
const int INF = 1e9;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N>>M;
	vector<vector<int>>board(N + 1, vector<int>(M + 1));

	int maxi = 0;
	int sum = 0;
	int sumupL = 0;
	int sumdownL = 0;

	int sumup = 0;
	int sumdown = 0;

	int NEMO = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}
	
	for (int i = 1; i <= N; i++) {

		for (int j = 1; j <= M; j++) {
			for (int x = i; x <= i + 3; x++) {
				if (x > N) {
					sum = 0;
					break;
				}

				sum += board[x][j];

			}
			maxi = max(maxi, sum);

			sum = 0;
			for (int y = j; y <= j + 3; y++) {
				if (y > M) {
					sum = 0;
					break;
				}

				sum += board[i][y];

			}

			maxi = max(maxi, sum);

			sum = 0;
			if (i == N)
				continue;

			for (int x = i; x <= i + 1; x++) {
				if (x > N) {

					sum = 0;
			
					break;
				}
				for (int y = j; y <= j + 2; y++) {
					if (y > M)
					{

						sum = 0;
						break;
					}
					if (x == i) {
						sumupL += board[x][y];


					}
					if (x == i + 1) {
						sumdownL += board[x][y];
						

					}
					sum += board[x][y];
					if (y ==j + 2)
						continue;
					NEMO += board[x][y];
				}

			}
			if (sum != 0) {
				
				sumup = sum - board[i][j] - board[i + 1][j + 2];
				sumdown = sum - board[i][j + 2] - board[i + 1][j];
				sum = 0;
				maxi = max(sumdown, maxi);
				maxi = max(sumup, maxi);
			}
			if (sumupL != 0 && j + 2 <= M && i + 1 <= N)
			{
				maxi = max(sumupL + board[i + 1][j + 0], maxi);

				maxi = max(sumupL + board[i + 1][j + 1], maxi);

				maxi = max(sumupL + board[i + 1][j + 2], maxi);
			}if (sumdownL != 0 && j + 2 <= M)
			{
				maxi = max(sumdownL + board[i][j], maxi);
				maxi = max(sumdownL + board[i][j + 1], maxi);
				maxi = max(sumdownL + board[i][j + 2], maxi);
			}if (NEMO != 0) {
				maxi = max(NEMO, maxi);
			}



			sumupL = 0;
			sumdownL = 0;

			sum = 0;
			sumup = 0;
			sumdown = 0;
			NEMO = 0;
			if (i == N - 1)
				continue;

			for (int x = i; x <= i + 2; x++) {
				if (x > N) {
				
					sum = 0;
						NEMO = 0;

					break;
				}
				for (int y = j; y <= j + 1; y++) {
					if (y > M)
					{
						
						sum = 0;
				
						NEMO = 0;
						break;
					}
					if (j == y) {
						sumupL += board[x][y];

					}
					if (y == j + 1) {
						
						sumdownL += board[x][y];
							}
					sum += board[x][y];

					
					

				

				}
				
			}
			if (sumupL != 0 && j + 1 <= M && i + 2 <= N)
			{

				maxi = max(sumupL + board[i][j + 1], maxi);
				maxi = max(sumupL + board[i + 1][j + 1], maxi);
				maxi = max(sumupL + board[i + 2][j + 1], maxi);

			}
			if (sumdownL != 0 && i + 2 <= N) {
				maxi = max(sumdownL + board[i][j], maxi);
				maxi = max(sumdownL + board[i + 1][j], maxi);
				maxi = max(sumdownL + board[i + 2][j], maxi);

			}
			
			if(sum!=0){
			
			sumup = sum - board[i][j] - board[i + 2][j + 1];
			sumdown = sum - board[i][j + 1] - board[i + 2][j];
			sum = 0;
			maxi = max(sumup, maxi);
			maxi = max(sumdown, maxi);
			}
	
			sumupL = 0;
			sumdownL = 0;

			sum = 0;
			sumup = 0;
			sumdown = 0;
			NEMO = 0;
			
			
		}
	
	}


	cout << maxi << endl;


}
