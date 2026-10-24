#include <stdio.h>
int main(){
    int b[20],p[20],nb,np,i,j,best;
    printf("Enter number of cloud blocks: ");scanf("%d",&nb);
    printf("Enter block sizes: ");for(i=0;i<nb;i++)scanf("%d",&b[i]);
    printf("Enter number of tasks: ");scanf("%d",&np);
    printf("Enter task sizes: ");for(i=0;i<np;i++)scanf("%d",&p[i]);
    for(i=0;i<np;i++){
        best=-1;
        for(j=0;j<nb;j++)if(b[j]>=p[i]&&(best==-1||b[j]<b[best]))best=j;
        if(best!=-1){b[best]-=p[i];printf("Task %d -> Block %d\n",i+1,best+1);}
        else printf("Task %d -> Not allocated\n",i+1);
    }
    return 0;
}
