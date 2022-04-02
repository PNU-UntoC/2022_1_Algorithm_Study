# include <iostream>

using namespace std;

bool checkNum (const int num) {
	int count = 0;

	for (int i = 1; i <= num; i++) {

		if (num % i == 0) {
			count = count + 1;
		}

	}

	if (count == 2) {
		return true;
	}
	else {
		return false;
	}

	}

int main() {

	int N = 0, num = 0,count = 0;
	bool check = false;

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> num;

		check = checkNum(num);

		if (check == true) {
			count = count + 1;
		}

	}

	cout << count;

}
