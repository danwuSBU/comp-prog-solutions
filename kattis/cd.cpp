//https://open.kattis.com/problems/cd
#include <iostream>
#include <unordered_set>

using namespace std;
/*input
3 3
1
2
3
1
2
4
0 0
*/
int main()
{
	int cd;
	int j1;
	int j2;
	cin >> j1;
	cin >> j2;

	while (j1 != 0 && j2 != 0)
	{
		unordered_set<int> set;
		for (int i = 0; i < j1; i++)
		{
			cin >> cd;
			set.insert(cd);
		}
		int count = 0;
		for (int i = 0; i < j2; i++)
		{
			cin >> cd;
			if (set.count(cd))
			{
				count++;
			}
		}
		cout << count << endl;
		cin >> j1;
		cin >> j2;
	}

	return 0;
}