#include <iostream>
#include <set>
#include <vector>
using namespace std;

// fast integer in
void fastscan(int& ret) {
    ret = 0;
    char r;
    bool start = false, neg = false;
    while (true) {
        r = getchar();
        if ((r - '0' < 0 || r - '0' > 9) && r != '-' && !start) {
            continue;
        }
        if ((r - '0' < 0 || r - '0' > 9) && r != '-' && start) {
            break;
        }
        if (start)ret *= 10;
        start = true;
        if (r == '-')neg = true;
        else ret += r - '0';
    }
    if (neg) ret *= -1;
}

int main()
{
    // use "\n" instead of cout << endl
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    fastscan(n);
    fastscan(e);

    vector<vector<int>> scoreboard;
    for (int i = 0; i <= n; i++)
    {
        scoreboard.push_back({ i, 0, 0 });
    }

    auto cmp = [](vector<int> left, vector<int> right)
    {
        if (left[1] < right[1])
        {
            return true;
        }
        if (left[1] == right[1])
        {
            if (left[2] > right[2])
            {
                return true;
            }
            if (left[2] == right[2])
            {
                return left[0] > right[0];
            }
        }
        return false;
    };

    set<vector<int>, decltype(cmp)> better_teams(cmp);

    int p, t;
    set<vector<int>, decltype(cmp)>::iterator it;
    for (int i = 0; i < e; i++)
    {
        fastscan(p);
        fastscan(t);

        if (p == 1)
        {
            scoreboard[1][1] += 1;
            scoreboard[1][2] += t;
            it = better_teams.begin();
            while ((better_teams.size() > 0) && (cmp(*it, scoreboard[1])))
            {
                it = better_teams.erase(it);
            }
        }
        else
        {
            vector<int> old_score = scoreboard[p];
            vector<int> new_score = { p, old_score[1] + 1, old_score[2] + t };
            if (cmp(scoreboard[1], new_score))
            {
                if (better_teams.count(old_score))
                {
                    it = better_teams.find(old_score);
                    better_teams.erase(it);
                    better_teams.insert(new_score);
                }
                else
                {
                    better_teams.insert(new_score);
                }
            }
            scoreboard[p] = new_score;
        }
        cout << better_teams.size() + 1 << "\n";
    }

    return 0;
}