#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,a[50],v[50]={0},h,total=0,min,pos,d;
    printf("Enter request count: ");scanf("%d",&n);
    printf("Enter track requests: ");for(int i=0;i<n;i++)scanf("%d",&a[i]);
    printf("Enter head position: ");scanf("%d",&h);
    printf("SSTF: %d ",h);
    for(int k=0;k<n;k++){
        min=999999;pos=-1;
        for(int i=0;i<n;i++)if(!v[i]&&(d=abs(h-a[i]))<min){min=d;pos=i;}
        v[pos]=1;total+=min;h=a[pos];printf("%d ",h);
    }
    printf("\nTotal head movement: %d\n",total);return 0;
}
