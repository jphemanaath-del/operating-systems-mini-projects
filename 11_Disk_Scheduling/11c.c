#include <stdio.h>
#include <stdlib.h>
void sort(int a[],int n){for(int i=0;i<n-1;i++)for(int j=i+1;j<n;j++)if(a[i]>a[j]){int t=a[i];a[i]=a[j];a[j]=t;}}
int main(){
    int n,a[50],h,start,dir,size,total=0;
    printf("Enter request count: ");scanf("%d",&n);
    if(n<1||n>50){printf("Invalid request count\n");return 0;}
    printf("Enter track requests: ");for(int i=0;i<n;i++)scanf("%d",&a[i]);
    printf("Enter head position: ");scanf("%d",&h); start=h;
    printf("Enter direction (1=right,0=left): ");scanf("%d",&dir);
    printf("Enter disk size (number of tracks): ");scanf("%d",&size);
    if(size<1||h<0||h>=size){printf("Invalid disk size or head position\n");return 0;}
    sort(a,n); printf("SCAN: %d ",h);
    if(dir){
        for(int i=0;i<n;i++)if(a[i]>=start){total+=abs(h-a[i]);h=a[i];printf("%d ",h);}
        total+=abs(h-(size-1));h=size-1;printf("%d ",h);
        for(int i=n-1;i>=0;i--)if(a[i]<start){total+=abs(h-a[i]);h=a[i];printf("%d ",h);}
    }else{
        for(int i=n-1;i>=0;i--)if(a[i]<=start){total+=abs(h-a[i]);h=a[i];printf("%d ",h);}
        total+=h;h=0;printf("0 ");
        for(int i=0;i<n;i++)if(a[i]>start){total+=abs(h-a[i]);h=a[i];printf("%d ",h);}
    }
    printf("\nTotal head movement: %d\n",total);return 0;
}
