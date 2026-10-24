#include <stdio.h>
int main(){
    int n,b[20],id[20],w[20]={0},t;
    printf("Enter number of satellite tasks: "); scanf("%d",&n);
    printf("Enter processing times: ");
    for(int i=0;i<n;i++){scanf("%d",&b[i]);id[i]=i+1;}
    for(int i=0;i<n-1;i++) for(int j=i+1;j<n;j++)
        if(b[i]>b[j]){
            t=b[i];b[i]=b[j];b[j]=t;
            t=id[i];id[i]=id[j];id[j]=t;
        }
    for(int i=1;i<n;i++) w[i]=w[i-1]+b[i-1];
    printf("SJF Order: ");
    for(int i=0;i<n;i++) printf("T%d ",id[i]);
    printf("\nWaiting Times: ");
    for(int i=0;i<n;i++) printf("%d ",w[i]);
    return 0;
}
