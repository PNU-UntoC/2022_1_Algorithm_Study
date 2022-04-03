#include <iostream>
#include <limits>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); // 속도 향상을 위한 코드

	int min = numeric_limits<int>::min(); // 정수의 최솟값
	int max = numeric_limits<int>::max(); // 정수의 최댓값

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (i == 0) { // 첫 번째 수를 입력받았을 때, max와 min 값을 변경해 줍니다.
			if (num > min) {
				min = num;
			}
			if (num < max) {
				max = num;
			}
		}
		else { // 그 다음 수부터, max와 min 값들을 비교하고 값을 갱신합니다.
			if (num < min) {
				min = num;
			}
			if (num > max) {
				max = num;
			}
		}
	}
	cout << min << " " << max;

	return 0;
}
