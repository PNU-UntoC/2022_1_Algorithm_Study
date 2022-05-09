#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main() {
	int limit;
	int enrollNum;
	cin >> limit >> enrollNum;

	vector<string> enrollList;
	string schoolID;
	for (int i = 0; i < enrollNum; i++) {
		cin >> schoolID;
		enrollList.push_back(schoolID);
	}
	set<string> s;
	vector<string> successList;
	set<string>::iterator it;
	for (int i = enrollNum - 1; i >= 0; i--) {
		schoolID = enrollList[i];
		it = s.find(schoolID);
		if (it == s.end()) {
			s.insert(schoolID);
			successList.push_back(schoolID);
		}
	}
	int size = successList.size();
	for (int i = size - 1; (i >= size - limit) && i >= 0; i--) {
		cout << successList[i] << '\n';
	}

	return 0;
}
