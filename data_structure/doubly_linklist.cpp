#include <iostream>
using namespace std;

const int N = 100010;

int v[N], l[N], r[N], idx;

//在节点a的右边插入一个数x
void my_insert(int a, int x)
{
    v[idx] = x;
    l[idx] = a, r[idx] = r[a];
    l[r[a]] = idx, r[a] = idx++;
}

//删除一个节点
void my_remove(int a)
{
    l[r[a]] = l[a];
    r[l[a]] = r[a];
}

int main()
{
    // 0是左端点，1是右端点
    r[0] = 1, l[1] = 0;
    idx = 2;
}