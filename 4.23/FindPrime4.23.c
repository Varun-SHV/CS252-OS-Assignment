#include<stdio.h>
#include<pthread.h>

#define MAX 1000


int prime_arr[MAX];
int N;
void *print(){
    int i;
     for(i=0;i<N;i++){
        if(prime_arr[i]==1){
            printf("%d ",i+1);
    
}}}
void *printprime()
{
  int  j,flag;
  int i;
  for(i=2;i<=N;i++){
     flag=0;
     for(j=2;j<i;j++)
       {
        if(i%j==0)
          {
           flag=1;
           break;
          }
       }

     if(flag==0)
     {
       prime_arr[i-1]=1;
     }
  }
}
void main(){
    int i,c;
    pthread_t thd;
    pthread_t thd2;
    printf("Enter the limit: ");
    scanf("%d",&N);
    c=pthread_create(&thd,NULL,&printprime,NULL);
    pthread_join(thd,NULL);
    c=pthread_create(&thd2,NULL,&print,NULL);
    pthread_join(thd,NULL);
    
    
}
