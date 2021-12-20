#include <iostream>
using namespace std;

/*数字排列问题 */

const int N = 10;

int n;
int path[N];
bool vis[N];

void dfs(int x)
{
    if (x == n)
    {
        for (int i = 0; i < n; i++)
            printf("%d ", path[i]);
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            path[x] = i;
            vis[i] = true;
            dfs(x + 1);
            vis[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    dfs(0);
    return 0;
}
