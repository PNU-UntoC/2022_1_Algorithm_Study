#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<int> road;
	int N, M;
	cin >> N >> M;
	int temp;
	int count = 0;
	cin >> temp;
	road.push_back(temp);
	if (temp) {
		count++;
	}
	for (int i = 1; i < N; i++) {
		cin >> temp;
		road.push_back(temp);
		if (road[i - 1] == 0 && temp) {
			count++;
		}
	}
	int trial, spaceNum;
	if (N == 1) {
		for (int i = 0; i < M; i++) {
			cin >> trial;
			if (trial) {
				cin >> spaceNum;
				if (road[0]) {
					road[0] = 1;
					count++;
				}
			}
			else {
				cout << count << '\n';
			}
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> trial;
		switch (trial) {
		case 0:
			cout << count << '\n';
			break;
		case 1:
			cin >> spaceNum;
			if (road[spaceNum - 1]) {
				break;
			}
			
			road[spaceNum - 1] = 1;

			if (spaceNum == 1) {
				if (road[spaceNum] == 0) {
					count++;
				}
			}
			else if (spaceNum == N) {
				if (road[spaceNum - 2] == 0) {
					count++;
				}
			}
			else {
				if (road[spaceNum - 2] == 0 && road[spaceNum] == 0) {
					count++;
				}
				if (road[spaceNum - 2] && road[spaceNum]) {
					count--;
				}
			}
			break;
		}
	}
	return 0;
}
