#include <stdio.h>
#include <stdlib.h>
void sort(int a[],int n){for(int i=0;i<n-1;i++)for(int j=i+1;j<n;j++)if(a[i]>a[j]){int t=a[i];a[i]=a[j];a[j]=t;}}
int main(){
    int n,a[50],h,dir,total=0;
    printf("Enter request count: ");scanf("%d",&n);
    printf("Enter track requests: ");for(int i=0;i<n;i++)scanf("%d",&a[i]);
    printf("Enter head position: ");scanf("%d",&h);
    printf("Enter direction (1=right,0=left): ");scanf("%d",&dir);sort(a,n);
    printf("LOOK: %d ",h);
    if(dir){
        for(int i=0;i<n;i++)if(a[i]>=h){total+=abs(h-a[i]);h=a[i];printf("%d ",h);}
        for(int i=n-1;i>=0;i--)if(a[i]<h){total+=abs(h-a[i]);h=a[i];printf("%d ",h);}
    }else{
        for(int i=n-1;i>=0;i--)if(a[i]<=h){total+=abs(h-a[i]);h=a[i];printf("%d ",h);}
        for(int i=0;i<n;i++)if(a[i]>h){total+=abs(h-a[i]);h=a[i];printf("%d ",h);}
    }
    printf("\nTotal head movement: %d\n",total);return 0;
}
