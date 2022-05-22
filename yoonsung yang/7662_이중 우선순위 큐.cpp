#include <iostream>
#include <queue>
#include <map>
#include <functional>
using namespace std;

#define LL long long

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	map<LL, int>CHK;
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		priority_queue<LL>B;
		priority_queue<LL, vector<LL>, greater<LL> > S;

		while (n--)
		{
			char cal;
			LL k;
			cin >> cal >> k;

			if (cal == 'I')
			{
				CHK[k]++;
				B.push(k), S.push(k);
			}
			else
			{
				if (!CHK.empty())
				{
					if (k == -1)
					{
						while (!S.empty() && CHK[S.top()] == 0) S.pop();
						if (!S.empty())
						{
							CHK[S.top()]--;
							S.pop();
						}
					}
					else
					{
						while (!B.empty() && CHK[B.top()] == 0) B.pop();
						if (!B.empty())
						{
							CHK[B.top()]--;
							B.pop();
						}
					}
				}
			}
		}
		while (!B.empty() && CHK[B.top()] == 0) B.pop();
		while (!S.empty() && CHK[S.top()] == 0) S.pop();


		if (B.empty() || S.empty()) cout << "EMPTY\n";
		else cout << B.top() << " " << S.top() << "\n";
        
        CHK.clear();
	}
	return 0;
}
