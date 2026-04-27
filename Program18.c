#include <stdio.h>
#include <stdlib.h>

int isPrime(int x){
    for(int i=2;i*i<=x;i++)

    if(x%i==0)
     return 0;

      return 1;
    }
int* waiter(int n,int* a,int q,int* rc){

    int *res=malloc(n*sizeof(int)),ri=0;
    int p[10000],pc=0,x=2;

    while(pc<q){
        if(isPrime(x)) p[pc++]=x;
        x++;
    }

    int *A=malloc(n*sizeof(int)),sa=n;


    for(int i=0;i<n;i++) 
    A[i]=a[i];
    for(int i=0;i<q;i++){   
           int *B=malloc(n*sizeof(int)),sb=0;
        int *na=malloc(n*sizeof(int)),sna=0;
        while(sa){ 
                   int v=A[--sa];
            if(v%p[i]==0) B[sb++]=v;
            else na[sna++]=v;    
           }
        while(sb) res[ri++]=B[--sb];
        free(A);
         free(B); 
         A=na; 
         sa=sna;}
    while(sa) res[ri++]=A[--sa];
    free(A);  
    *rc=ri;   
    return res;
}
