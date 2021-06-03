//https://open.kattis.com/problems/10kindsofpeople
#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <queue>

using namespace std;

bool in_board(tuple<int, int> spot, vector<string> board)
{
	int x = get<0>(spot);
	int y = get<1>(spot);

	if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
	{
		return false;
	}
	return true;
}

bool bfs(tuple<int, int> start, tuple<int, int> end, vector<string> board, int terrain)
{
	set<tuple<int, int>> visited;
	priority_queue<tuple<int, int>, vector<tuple<int, int>>> frontier;
	frontier.push(start);
	while (!frontier.empty())
	{
		tuple<int, int> current = frontier.top();
		if (current == end)
		{
			return true;
		}
		visited.insert(current);
		frontier.pop();
		for (tuple<int, int> x : { make_tuple(get<0>(current) - 1, get<1>(current)), make_tuple(get<0>(current) + 1, get<1>(current)),
			make_tuple(get<0>(current), get<1>(current) - 1) , make_tuple(get<0>(current), get<1>(current) + 1) })
		{
			if (in_board(x, board) && (terrain == board[get<0>(x)][get<1>(x)]))
			{
				if (visited.count(x))
				{
					continue;
				}
				else
				{
					frontier.push(x);
				}
			}
		}

	}
	return false;
}

int main()
{
	int r, c;
	cin >> r;
	cin >> c;
	vector<string> board(r);
	for (int i = 0; i < r; i++)
	{
		cin >> board[i];
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

		if (board[sx][sy] != board[ex][ey])
		{
			cout << "neither" << endl;
			continue;
		}

		int terrain = board[sx][sy];

		tuple<int, int> start = make_tuple(sx, sy);
		tuple<int, int> end = make_tuple(ex, ey);
		
		if (bfs(start, end, board, terrain))
		{
			if (terrain == '0')
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