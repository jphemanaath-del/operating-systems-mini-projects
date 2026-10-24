#include <stdio.h>
int main(){
    int n,r,i,j,done=0;
    printf("Enter processes and resources: "); scanf("%d%d",&n,&r);
    int av[r],al[n][r],mx[n][r],need[n][r],fin[n],seq[n];
    printf("Enter Available: "); for(j=0;j<r;j++) scanf("%d",&av[j]);
    printf("Enter Allocation matrix:\n");
    for(i=0;i<n;i++) for(j=0;j<r;j++) scanf("%d",&al[i][j]);
    printf("Enter Max matrix:\n");
    for(i=0;i<n;i++) for(j=0;j<r;j++){scanf("%d",&mx[i][j]);need[i][j]=mx[i][j]-al[i][j];fin[i]=0;}
    while(done<n){
        int found=0;
        for(i=0;i<n;i++) if(!fin[i]){
            for(j=0;j<r;j++) if(need[i][j]>av[j]) break;
            if(j==r){
                for(j=0;j<r;j++) av[j]+=al[i][j];
                fin[i]=1; seq[done++]=i; found=1;
            }
        }
        if(!found) break;
    }
    if(done==n){
        printf("SAFE state\nSafe sequence: ");
        for(i=0;i<n;i++) printf("P%d ",seq[i]);
    }else printf("UNSAFE state\n");
    return 0;
}
