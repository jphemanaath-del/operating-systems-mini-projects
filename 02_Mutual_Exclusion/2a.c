#include <stdio.h>
#include <pthread.h>

int camera[5]={0}; pthread_mutex_t m;
void *book(void *arg){
    int id=*(int*)arg, c;
    pthread_mutex_lock(&m);
    printf("Team %d enter camera (1-4): ",id);
    scanf("%d",&c);
    if(c>=1 && c<=4 && !camera[c]){camera[c]=1;printf("Team %d booked Camera %d\n",id,c);}
    else printf("Camera unavailable\n");
    pthread_mutex_unlock(&m); return NULL;
}
int main(){
    pthread_t t[3]; int id[3]={1,2,3};
    pthread_mutex_init(&m,0);
    for(int i=0;i<3;i++) pthread_create(&t[i],0,book,&id[i]);
    for(int i=0;i<3;i++) pthread_join(t[i],0);
    pthread_mutex_destroy(&m); return 0;
}
