#include <iostream>
using namespace std;
int d[1000000] = {0,}; //정수 배열 생성

int goToOne(int n) {
	if (n == 1) // n의 값이 1이면, 0을 반환
		return 0;
	if (d[n] > 0) // 초기 값이 아니라면, 리턴
		return d[n];
	d[n] = goToOne(n - 1) + 1; // 1을 빼는 경우
	if (n % 2 == 0) { // 2로 나누는 경우
		int tmp = goToOne(n / 2) + 1;
		if (d[n] > tmp) {
			d[n] = tmp;
		}
	}
	if (n % 3 == 0) { // 3으로 나누는 경우
		int tmp = goToOne(n / 3) + 1;
		if (d[n] > tmp) {
			d[n] = tmp;
		}
	}
	return d[n]; // 세 가지 경우 중 최소의 값을 리턴
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	cout << goToOne(n);
}
