#include <iostream>
using namespace std;

const int N = 100010;

int son[N][26], cnt[N], idx;
char str[N];

//向trie树插入一个字符串
void my_insert(char *str)
{
    int p = 0; //从根节点开始遍历
    for (int i = 0; str[i] != '\0'; i++)
    {
        int tmp = str[i] - 'a';
        //没有该子节点就新建一个子节点
        if (!son[p][tmp])
        {
            son[p][tmp] = ++idx;
        }
        //走到p的子节点
        p = son[p][tmp];
    }
    cnt[p]++; //给对应编号的最后一个节点打上标记，记作录入了一个完整字符串
}

int my_search(char *str)
{
    int p = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        int tmp = str[i] - 'a';
        if (son[p][tmp] == 0)
        {
            return 0;
        }
        p = son[p][tmp];
    }
    return cnt[p];
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        char op[2];
        scanf("%s%s", op, str);
        if (op[0] == 'I')
            my_insert(str);
        else
            printf("%d\n", my_search(str));
    }
    return 0;
}