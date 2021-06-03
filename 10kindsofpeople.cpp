//https://open.kattis.com/problems/10kindsofpeople
#include <iostream>
#include <vector>

using namespace std;

class union_find
{
	int* id, cnt, * sz;
public:
	// Create an empty union find data structure with N isolated sets.
	union_find(int N) {
		cnt = N; id = new int[N]; sz = new int[N];
		for (int i = 0; i < N; i++)  id[i] = i, sz[i] = 1;
	}
	~union_find() { delete[] id; delete[] sz; }

	// Return the id of component corresponding to object p.
	int find(int p) {
		int root = p;
		while (root != id[root])    root = id[root];
		while (p != root) { int newp = id[p]; id[p] = root; p = newp; }
		return root;
	}
	// Replace sets containing x and y with their union.
	void merge(int x, int y) {
		int i = find(x); int j = find(y); if (i == j) return;
		// make smaller root point to larger one
		if (sz[i] < sz[j]) { id[i] = j, sz[j] += sz[i]; }
		else { id[j] = i, sz[i] += sz[j]; }
		cnt--;
	}
	// Are objects x and y in the same set?
	bool connected(int x, int y) { return find(x) == find(y); }
	// Return the number of disjoint sets.
	int count() { return cnt; }
};

int main()
{
	int r, c;
	cin >> r;
	cin >> c;

	union_find uf = union_find(r * c);

	vector<string> board(r);
	for (int i = 0; i < r; i++)
	{
		cin >> board[i];
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			int id = i * c + j;
			if (i > 0)
			{
				int topid = (i - 1) * c + j;
				if (board[i][j] == board[i - 1][j])
				{
					uf.merge(topid, id);
				}
			}
			if (j > 0)
			{
				int leftid = id - 1;
				if (board[i][j] == board[i][j - 1])
				{
					uf.merge(leftid, id);
				}
			}
		}
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int sx, sy, ex, ey;
		cin >> sx;
		cin >> sy;
		cin >> ex;
		cin >> ey;
		sx -= 1;
		sy -= 1;
		ex -= 1;
		ey -= 1;
		
		//cout << uf.find(sx * c + sy) << endl;
		//cout << uf.find(ex * c + ey) << endl;

		if (board[sx][sy] != board[ex][ey])
		{
			cout << "neither" << endl;
			continue;
		}
		if (uf.connected(sx * c + sy, ex * c + ey))
		{
			if (board[sx][sy] == '0')
			{
				cout << "binary" << endl;
			}
			else
			{
				cout << "decimal" << endl;
			}
		}
		else
		{
			cout << "neither" << endl;
		}

	}

	return 0;
}