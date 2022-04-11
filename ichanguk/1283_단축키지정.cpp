#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	int N;
	cin >> N;
	cin.ignore();
	string shortCut;
	vector<string> ans;
	int wasRegisterd['z' - 'a' + 1] = { 0, };
	
	for (int i = 0; i < N; i++) {
		getline(cin, shortCut);
		int whereWordStart[5] = { 0, };
		int cur = 1;
		for (int j = 1; j < shortCut.size(); j++) {
			if (shortCut[j - 1] == ' ') {
				whereWordStart[cur++] = j;
			}
		}
		char temp;
		bool success = false;
		for (int j = 0; j < 5; j++) {
			cur = whereWordStart[j];
			if (cur == 0 && j != 0) {
				break;
			}
			if (shortCut[cur] >= 'A' && shortCut[cur] <= 'Z') {
				temp = shortCut[cur] + 'a' - 'A';
			}
			else {
				temp = shortCut[cur];
			}
			if (wasRegisterd[temp - 'a'] == 0) {
				wasRegisterd[temp - 'a'] = 1;
				shortCut.insert(cur, "[");
				shortCut.insert(cur + 2, "]");
				ans.push_back(shortCut);
				success = true;
				break;
			}
		}
		if (success) {
			continue;
		}

		for (int j = 1; j < shortCut.size(); j++) {
			if (shortCut[j] == ' ') {
				continue;
			}
			if (shortCut[j] >= 'A' && shortCut[j] <= 'Z') {
				temp = shortCut[j] + 'a' - 'A';
			}
			else {
				temp = shortCut[j];
			}
			if (wasRegisterd[temp - 'a'] == 0) {
				wasRegisterd[temp - 'a'] = 1;
				shortCut.insert(j, "[");
				shortCut.insert(j + 2, "]");
				ans.push_back(shortCut);
				success = true;
				break;
			}
		}
		if (success) {
			continue;
		}

		ans.push_back(shortCut);
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << endl;
	}
}
