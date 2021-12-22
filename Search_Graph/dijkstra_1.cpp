#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 510;
int n, m;
int g[N][N];   //存图
int dist[N];   //存各点到起点的最短路径
bool vis[N];   //标记已经是最近的点

int dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        }
        vis[t] = true;
        for (int j = 1; j <= n; j++)
        {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    if (dist[n] == 0x3f3f3f3f)
        return -1;  //说明不存在 1号点到 n号点的通路
    return dist[n]; //返回 1号点到 n号点的最短距离
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof(g));
    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c); //从重边中选取最短边
    }
    printf("%d\n", dijkstra());
    return 0;
}