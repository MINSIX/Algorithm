#include<bits/stdc++.h>
using namespace std;
int T;




int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> T;
	int k;

	
		
		while (T-- > 0) {

			cin >> k;
			char cal;
			int n;
			multiset<int> ms;
		
			for (int i = 0; i < k; i++) {
				cin >> cal;
				cin >> n;
				if (cal == 'I')
				{
					ms.insert(n);
				}
				else
				{
					if (n == 1)
					{


						if (!ms.empty())
						{
							auto it = ms.end();
							it--;
							ms.erase(it);
						}
					}
					else {
						if (!ms.empty())
						{
							ms.erase(ms.begin());
						}
					}
				}
			}
			if (ms.empty())
				cout << "EMPTY" << endl;
			else {
				auto it = ms.end();
				it--;
				cout << *it << " " << *ms.begin() << endl;
			}




	}



}