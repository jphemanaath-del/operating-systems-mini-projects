#include <stdio.h>
#include <string.h>
int main(){
    int n,found=0; char files[50][50],search[50];
    printf("Enter number of files (1-50): "); scanf("%d",&n);
    if(n<1||n>50){printf("Invalid number of files\n");return 0;}
    for(int i=0;i<n;i++){
        printf("Enter filename %d: ",i+1); scanf("%49s",files[i]);
    }
    printf("Single-Level Directory:\n");
    for(int i=0;i<n;i++) printf("%s\n",files[i]);
    printf("Enter filename to search: "); scanf("%49s",search);
    for(int i=0;i<n;i++) if(strcmp(files[i],search)==0){found=1;break;}
    if(found) printf("File found in the directory.\n");
    else printf("File not found.\n");
    return 0;
}
