#include <stdio.h>
int main(){
    int n,f,disk[100]={0},size,index,b[50],ok;
    printf("Enter total disk blocks: ");scanf("%d",&n);
    printf("Enter number of files: ");scanf("%d",&f);
    for(int i=1;i<=f;i++){
        printf("Enter size of File %d: ",i);scanf("%d",&size);
        printf("Enter index block: ");scanf("%d",&index);
        if(index<0||index>=n||disk[index]){printf("Invalid index block\n");continue;}
        ok=1; printf("Enter %d data blocks: ",size);
        for(int j=0;j<size;j++){scanf("%d",&b[j]);if(b[j]<0||b[j]>=n||disk[b[j]]||b[j]==index)ok=0;}
        if(ok){
            disk[index]=i;for(int j=0;j<size;j++)disk[b[j]]=i;
            printf("File %d -> Index %d -> ",i,index);
            for(int j=0;j<size;j++)printf("%d ",b[j]);printf("\n");
        }else printf("File %d -> Invalid or occupied data block\n",i);
    }
    return 0;
}
