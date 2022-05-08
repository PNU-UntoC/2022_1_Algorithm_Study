#include <cstdio>
#define INF 2e9
int main()
{
	int n, m, b;
	int arr[260] = { 0 };
	scanf("%d%d%d", &n, &m, &b);

	for (int i = 0; i < n * m; i++)
	{
		int a;
		scanf("%d", &a);
		arr[a]++;
	}

	int ans_t = INF, ans_h;
	for (int i = 256; i >= 0; i--)
	{
		int time = 0, block = b;

		for (int j = 0; j < i; j++)
		{
			int take = i - j;
			time += take * arr[j];
			block -= take * arr[j];
		}
		for (int j = i + 1; j <= 256; j++)
		{
			int take = j - i;
			time += 2 * take * arr[j];
			block += take * arr[j];
		}

		if (block >= 0 && time < ans_t) ans_t = time, ans_h = i;
	}

	printf("%d %d\n", ans_t, ans_h);

	return 0;
}
