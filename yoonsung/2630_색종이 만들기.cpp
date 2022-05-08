#include <cstdio>

int arr[256][256];
int white, blue;

void dividing(int sx, int sy, int size)
{
	bool color[2] = { 0 };
	color[arr[sx][sy]] = true;

	for (int i = sx; i < sx + size; i++)
	{
		for (int j = sy; j < sy + size; j++)
		{
			if (color[arr[i][j]]==false)
			{
				size /= 2;
                
				dividing(sx, sy, size);
				dividing(sx + size, sy, size);
				dividing(sx, sy + size, size);
				dividing(sx + size, sy + size, size);

				return;
			}
		}
	}

	white += color[0];
	blue += color[1];

	return;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);

	dividing(0, 0, n);

	printf("%d %d\n", white, blue);

	return 0;
}
