#include <stdio.h>
int main(){
    int n,f,disk[100]={0},size,start,k;
    printf("Enter total disk blocks: ");scanf("%d",&n);
    printf("Enter number of files: ");scanf("%d",&f);
    for(int i=1;i<=f;i++){
        printf("Enter size of File %d: ",i);scanf("%d",&size);start=-1;
        for(int j=0;j<=n-size;j++){
            for(k=j;k<j+size;k++)if(disk[k])break;
            if(k==j+size){start=j;break;}
        }
        if(start!=-1){
            for(k=start;k<start+size;k++)disk[k]=i;
            printf("File %d -> Blocks %d to %d\n",i,start,start+size-1);
        }else printf("File %d -> Not allocated\n",i);
    }
    return 0;
}
