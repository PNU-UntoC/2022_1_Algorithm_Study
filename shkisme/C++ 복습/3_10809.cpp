#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); // 속도 향상을 위한 코드

	string str;
	cin >> str;

	int alpha[26];
	fill_n(alpha, 26, -1); // 배열의 값을 -1로 초기화

	int index = 0;
	for (int i = 0; i < str.length();i++) { // string class의 size_t length() 함수
		if (alpha[str[i] - 97] < 0) {
			alpha[str[i] - 97] = index;
		}
		index++;
	}
	for (auto i : alpha) {
		cout << i << " ";
	}
	return 0;
}
