#include<iostream>
using namespace std;
const int N = 100010;

// head 表示头结点的下标
// e[i] 表示节点i的值
// ne[i] 表示节点i的next指针是多少
// idx 存储当前已经用到了哪个点（指操作数）

int head,v[N],nv[N],idx;

void init()
{
    head = -1;
    idx = 1;
}
//将x插入到头结点
void add_to_head(int x)
{
    v[idx]=x;
    nv[idx]=head;
    head=idx++;
}
//将x插入到下标是k的结点的后面
void add(int k,int x)
{
    v[idx] = x;
    nv[idx] = nv[k];
    nv[k] = idx++;
}
//删除下标为k的点后面的一个点
void remove(int k)
{
    nv[k]=nv[nv[k]];
}

