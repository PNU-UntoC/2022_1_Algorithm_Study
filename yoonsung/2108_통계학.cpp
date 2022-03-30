#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#define Max(a,b) (a>b?a:b)
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> arr(n, 0), chk(8005, 0);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        chk[arr[i] + 4000]++;
    }

    sort(arr.begin(), arr.end());

    int sum = 0, MAX = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        MAX = Max(chk[arr[i] + 4000], MAX);
    }
    float s = round(float(sum) / n);

    queue<int>q;
    for (int i = 0; i < 8001; i++)
        if (chk[i] == MAX) q.push(i - 4000);

    if (q.size() > 1) q.pop();
    
    printf("%d %d %d %d\n", (int)s, arr[n / 2], q.front(), arr[n - 1] - arr[0]);
    return 0;
}
