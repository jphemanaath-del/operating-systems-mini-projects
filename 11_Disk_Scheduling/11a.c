#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,a[50],h,total=0;
    printf("Enter request count: ");scanf("%d",&n);
    printf("Enter track requests: ");for(int i=0;i<n;i++)scanf("%d",&a[i]);
    printf("Enter head position: ");scanf("%d",&h);
    printf("FCFS: %d ",h);
    for(int i=0;i<n;i++){total+=abs(h-a[i]);h=a[i];printf("%d ",h);}
    printf("\nTotal head movement: %d\n",total);return 0;
}
