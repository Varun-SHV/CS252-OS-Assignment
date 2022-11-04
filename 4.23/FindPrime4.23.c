/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>
#include<pthread.h>

#define MAX 1000


int prime_arr[MAX];
int N;

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
    printf("Enter the limit: ");
    scanf("%d",&N);
    c=pthread_create(&thd,NULL,&printprime,NULL);
    pthread_join(thd,NULL);
    for(i=0;i<N;i++){
        if(prime_arr[i]==1){
            printf("%d ",i+1);
        }
    }
    
}
