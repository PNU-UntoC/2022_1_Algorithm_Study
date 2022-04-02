# include <iostream>

using namespace std;

bool checknums(int nums) {

	int a1 = 0, a2 = 0, a3 = 0;

	if (nums < 100) {
		return true;
	}

	a1 = nums / 100;
	a2 = (nums % 100) / 10;
	a3 = nums % 10;

	if ((a1 - a2) == (a2 - a3)) {
		return true;
	}
	else {
		return false;
	}
}

int main() {

	int num = 0, count = 0;
	bool checkresult;

	cin >> num;

	int numarr[] = { 0, };

	for (int i = 0; i < num; i++) {

		checkresult = checknums(i + 1);

		if (checkresult == true) {
			count = count + 1;
		}

	}

	cout << count;

}
