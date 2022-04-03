#include <cstdio>
#include <queue>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);

		queue<int>q, inx;
		priority_queue<int>pq;
		for (int i = 0; i < n; i++)
		{
			int a;
			scanf("%d", &a);
			q.push(a);
			pq.push(a);
			inx.push(i);
		}

		int i = 0;
		while (1)
		{
			if (pq.top() != q.front())
			{
				q.push(q.front());
				inx.push(inx.front());
			}
			else
			{
				i++;
				pq.pop();
				if (inx.front() == m) break;
			}

			q.pop();
			inx.pop();
		}

		printf("%d\n", i);
	}
	return 0;
}
