#include <iostream>
#include <cstring>
using namespace std;

//开放寻址法

const int N = 200003, null = 0x3f3f3f3f; // N一般取区间长度的2~3倍，并且为质数

int h[N];

int find(int x)
{
    int t = (x % N + N) % N;          //保证余数为正数
    while (h[t] != null && h[t] != x) //如果当前位置不为空且该位置不是自己，则往后移一位继续找
    {
        t++;
        if (t == N)
            t = 0;
    }
    return t;
}

int main()
{
    memset(h, 0x3f, sizeof(h));

    int n;
    cin >> n;
    while (n--)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if (*op == 'I')
            h[find(x)] = x;
        else
        {
            if (h[find(x)] == null)
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }
    return 0;
}