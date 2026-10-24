#include <stdio.h>
#include <stdlib.h>
void sort(int a[],int n){for(int i=0;i<n-1;i++)for(int j=i+1;j<n;j++)if(a[i]>a[j]){int t=a[i];a[i]=a[j];a[j]=t;}}
int main(){
    int n,a[50],h,size,total=0;
    printf("Enter request count: ");scanf("%d",&n);
    printf("Enter track requests: ");for(int i=0;i<n;i++)scanf("%d",&a[i]);
    printf("Enter head position: ");scanf("%d",&h);
    printf("Enter disk size: ");scanf("%d",&size);sort(a,n);
    printf("C-SCAN: %d ",h);
    for(int i=0;i<n;i++)if(a[i]>=h){total+=abs(h-a[i]);h=a[i];printf("%d ",h);}
    total+=abs(h-(size-1));h=size-1;printf("%d ",h);
    total+=size-1;h=0;printf("0 ");
    for(int i=0;i<n;i++)if(a[i]<h+size){if(a[i]<size){total+=abs(h-a[i]);h=a[i];printf("%d ",h);}}
    printf("\nTotal head movement: %d\n",total);return 0;
}
