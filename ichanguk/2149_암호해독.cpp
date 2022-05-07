#include <iostream>
#include <string>
using namespace std;

int main() {
		string key;
		string cipher;
		string cipherMatrix[10];

		cin >> key;
		cin >> cipher;
		int keySize = key.size();
		int cipherDivKey = cipher.size() / keySize;
		for (int i = 0; i < keySize; i++) {
			cipherMatrix[i] = cipher.substr(i * cipherDivKey, cipherDivKey);
		}

		int swapCount = 0;
		int indexX[20];
		int indexY[20];
		for (int i = 0; i < keySize - 1; i++) {
			int minIndex = i;
			for (int j = i + 1; j < keySize; j++) {
				if (key[minIndex] > key[j]) {
					minIndex = j;
				}
			}
			if (minIndex != i) {
				swap(key[i], key[minIndex]);
				indexX[swapCount] = i;
				indexY[swapCount] = minIndex;
				swapCount++;
				if (key[minIndex] == key[minIndex - 1]) {
					for (int j = i + 1; j < minIndex; j++) {
						indexX[swapCount] = j;
						indexY[swapCount] = minIndex;
						swapCount++;
					}
				}
			}
		}

		for (int i = swapCount - 1; i >= 0; i--) {
			swap(cipherMatrix[indexX[i]], cipherMatrix[indexY[i]]);
		}

		for (int i = 0; i < cipherDivKey; i++) {
			for (int j = 0; j < keySize; j++) {
				cout << cipherMatrix[j][i];
			}
		}
	return 0;
}
