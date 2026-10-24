#include <stdio.h>
#include <string.h>
int main(){
    int users,count[10],found=0; char names[10][30],files[10][20][50];
    char user[30],search[50];
    printf("Enter number of users (1-10): "); scanf("%d",&users);
    if(users<1||users>10){printf("Invalid number of users\n");return 0;}
    for(int i=0;i<users;i++){
        printf("Enter username %d: ",i+1); scanf("%29s",names[i]);
        printf("Number of files for %s (0-20): ",names[i]); scanf("%d",&count[i]);
        if(count[i]<0||count[i]>20){printf("Invalid file count\n");return 0;}
        for(int j=0;j<count[i];j++){
            printf("Enter filename for %s: ",names[i]); scanf("%49s",files[i][j]);
        }
    }
    printf("Two-Level Directory:\n");
    for(int i=0;i<users;i++){
        printf("%s/:",names[i]);
        for(int j=0;j<count[i];j++) printf(" %s",files[i][j]);
        printf("\n");
    }
    printf("Enter username to search: "); scanf("%29s",user);
    printf("Enter filename to search: "); scanf("%49s",search);
    for(int i=0;i<users;i++) if(strcmp(names[i],user)==0){
        for(int j=0;j<count[i];j++) if(strcmp(files[i][j],search)==0){found=1;break;}
        break;
    }
    if(found) printf("File found in user directory.\n");
    else printf("File not found for the specified user.\n");
    return 0;
}
