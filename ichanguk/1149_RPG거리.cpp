#include <iostream>
using namespace std;

int lowCost(const int xCost, const int yCost)
{
	return (xCost < yCost) ? xCost : yCost;
}

int main()
{
	int RGB[3];
	int iMinCost[1000][3];
	
	int N;
	cin >> N;
	cin >> iMinCost[0][0] >> iMinCost[0][1] >> iMinCost[0][2];

	for (int i = 1; i < N; i++) {
		cin >> RGB[0] >> RGB[1] >> RGB[2];
		iMinCost[i][0] = RGB[0] + lowCost(iMinCost[i - 1][1], iMinCost[i - 1][2]);
		iMinCost[i][1] = RGB[1] + lowCost(iMinCost[i - 1][0], iMinCost[i - 1][2]);
		iMinCost[i][2] = RGB[2] + lowCost(iMinCost[i - 1][0], iMinCost[i - 1][1]);
	}

	cout << lowCost(iMinCost[N - 1][0], lowCost(iMinCost[N - 1][1], iMinCost[N - 1][2])) << endl;
	return 0;
}
