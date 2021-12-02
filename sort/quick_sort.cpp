#include<iostream>
using namespace std;
int n,a[1000005];
void quick_sort(int left,int right)
{
    int mid = left + (right + left)>>1;
    int i=left,j=right;
    int t=a[mid];
    do{
        while(a[i]<t) i++;
        while(a[j]>t) j--;
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(left < j)
        quick_sort(left,j);
    if(i<right)
        quick_sort(i,right);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quick_sort(0,n-1);
    return 0;
}