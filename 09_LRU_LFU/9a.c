#include <stdio.h>
int main(){
    int f,n,p[50],m[20],age[20]={0},i,j,k=0,fault=0,hit,min;
    printf("Enter memory frames: ");scanf("%d",&f);
    printf("Enter number of page references: ");scanf("%d",&n);
    printf("Enter page sequence: ");for(i=0;i<n;i++)scanf("%d",&p[i]);
    for(i=0;i<f;i++)m[i]=-1;
    for(i=0;i<n;i++){
        hit=0;
        for(j=0;j<f;j++)if(m[j]==p[i]){hit=1;age[j]=i+1;}
        if(!hit){
            if(k<f)m[k]=p[i],age[k++]=i+1;
            else{min=0;for(j=1;j<f;j++)if(age[j]<age[min])min=j;m[min]=p[i];age[min]=i+1;}
            fault++;printf("Page %d -> Fault\n",p[i]);
        }else printf("Page %d -> Hit\n",p[i]);
    }
    printf("Page Faults: %d\nFinal Frames: ",fault);
    for(i=0;i<f;i++)printf("%d ",m[i]);
    return 0;
}
