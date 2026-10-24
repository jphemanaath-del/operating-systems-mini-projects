#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t fund[2];

void *process(void *arg){
    int id=*(int*)arg;
    pthread_mutex_lock(&fund[0]); pthread_mutex_lock(&fund[1]);
    printf("Loan Process %d granted safely\n",id);
    usleep(100000);
    pthread_mutex_unlock(&fund[1]); pthread_mutex_unlock(&fund[0]);
    return NULL;
}
int main(){
    pthread_t a,b; int x=1,y=2;
    pthread_mutex_init(&fund[0],0); pthread_mutex_init(&fund[1],0);
    pthread_create(&a,0,process,&x); pthread_create(&b,0,process,&y);
    pthread_join(a,0); pthread_join(b,0);
    printf("No circular wait occurred.\n"); return 0;
}
