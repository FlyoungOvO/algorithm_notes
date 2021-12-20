#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int N = 1000010;
int h[N], hp[N], ph[N], cnt;

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u)
{
    int t = u;
    if (2 * u <= cnt && h[2 * u] < h[u])
        t = 2 * u;
    if (2 * u + 1 <= cnt && h[2 * u + 1] < h[u])
        t = 2 * u + 1;
    if (u != t)
    {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && h[u / 2] > h[u])
    {
        heap_swap(u, u / 2);
        u /= 2;
    }
}

int main()
{
    int n,m=0;
    cin>>n;
}