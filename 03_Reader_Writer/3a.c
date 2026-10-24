#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

char headline[]="Breaking News"; int views=100;
pthread_rwlock_t lock=PTHREAD_RWLOCK_INITIALIZER;

void *reader(void *arg){
    int id=*(int*)arg;
    for(int i=0;i<3;i++){
        pthread_rwlock_rdlock(&lock);
        printf("Reader %d: %s | views=%d\n",id,headline,views);
        pthread_rwlock_unlock(&lock); usleep(100000);
    } return NULL;
}
void *writer(void *arg){
    for(int i=0;i<2;i++){
        pthread_rwlock_wrlock(&lock); views+=10;
        printf("Writer: article updated | views=%d\n",views);
        pthread_rwlock_unlock(&lock); usleep(150000);
    } return NULL;
}
int main(){
    pthread_t r1,r2,w; int a=1,b=2;
    pthread_create(&r1,0,reader,&a); pthread_create(&r2,0,reader,&b);
    pthread_create(&w,0,writer,0);
    pthread_join(r1,0); pthread_join(r2,0); pthread_join(w,0); return 0;
}
