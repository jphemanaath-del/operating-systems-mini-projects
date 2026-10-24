#include <stdio.h>
#include <pthread.h>

pthread_mutex_t e[20]; int n;
void *researcher(void *arg){
    int i=*(int*)arg;
    pthread_mutex_lock(&e[i]);
    pthread_mutex_lock(&e[(i+1)%n]);
    printf("Researcher %d -> Equipment %d & %d\n",i+1,i+1,(i+1)%n+1);
    pthread_mutex_unlock(&e[(i+1)%n]);
    pthread_mutex_unlock(&e[i]); return NULL;
}
int main(){
    pthread_t t[20]; int id[20];
    printf("Enter number of researchers: "); scanf("%d",&n);
    for(int i=0;i<n;i++) pthread_mutex_init(&e[i],0);
    for(int i=0;i<n;i++){id[i]=i;pthread_create(&t[i],0,researcher,&id[i]);}
    for(int i=0;i<n;i++) pthread_join(t[i],0);
    return 0;
}
