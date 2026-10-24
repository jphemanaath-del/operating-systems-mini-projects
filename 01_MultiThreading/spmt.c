#include <stdio.h>
#include <string.h>
#include <pthread.h>
char *words[] = {"hello","thanks","goodbye"};
char *french[] = {"bonjour","merci","au revoir"};
void *translate(void *arg) {
    int i = *(int *)arg;
    printf("%s -> %s\n", words[i], french[i]);
    return NULL;
}
int main() {
    pthread_t t[3];
    int id[3] = {0,1,2};
for(int i=0;i<3;i++)
        pthread_create(&t[i],NULL,translate,&id[i]);
for(int i=0;i<3;i++)
        pthread_join(t[i],NULL);
 return 0;
