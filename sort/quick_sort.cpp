#include<iostream>
using namespace std;

void quick_sort(int a[],int l,int r)
{
    if(l>=r) return;            //left > right 时直接返回

    int i=l,j=r+1,t=a[(l+r)/2];  //j = r + 1,对边界值的处理
    while(i<j){
        do i++;while(a[i]<t);   //找到大于 t 的 a[i],找到后跳出该层循环
        do j--;while(a[j]>t);   //找到小于 t 的 a[j],找到后跳出该层循环
        if(i<j)
            swap(a[i],a[j]);    //交换a[i],a[j]
    }
    quick_sort(a,l,j);          //对左边递归
    quick_sort(a,j+1,r);        //对右边递归
}

int main()
{
    int a[]={1,3,2,5,4};
    quick_sort(a,0,4);
    for(int i=0;i<5;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
