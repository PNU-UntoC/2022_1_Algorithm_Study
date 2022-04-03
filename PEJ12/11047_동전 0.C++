#include <iostream>

using namespace std;


int main(void) {
    int num, money;
    cin >> num >> money;
    int* array = new int[num];

    for (int i = 0; i < num; i++) {
        cin >> array[i];
    }
    int count = 0;

    for (int i = num - 1; i >= 0; i--) {
        if (money >= array[i]) {
            int subCount = money / array[i];
            count += subCount;
            money -= subCount * array[i];
        }
        if (money == 0) {
            break;
        }
    }
    cout << count;
    delete[] array;
    return 0;
}
