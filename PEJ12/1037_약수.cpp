#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int num;
	cin >> num;
	vector<int>vec(num);
	for (int i = 0; i < vec.size(); i++) {
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());
	cout << vec[0] * vec[num - 1];
	return 0;
}
