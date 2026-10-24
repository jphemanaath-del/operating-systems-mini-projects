#include <stdio.h>
int main(){
    int n,b[20],p[20],q,t,done=0,minp;
    printf("Enter number of ICU tasks: "); scanf("%d",&n);
    printf("Enter burst time and priority:\n");
    for(int i=0;i<n;i++) scanf("%d%d",&b[i],&p[i]);
    printf("Enter time quantum: "); scanf("%d",&q);
    printf("Execution: ");
    while(done<n){
        minp=9999;
        for(int i=0;i<n;i++) if(b[i]>0 && p[i]<minp) minp=p[i];
        for(int i=0;i<n;i++) if(b[i]>0 && p[i]==minp){
            t=b[i]>q?q:b[i]; b[i]-=t; printf("P%d(%d) ",i+1,t);
        }
        done=0; for(int i=0;i<n;i++) if(b[i]==0) done++;
    }
    return 0;
}
