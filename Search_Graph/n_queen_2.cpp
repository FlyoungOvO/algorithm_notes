#include <iostream>
using namespace std;

// n皇后问题第二种搜索方法，事先在分析出每一列放一个皇后

const int N = 20;
int n;
char g[N][N];
bool col[N], dg[N], udg[N];

void dfs(int x)
{
    if (x == n)
    {
        for (int i = 0; i < n; i++)
            puts(g[i]);
        puts("");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!col[i] && !dg[x + i] && !udg[n - x + i])
        {
            g[x][i] = 'Q';
            col[i] = dg[x + i] = udg[n - x + i] = true;
            dfs(x + 1);
            //回溯
            g[x][i] = '.';
            col[i] = dg[x + i] = udg[n - x + i] = false;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';
    dfs(0);
    return 0;
}