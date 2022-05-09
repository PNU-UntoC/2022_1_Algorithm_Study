#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	map<string, string> notePad;
	string address;
	string password;
	for (int i = 0; i < N; i++) {
		cin >> address >> password;
		notePad[address] = password;
	}
	for (int i = 0; i < M; i++) {
		cin >> address;
		cout << notePad[address] << '\n';
	}
	return 0;
}
