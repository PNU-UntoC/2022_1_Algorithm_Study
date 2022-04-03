#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); // 속도 향상을 위한 코드

	int n, m;
	cin >> n >> m;

	vector<string> noHear(n); // 듣도 못한 사람을 저장할 배열
	vector<string> noSee(m); // 보도 못한 사람을 저장할 배열
	map<string, int> list; // 0으로 초기화 되어 있는 map
	int noHearAndnoSee = 0; // 듣도 보도 못한 사람의 수

	for (int i = 0; i < n; i++) {
		cin >> noHear[i];
		list[noHear[i]] = 1;
	}
	for (int i = 0; i < m; i++) {
		cin >> noSee[i];
		if (list[noSee[i]] == 1) { // 보도 못한 사람 중, 듣도 못한 사람이 있을 경우
			noHearAndnoSee++;
			list[noSee[i]] = 2;
		}
	}
	cout << noHearAndnoSee << "\n";
	for (auto tmp : list) {
		if (tmp.second == 2) {
			cout << tmp.first << "\n";
		}
	}
	return 0;
}
