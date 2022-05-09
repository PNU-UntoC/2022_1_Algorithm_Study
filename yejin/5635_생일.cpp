#include <iostream>
#include <string>
#include <vector>
using namespace std;

class student {
private:
	string name;
	int day = 0, month = 0, year = 0;

public:
	student() {}
	student(string name, int day, int month, int year)
		: day(day), month(month), year(year), name(name) {}

	const bool operator>(const student& s) const {
		if (year < s.year) return true;
		else if (year > s.year) return false;

		if (month < s.month) return true;
		else if (month > s.month) return false;

		if (day < s.day) return true;
		else return false;
	}

	const string get_name() { return name; }
};

int main() {
	int n;
	cin >> n;

	vector<student> vec;

	for (int i = 0; i < n; i++) {
		string name;
		int day, month, year;
		cin >> name >> day >> month >> year;

		vec.emplace_back(name, day, month, year);
	}

	int min = 0, max = 0;
	for (int i = 0; i < n; i++) {
		if (vec[min] > vec[i])
			min = i;

		if (vec[i] > vec[max])
			max = i;
	}

	cout << vec[min].get_name() << endl;
	cout << vec[max].get_name() << endl;

	return 0;
}
