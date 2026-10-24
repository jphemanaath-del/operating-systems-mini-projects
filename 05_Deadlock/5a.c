#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t fund[2];

void *p1(void *x){
    pthread_mutex_lock(&fund[0]); printf("P1 locked Fund 1\n"); sleep(1);
    printf("P1 waiting for Fund 2\n"); pthread_mutex_lock(&fund[1]); return NULL;
}
void *p2(void *x){
    pthread_mutex_lock(&fund[1]); printf("P2 locked Fund 2\n"); sleep(1);
    printf("P2 waiting for Fund 1\n"); pthread_mutex_lock(&fund[0]); return NULL;
}
int main(){
    pthread_t a,b; pthread_mutex_init(&fund[0],0); pthread_mutex_init(&fund[1],0);
    pthread_create(&a,0,p1,0); pthread_create(&b,0,p2,0);
    pthread_join(a,0); pthread_join(b,0); return 0;
}
