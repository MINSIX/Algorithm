#include <bits/stdc++.h>
using namespace std;
int N, K, X, res;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	queue<int> q;
	cin >> N >> K;

	// n명 번호를 부여하여 큐에 넣기
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}

	cout << "<";
	// 요세푸스 순열 알고리즘
	while (!q.empty()) {
		for (int i = 1; i < K; i++) {
			X = q.front();
			q.pop();
			q.push(X);
		}
		res = q.front();
		cout << res;


		q.pop();
		if (!q.empty())
			cout << ", ";

	}cout << ">";

	return 0;
}
