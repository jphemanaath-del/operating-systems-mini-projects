#include <stdio.h>
int main(){
    int n,b[20],p[20],id[20],w[20]={0},t;
    printf("Enter number of ICU tasks: "); scanf("%d",&n);
    if(n<1||n>20){printf("Invalid number of tasks\n");return 0;}
    printf("Enter burst time and priority (smaller number = higher priority):\n");
    for(int i=0;i<n;i++){id[i]=i+1;scanf("%d%d",&b[i],&p[i]);}
    for(int i=0;i<n-1;i++) for(int j=i+1;j<n;j++) if(p[i]>p[j]){
        t=p[i];p[i]=p[j];p[j]=t;
        t=b[i];b[i]=b[j];b[j]=t;
        t=id[i];id[i]=id[j];id[j]=t;
    }
    for(int i=1;i<n;i++) w[i]=w[i-1]+b[i-1];
    printf("Priority Order: "); for(int i=0;i<n;i++) printf("P%d ",id[i]);
    printf("\nWaiting Times: "); for(int i=0;i<n;i++) printf("%d ",w[i]);
    return 0;
}
