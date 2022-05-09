#include <iostream>
using namespace std;

void dfs(bool** ground, int maxX, int maxY, int x, int y);
int count(bool** ground, int maxX, int maxY);

int main()
{
    int n;
    cin >> n;
    int* results = new int[n];
    for (int i = 0; i < n; i++) 
    {
        int x, y, c;
        cin >> x >> y >> c;
        bool** ground = new bool*[y];
        for (int j = 0; j < y; j++)
        {
            ground[j] = new bool[x];
            for (int k = 0; k < x; k++)
                ground[j][k] = false;
        }
        for (int j = 0; j < c; j++)
        {
            int px, py;
            cin >> px >> py;
            ground[py][px] = true;
        }
        results[i] = count(ground, x - 1, y - 1);
    }

    for (int i = 0; i < n; i++)
        cout << results[i] << "\n";
}

void dfs(bool** ground, int maxX,int maxY,int x, int y) 
{
    if (!ground[y][x])
        return;

    ground[y][x] = false;

    if (y != 0)
        dfs(ground, maxX, maxY, x, y - 1);
    if (y != maxY)
        dfs(ground, maxX, maxY, x, y + 1);
    if (x != 0)
        dfs(ground, maxX, maxY, x - 1, y);
    if (x != maxX)
        dfs(ground, maxX, maxY, x + 1, y);

}

int count(bool** ground, int maxX, int maxY)
{
    int result = 0;
    for(int y=0;y<=maxY;y++)
        for (int x = 0; x <= maxX; x++)
        {
            if (ground[y][x])
            {
                result++;
                dfs(ground, maxX, maxY, x, y);
            }
        }

    return result;

}
