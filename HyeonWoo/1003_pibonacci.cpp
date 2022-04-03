#include <iostream>
using namespace std;

void fibo(int n);

int main()
{
	int n;
	cin >> n;
	int* list = new int[n];
	for (int i = 0; i < n; i++)  cin >> list[i];

	for (int i = 0; i < n; i++)  fibo(list[i]);

	return 0;
}

void fibo(int n)
{
	if (n == 0)
	{
		cout << 1 << " " << 0 << "\n";
		return;
	}
	else if (n == 1)
	{
		cout << 0 << " " << 1 << "\n";
		return;
	}
	int* db = new int[n + 1];
	db[0] = 0;
	db[1] = 1;
	for (int i = 2; i < n + 1; i++)
		db[i] = db[i - 2] + db[i - 1];

	cout << db[n - 1] << " " << db[n] << "\n";
	delete[] db;

}
