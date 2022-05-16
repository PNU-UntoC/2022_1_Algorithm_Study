#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string name;
	cin >> name;
	sort(name.begin(), name.end());
	int oddCount = 0;
	int charCount = 0;
	int i, j;
	char oddChar;
	for (i = 0; i < name.size(); i++) {
		charCount = 0;
		char temp = name[i];
		charCount++;
		for (j = i + 1; j < name.size(); j++) {
			if (temp == name[j]) {
				charCount++;
			}
			else {
				break;
			}
		}
		if (charCount % 2 == 1) {
			oddCount++;
			oddChar = temp;
		}
		i = j - 1;
	}
	if (oddCount > 1) {
		cout << "I'm Sorry Hansoo\n";
		return 0;
	}
	char palindrome[50];
	int k = 0;
	palindrome[name.size()] = '\0';

	if (oddCount == 1) {
		for (int i = 0; i < name.size() - 1; i++) {
			if (name[i] == oddChar) {
				for (j = i + 1; j < name.size(); j++) {
					name[j - 1] = name[j];
				}
				name[name.size() - 1] = oddChar;
				break;
			}
		}
	}
	for (i = 0; i < name.size(); i++) {
		if (i % 2 == 0) {
			palindrome[k] = name[i];
		}
		else {
			palindrome[name.size() - (k + 1)] = name[i];
			k++;
		}
	}

	cout << palindrome << endl;
}
