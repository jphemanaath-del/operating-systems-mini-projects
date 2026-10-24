#include <stdio.h>
int main(){
    int n,b[20],q,done=0,t;
    printf("Enter number of ICU tasks: "); scanf("%d",&n);
    printf("Enter burst times: "); for(int i=0;i<n;i++) scanf("%d",&b[i]);
    printf("Enter time quantum: "); scanf("%d",&q);
    printf("Execution: ");
    while(done<n){
        done=0;
        for(int i=0;i<n;i++) if(b[i]>0){
            t=b[i]>q?q:b[i]; b[i]-=t;
            printf("P%d(%d) ",i+1,t);
        }
        for(int i=0;i<n;i++) if(b[i]==0) done++;
    }
    return 0;
}
