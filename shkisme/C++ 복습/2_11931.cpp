#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); // 속도 향상을 위한 코드

	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<int>()); // 내림차순 정렬

	for (auto i : v) {
		cout << i << "\n";
	}

	return 0;
}
