#include<iostream>
using namespace std;

int tmp[10000010];

void merge_sort(int a[],int l,int r)
{
    if(l>=r)
        return;
    int mid = l+(r-l)/2;
    merge_sort(a,l,mid);
    merge_sort(a,mid+1,r);

    int k=0,i=l,j=mid+1;
    while(i<=mid && j<=r){
        if(a[i]<=a[j])
            tmp[k++]=a[i++];
        else
            tmp[k++]=a[j++];
    }
    while(i<=mid)
        tmp[k++]=a[i++];
    while(j<=r)
        tmp[k++]=a[j++];
    for(i=l,j=0;i<=r;i++,j++)
        a[i]=tmp[j];
}