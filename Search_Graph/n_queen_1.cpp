#include <iostream>
using namespace std;

/*N-皇后问题*/
//第一种搜索方法，对所有位置进行遍历

const int N = 10;
int n;
bool row[N], col[N], dg[N * 2], udg[2 * N]; // dg表示对角线，udg表示斜对角线
char g[N][N];

void dfs(int x, int y, int s) // s表示已经摆好的皇后的数目
{
    if (s > n)
        return; //根据对题意的分析，可提前知道每一列最多1个皇后，故s不可能大于n
    if (y == n)
    { //列数越界后回到第一列，行数+1
        y = 0;
        x++;
    }
    if (x == n)
    {
        if (s == n)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    cout << g[i][j];
                cout << endl;
            }
            cout << endl;
        }
        return;
    }

    g[x][y] = '.';
    dfs(x, y + 1, s);
    if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n])
    {
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
        g[x][y] = 'Q';
        dfs(x, y + 1, s + 1);
        g[x][y] = '.';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
    }
}

int main()
{
    cin >> n;
    dfs(0, 0, 0);
    return 0;
}