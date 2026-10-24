#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int camera[5]={0}; sem_t s; pthread_mutex_t m; pthread_cond_t c;
void *book(void *arg){
    int id=*(int*)arg, cam=id;
    sem_wait(&s); pthread_mutex_lock(&m);
    while(camera[cam]) pthread_cond_wait(&c,&m);
    camera[cam]=1; printf("Team %d using Camera %d\n",id,cam);
    pthread_mutex_unlock(&m);
    sleep(1);
    pthread_mutex_lock(&m); camera[cam]=0; pthread_cond_broadcast(&c);
    pthread_mutex_unlock(&m); sem_post(&s); return NULL;
}
int main(){
    pthread_t t[4]; int id[4]={1,2,3,4};
    sem_init(&s,0,2); pthread_mutex_init(&m,0); pthread_cond_init(&c,0);
    for(int i=0;i<4;i++) pthread_create(&t[i],0,book,&id[i]);
    for(int i=0;i<4;i++) pthread_join(t[i],0);
    return 0;
}
