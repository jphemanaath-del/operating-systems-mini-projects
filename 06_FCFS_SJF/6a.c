#include <stdio.h>
int main(){
    int n,b[20],w[20]={0};
    printf("Enter number of satellite tasks: "); scanf("%d",&n);
    printf("Enter processing times: ");
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    for(int i=1;i<n;i++) w[i]=w[i-1]+b[i-1];
    printf("FCFS Order: ");
    for(int i=0;i<n;i++) printf("T%d ",i+1);
    printf("\nWaiting Times: ");
    for(int i=0;i<n;i++) printf("%d ",w[i]);
    return 0;
}
